# Atividade 1 - 8-Puzzle com Busca em Largura e Profundidade

## Descrição

Esta aplicação implementa um agente inteligente para a resolução do problema do _quebra-cabeça de 8 peças_ utilizando os algoritmos de busca em largura e busca em profundidade.

## Como executar

* Instale alguma implementação de _ruby_ (ao menos `ruby 3.2`);
* Instale a biblioteca [ruby2d](https://github.com/ruby2d/ruby2d);
* Na pasta atual, rode a aplicação com `ruby main.rb`.

## Modificações

O arquivo `main.rb` contém a configuração inicial do jogo, como o estado inicial do tabuleiro e o algoritmo de busca a ser utilizado.

### Objetivo

Modificando a linha


```ruby
GOAL = [0, 1, 2, 3, 4, 5, 6, 7, 8].freeze
```
é possível definir o estado objetivo do tabuleiro. Os valores de cada célula devem ser únicos e devem também variar de 0 a 9, sendo que o número 0 representa o espaço vazio. Portanto, um vetor de estado será representado graficamente como um grid de tal forma:

```
0 1 2
3 4 5
6 7 8
```

### Estado inicial

A linha de código abaixo embaralha o tabuleiro inicial:

```ruby
board.shuffle_board
```

Para definir manualmente o estado do tabuleiro, basta modificar a linha para

```ruby
board.grid = [...]
```

onde as reticências devem ser substituídas por um vetor de estado válido.

### Algoritmo de busca

A linha abaixo define o algoritmo de busca a ser utilizado. Por padrão, é usado o de busca em largura.

```ruby
result = Solver.bfs(board, GOAL)
```

Para utilizar o algoritmo de busca em profundidade, basta alterar _bfs_ para _dfs_.
