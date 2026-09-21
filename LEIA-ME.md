# Simulador dos exames da Piscine

Isto é um exame a sério, sem ser o exame. Sorteia um exercício de cada nível a
começar no 0, dá-te quatro horas, e corrige como a Moulinette corrige: compila com
`cc -Wall -Wextra -Werror`, procura funções proibidas com `nm`, e compara o output
byte a byte.

**Versão web, sem instalar nada:** https://tomascoutotech.github.io/42-piscine-exam-trainer/

<img src="docs/exam-cli.svg" alt="Uma sessão real do ./exam: nível 0 sorteado, uma correcção falhada com o diff, e depois a que passa" width="650">

---

## Começar

```sh
git clone https://github.com/tomascoutotech/42-piscine-exam-trainer
cd 42-piscine-exam-trainer
./exam start exam03
```

Precisa de Linux, macOS ou WSL. No Windows também corre sem WSL, no Git Bash —
ver [mais abaixo](#windows-sem-wsl).

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
| `./exam start [exame] [--ate N]` | começa. `exam00` `exam01` `exam02` `exam03` (por omissão) |
| `./exam grade` | corrige o exercício actual |
| `./exam status` | em que nível vais e quanto tempo resta |
| `./exam enunciado` | volta a mostrar o enunciado |
| `./exam solucao` | revela a resolução, só depois de teres tentado corrigir |
| `./exam treino <nome\|0..5>` | um exercício a solo, sem cronómetro, em `treino/` |
| `./exam lista [nível]` | os 73 exercícios da pool |
| `./exam selftest` | corrige as 73 soluções de referência. Tem de dar 73/73 |

A Piscine tem **quatro exames**, e o último, o `exam03`, é o exame final — e é o que
sai por omissão, portanto um `./exam start` seco dá-te esse.

Os quatro sorteiam da **mesma pool de seis níveis** e seguem as mesmas regras. O que
muda entre eles é a altura da Piscine em que acontecem e quanto C já sabes nessa
altura, **não um tecto de nível**. Não encontrei fonte nenhuma para um tecto por
exame, por isso isto não inventa um.

Quatro horas por omissão; para duas, `EXAM_TIME=7200 ./exam start`. Para uma sessão
curta, `./exam start --ate 2` pára no nível 2 — isso é escolha tua, o exame a sério
acaba é quando o tempo acaba.

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

Há duas flags aqui que o exame não usa, as duas para o teu compilador não te chumbar
por algo que o da escola aceitaria: o `-fno-builtin` acima, e o `-std=gnu17` na
compilação. Sem o segundo, um gcc 15 lê o `int (*cmp)()` que o próprio enunciado do
`ft_list_remove_if` manda usar como "não leva argumentos" — regra nova do C23 — e
recusa o código. As flags que decidem a tua nota, `-Wall -Wextra -Werror`, são as do
exame.

## Windows sem WSL

Corre no **Git Bash** (o que vem com o Git para Windows) desde que tenhas um
compilador de C. O mais simples é o MSYS2:

```sh
# instala uma vez, no PowerShell
winget install MSYS2.MSYS2
# e no Git Bash, antes de correres o ./exam
export PATH="$PATH:/c/msys64/ucrt64/bin"
./exam selftest
```

Testado: **passam os 73**, tal como em Linux. O simulador desfaz sozinho dois estragos
que o Windows faz e que nada têm a ver com o teu código — a conversão de `\n` em
`\r\n` à saída dos programas, e a mania do MSYS de transformar um argumento `/` num
caminho tipo `C:/Program Files/Git`.

Houve um exercício em que foi preciso mudar a própria resolução. O `ft_itoa` tem de
conseguir escrever `-2147483648`, cujo positivo não cabe num `int`; o truque habitual
é guardá-lo num `long`, que funciona em Linux e parte no Windows, onde o `long` tem
32 bits. A resolução usa um `unsigned int`: tem 32 bits em qualquer máquina, e trocar
o sinal a um `unsigned` é uma conta definida pela norma em vez de ser transbordo. A
mesma ideia, com menos uma suposição sobre a máquina — e está explicada assim no PDF.

> O WSL continua a ser melhor para treinar: é o mesmo sistema que vais ter à frente
> no exame. O Git Bash serve para não teres desculpa em nenhum computador.

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

## O site

[tomascoutotech.github.io/42-piscine-exam-trainer](https://tomascoutotech.github.io/42-piscine-exam-trainer/)
— sorteia com cronómetro, lista os 73 com pesquisa, e mostra o enunciado, os testes e
a resolução. Não compila nada: o browser não corre C.

<img src="docs/site.png" alt="O simulador web com um exercício sorteado, o enunciado e os casos de teste" width="820">

## O documento

A pool tem 73 exercícios e o documento cobre 70. Os três que **não** têm página lá
dentro são o `moment`, o `biggest_pal` e o `cycle_detector` — os mais raros, que
vieram das colecções públicas. Têm aqui o enunciado e uma resolução testada; o que
não têm é a explicação linha a linha, e tanto o `./exam solucao` como o site to dizem
quando abres um deles.

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
