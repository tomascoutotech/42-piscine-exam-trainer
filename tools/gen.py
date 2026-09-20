#!/usr/bin/env python3
"""Gera os casos de teste e os dados do site a partir do material do repositorio.

Regra que manda em tudo: nenhum valor esperado e escrito a mao. Os comandos sao
extraidos dos enunciados (as linhas que comecam por "$>") e o output esperado e
o que a solucao de referencia produz quando corre esse comando. Depois compara-se
uma coisa com a outra; uma diferenca e um aviso que tem de ser explicado em
tools/diferencas.txt, nunca silenciada.

    python3 tools/gen.py           gera tests/cases/ e docs/data.js
    python3 tools/gen.py --check   so verifica, nao escreve nada
"""
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
POOL = os.path.join(RAIZ, "pool")
SOLS = os.path.join(RAIZ, "solucoes")
MAINS = os.path.join(RAIZ, "tests", "mains")
INCLUDE = os.path.join(RAIZ, "tests", "include")
CASES = os.path.join(RAIZ, "tests", "cases")
CC = ["cc", "-Wall", "-Wextra", "-Werror"]


def ler(p):
    with open(p, encoding="utf-8") as fh:
        return fh.read()


def exercicios():
    """[(nivel, nome, texto_do_enunciado)] ordenado por nivel e nome."""
    out = []
    for lvl in range(6):
        d = os.path.join(POOL, "level%d" % lvl)
        if not os.path.isdir(d):
            continue
        for nome in sorted(os.listdir(d)):
            texto = ler(os.path.join(d, nome, "subject.en.txt"))
            # alguns exercicios trazem exemplos num ficheiro a parte: contam
            # como casos, mas nao fazem parte do texto do enunciado
            extra = os.path.join(d, nome, "examples.txt")
            exemplos = ler(extra) if os.path.exists(extra) else ""
            out.append((lvl, nome, texto, exemplos))
    return out


def cabecalho(texto):
    """Assignment name / Expected files / Allowed functions do topo do enunciado."""
    campos = {}
    for linha in texto.splitlines():
        if linha.startswith("---"):
            break
        m = re.match(r"([A-Za-z ]+?)\s*:\s*(.*)$", linha)
        if m:
            campos[m.group(1).strip().lower()] = m.group(2).strip()
    permitidas = campos.get("allowed functions", "")
    if permitidas in ("-", ""):
        permitidas = []
    else:
        permitidas = [f.strip() for f in permitidas.split(",") if f.strip()]
    return campos.get("expected files", ""), permitidas


def transcricoes(texto, nome):
    """Pares (comando, output_mostrado) tirados das linhas '$>' do enunciado."""
    pares = []
    linhas = texto.splitlines()
    i = 0
    while i < len(linhas):
        m = re.match(r"\$>\s*(.*)$", linhas[i])
        i += 1
        if not m:
            continue
        cmd = m.group(1).strip()
        # um comando pode continuar na linha seguinte (o brainfuck tem uma
        # newline dentro das aspas): continua enquanto as aspas nao fecharem
        while cmd.count('"') % 2 == 1 and i < len(linhas):
            cmd += "\n" + linhas[i]
            i += 1
        saida = []
        while i < len(linhas) and not linhas[i].startswith("$>"):
            saida.append(linhas[i])
            i += 1
        if not cmd:
            continue
        # o nome do binario nos exemplos nem sempre e o nome do exercicio
        # (o check_mate chama-se "chessmate" la dentro) e nem sempre leva ./
        if cmd.startswith(nome + " ") or cmd == nome:
            cmd = "./" + cmd
        if not cmd.startswith("./"):
            continue            # linhas como "cat test_main.c" ou "gcc ..."
        partes = cmd.split(None, 1)
        cmd = "./" + nome + (" " + partes[1] if len(partes) > 1 else "")
        pares.append((cmd, "\n".join(saida).rstrip("\n")))
    return pares


def headers_precisos(pasta):
    """Copia list.h / ft_list.h para a pasta se algum .c os incluir e faltarem."""
    for h in ("list.h", "ft_list.h"):
        if os.path.exists(os.path.join(pasta, h)):
            continue
        usa = any('#include "%s"' % h in ler(os.path.join(pasta, f))
                  for f in os.listdir(pasta) if f.endswith(".c"))
        if usa:
            shutil.copy(os.path.join(INCLUDE, h), pasta)


def compila_referencia(nome, destino):
    """Copia a solucao (+ main de teste se for funcao) e compila. Devolve erro ou None."""
    for f in os.listdir(os.path.join(SOLS, nome)):
        shutil.copy(os.path.join(SOLS, nome, f), destino)
    main = os.path.join(MAINS, nome + ".c")
    if os.path.exists(main):
        shutil.copy(main, os.path.join(destino, "main.c"))
    headers_precisos(destino)
    fontes = sorted(f for f in os.listdir(destino) if f.endswith(".c"))
    r = subprocess.run(CC + fontes + ["-o", nome], cwd=destino,
                       capture_output=True, text=True)
    return None if r.returncode == 0 else (r.stderr.strip() or "erro a compilar")


def corre(cmd, pasta):
    """O output tal e qual, ate ao ultimo byte.

    Nada de rstrip aqui: a newline a mais no fim e o erro numero um deste
    exame e o only_a tem de escrever 'a' sem newline nenhuma. Se a captura
    cortar o fim, o corrector deixa passar exactamente o que devia chumbar.
    surrogateescape porque o print_memory escreve bytes que nao sao UTF-8.
    """
    r = subprocess.run(cmd, shell=True, cwd=pasta, capture_output=True,
                       encoding="utf-8", errors="surrogateescape", timeout=10)
    return r.stdout


def limpa(s):
    """Versao segura para JSON (o site nao consegue mostrar bytes invalidos)."""
    return s.encode("utf-8", "replace").decode("utf-8")


def main():
    so_verificar = "--check" in sys.argv
    lista = exercicios()
    dados = []
    avisos = []
    falhas = []

    if not so_verificar and os.path.isdir(CASES):
        shutil.rmtree(CASES)

    for lvl, nome, texto, exemplos in lista:
        exp_files, permitidas = cabecalho(texto)
        e_funcao = os.path.exists(os.path.join(MAINS, nome + ".c"))
        tmp = tempfile.mkdtemp(prefix="gen_" + nome + "_")
        try:
            erro = compila_referencia(nome, tmp)
            if erro:
                falhas.append("%s: NAO COMPILA\n%s" % (nome, erro))
                continue

            if e_funcao:
                # o enunciado de uma funcao mostra exemplos com o main dele,
                # nao com o nosso: os casos vem do main de teste
                comandos = [("./" + nome, None)]
            else:
                comandos = transcricoes(texto, nome)
                vistos = {c for c, _ in comandos}
                for c, o in transcricoes(exemplos, nome):
                    if c not in vistos:
                        comandos.append((c, o))
                        vistos.add(c)
                if not comandos:
                    comandos = [("./" + nome, None)]

            casos = []
            for cmd, mostrado in comandos:
                try:
                    obtido = corre(cmd, tmp)
                except subprocess.TimeoutExpired:
                    falhas.append("%s: '%s' nao acaba (timeout 10s)" % (nome, cmd))
                    continue
                casos.append((cmd, obtido))
                # o enunciado mostra o output como linhas, sem dizer nada sobre
                # a newline final: a comparacao com o texto dele ignora-a. O que
                # fica guardado no .out e que e exacto.
                if mostrado is not None and mostrado != obtido.rstrip("\n"):
                    avisos.append("%s | %s\n  enunciado: %r\n  referencia: %r"
                                  % (nome, cmd, mostrado, obtido))

            if not so_verificar:
                d = os.path.join(CASES, nome)
                os.makedirs(d)
                for i, (cmd, out) in enumerate(casos, 1):
                    with open(os.path.join(d, "%02d.cmd" % i), "w",
                              encoding="utf-8") as fh:
                        fh.write(cmd + "\n")
                    # sem newline acrescentada: o ficheiro e os bytes exactos
                    with open(os.path.join(d, "%02d.out" % i), "w", newline="",
                              encoding="utf-8", errors="surrogateescape") as fh:
                        fh.write(out)

            solucao = {}
            for f in sorted(os.listdir(os.path.join(SOLS, nome))):
                solucao[f] = ler(os.path.join(SOLS, nome, f))
            dados.append({
                "nome": nome, "nivel": lvl, "enunciado": texto,
                "ficheiros": exp_files, "permitidas": permitidas,
                "funcao": e_funcao, "solucao": solucao,
                "main": ler(os.path.join(MAINS, nome + ".c")) if e_funcao else "",
                "casos": [{"cmd": c, "out": limpa(o)} for c, o in casos],
            })
        finally:
            shutil.rmtree(tmp, ignore_errors=True)

    if not so_verificar:
        with open(os.path.join(RAIZ, "docs", "data.js"), "w",
                  encoding="utf-8") as fh:
            fh.write("window.POOL = ")
            json.dump(dados, fh, ensure_ascii=False)
            fh.write(";\n")

    print("exercicios: %d   casos: %d"
          % (len(dados), sum(len(d["casos"]) for d in dados)))
    for f in falhas:
        print("FALHA " + f)
    if avisos:
        print("\n%d diferencas entre o enunciado e a referencia "
              "(tem de estar explicadas em tools/diferencas.txt):" % len(avisos))
        for a in avisos:
            print("  " + a)
    return 1 if falhas else 0


if __name__ == "__main__":
    sys.exit(main())
