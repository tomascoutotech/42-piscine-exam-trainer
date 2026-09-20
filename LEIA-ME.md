# Simulador dos exames da Piscine

Isto é um exame a sério, sem ser o exame. Sorteia um exercício de cada nível a
começar no 0, dá-te quatro horas, e corrige como a Moulinette corrige: compila com
`cc -Wall -Wextra -Werror`, procura funções proibidas com `nm`, e compara o output
byte a byte.

**Versão web, sem instalar nada:** https://tomascoutotech.github.io/42-piscine-exam-trainer/

---

## Começar

```sh
git clone https://github.com/tomascoutotech/42-piscine-exam-trainer
cd 42-piscine-exam-trainer
./exam start final
```

Precisa de Linux, macOS ou WSL. No Windows, abre o WSL — vais precisar dele para a
Piscine toda, mais vale já.

O `./exam start` sorteia um exercício do nível 0, cria `rendu/<nome>/` com o
enunciado lá dentro e arranca o cronómetro. Escreves o código nessa pasta e corres:

```
./exam grade
```

Se passar, sobe de nível e sorteia o seguinte. Se não passar, diz-te exactamente
onde falhou e ficas no mesmo nível — como no exame.

### Os comandos todos

| | |
|---|---|
| `./exam start [exame]` | começa. `exam00` `exam01` `exam02` `exam03` `final` (por omissão) |
| `./exam grade` | corrige o exercício actual |
| `./exam status` | em que nível vais e quanto tempo resta |
| `./exam enunciado` | volta a mostrar o enunciado |
| `./exam solucao` | revela a resolução, só depois de teres tentado corrigir |
| `./exam treino <nome\|0..5>` | um exercício a solo, sem cronómetro, em `treino/` |
| `./exam lista [nível]` | os 73 exercícios da pool |
| `./exam selftest` | corrige as 73 soluções de referência. Tem de dar 73/73 |

Os níveis de cada exame: `exam00` 0–1, `exam01` 0–2, `exam02` 0–3, `exam03` 0–4,
`final` 0–5. Quatro horas por omissão; para duas, `EXAM_TIME=7200 ./exam start`.

## O que a correcção verifica

```
cc -Wall -Wextra -Werror   compila sem um único aviso
nm                         nenhuma função além das permitidas pelo enunciado
diff                       o output igual, byte a byte
```

**A norminette não é corrida.** O exame não a corre. Um `for`, uma declaração a meio
da função, uma função de 40 linhas — passa tudo. Uma newline a mais no fim, não.

Corre sempre com `| cat -e`. O `$` mostra-te onde a linha acaba de verdade, e o erro
número um deste exame é a newline final a mais ou a menos.

A verificação das funções proibidas só olha para os *teus* ficheiros, compilados com
`-fno-builtin`. Sem essa flag o gcc troca o teu `printf("%c", c)` por `putchar` e
depois acusa-te de chamar uma função que nunca escreveste.

## Exercícios que são funções

Cerca de 30 dos 73 são funções, não programas: sozinhas não correm. O simulador
junta-lhes um `main.c` de teste que está em `tests/mains/`.

> **O main nunca se entrega.** O avaliador tem o dele. Se entregares o teu ficam dois
> no mesmo programa e nem chega a linkar: *multiple definition of 'main'*. Entrega só
> os ficheiros que a linha `Expected files` do enunciado pede.

O mesmo vale para o `list.h` e o `ft_list.h`: quando o enunciado diz *"we will use
ours during the evaluation"*, o header é deles. Estão em `tests/include/` e o
simulador põe-nos lá quando são precisos.

## O que está aqui dentro

```
exam                 o simulador
pool/levelN/<nome>/  o enunciado original (subject.en.txt)
solucoes/<nome>/     uma resolução de referência por exercício
tests/cases/<nome>/  os casos de teste: NN.cmd e o NN.out esperado
tests/mains/         um main.c por cada exercício que é função
tests/include/       list.h e ft_list.h, os headers que o avaliador dá
tools/gen.py         regera tests/cases e docs/data.js
docs/                o site e o PDF
```

### Os valores esperados não foram escritos à mão

Nenhum. O `tools/gen.py` tira os comandos dos próprios enunciados (as linhas que
começam por `$>`), corre-os contra a solução de referência e guarda o que sai. Depois
compara isso com o output que o enunciado mostra. Sobram três diferenças, as três
explicadas em [tools/diferencas.txt](tools/diferencas.txt): dois descuidos do
enunciado e um exemplo cortado a meio. Se aparecer uma quarta, partiu-se alguma coisa.

Escrever o valor esperado de cabeça já produziu falsos alarmes suficientes para
justificar a regra.

## O documento

[docs/exame-final-piscine.pdf](docs/exame-final-piscine.pdf) — 111 páginas. Os 70
exercícios dos níveis 0 a 5, cada um com o que o enunciado pede, como pensar nele, o
código, e uma explicação linha a linha desse código.

## Como treinar a sério

1. Abre só o enunciado. Não abras a pasta `solucoes/`.
2. Escreve do zero, a tempo: 15 minutos nos níveis 0–1, 30 nos 2–3, 45 nos 4–5.
3. `./exam grade`.
4. **Só depois** `./exam solucao`. Se a tua passa nos testes e é diferente da minha,
   a tua está certa.

O objectivo não é decorar resoluções. É chegares ao exame e reconheceres o problema.

## O que isto não é

- **A pool não é oficial.** Foi reconstruída a partir de colecções públicas que
  concordam entre si, cruzadas com ficheiros de resultado de exames reais. É boa
  evidência; não é a fonte. A pool varia entre campus e entre anos, e nenhum exame
  usa os 73.
- **As soluções estão à vista no repositório.** O simulador só as mostra depois de
  tentares e o site pergunta primeiro, mas qualquer pessoa abre a pasta `solucoes/`
  no GitHub. A tranca é para ti, não é uma tranca.
- **Copiar no exame é detectado e a 42 pune.** Isto existe para treinares em
  condições de exame e para conferires o teu trabalho depois.
- **O site não compila nada.** O browser não corre C. Mostra o enunciado, os testes e
  a resolução; quem corrige é o `./exam`.

---

Feito por **tomanuel**.
