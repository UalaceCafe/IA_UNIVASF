# Atividade 2 - Algoritmo Genético para minimização de uma função

## Descrição

Esta aplicação implementa na linguagem _C_ um algoritmo genético para a resolução do problema da minimização da função

$$f(x) = x^2 - 3x + 4$$

com $x \in \mathbb{Z}, -10 \le x \le 10$.

As seguintes condições também foram seguidas:

* Os cromossomos são representados por um vetor de bits;
* O tamanho da população é de 4 indivíduos;
* A seleção é feita por torneio;
* A taxa de crossover é de 60% (0.6);
* A probabilidade de mutação é de 1% (0.01).

## Como executar

Com a ferramenta `make`
  * Para compilar e executar automaticamente a aplicação, rode o comando `make` neste diretório raiz;
  * Para apenas compilar o código-fonte, rode o comando `make compile` neste diretório raiz.

Caso não possua a ferramenta `make`, execute o comando
> `gcc -Wall -pedantic -O2 -std=c17 -Werror src/main.c src/utils.c src/population.c src/genetic.c -o bin/main`

Em qualquer um dos casos, o binário será gerado no diretório [`bin`](bin/).

## Metodologia

### Representação de um indivíduo

Um indivíduo é representado com a seguinte estrutura:

```c
typedef struct {
    int8_t value;
    uint8_t chromosome[CHROMOSOME_SIZE];
    double fitness;
} Individual;
```

Onde:
  * `value`: valor do fenótipo do indivíduo. No nosso caso particular, é um valor de $x$;
  * `chromosome`: vetor de bits que representa o cromossomo do indivíduo. Este campo é melhor descrito na seção [Representação dos cromossomos](#representação-dos-cromossomos);
  * `fitness`: valor de aptidão do indivíduo. No nosso caso particular, é calculada como o inverso do valor da função objetivo, isto é, $1 / f(x)$.


### Representação dos cromossomos

O cromossomo de um indivíduo é representado por um vetor de 5 bits, onde

<center>

| Bit de sinal | Bits de valor |
|:------------:|:-------------:|
| 0 ou 1       | xxxx          |

</center>

Por exemplo, se um indivíduo possui como fenótipo (isto é, seu valor) $x = -7$, então seu genótipo (cromossomo) é representado por

$${\color{yellow}1}{\color{orange}0111}$$

É importante ressaltar que números negativos não são representados seguindo o método do [complemento de 2](https://pt.wikipedia.org/wiki/Complemento_para_dois), e sim por seu valor absoluto, com o bit de sinal indicando se o número é positivo ou negativo (representação também conhecida como [sinal-e-magnitude](https://pt.wikipedia.org/wiki/Representação_de_números_com_sinal#Método_sinal-e-magnitude)).

Portanto, os bits de valor de um número positivo são exatamente iguais aos bits de valor do mesmo número negativo, e vice-versa.

### Seleção

A seleção é feita por torneio, onde dois pares de indivíduos escolhidos aleatoriamente da população competem entre si. O indivíduo com maior valor de aptidão entre cada par é selecionado para o crossover.

### Crossover e mutação

Cada par de filhos tem 60% de chance de ser gerado por crossover. O teste é feito através da geração de um número aleatório que é então comparado com a taxa de crossover. Caso o teste falhe, o par será feito de cópias exatas dos pais.

De forma semelhante, para todos os filhos, cada um de seus genes (bits do cromossomo) tem 1% de chance de sofrer mutação. O teste é feito da mesma forma, porém com a taxa de mutação. Caso o teste falhe, o gene não sofrerá mutação. Uma mutação é equivalente a trocar o valor do bit (0 $\rightarrow$ 1, 1 $\rightarrow$ 0).
