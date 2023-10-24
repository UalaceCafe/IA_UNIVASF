# Extra 1 - Algoritmo de classificação Naïve Bayes

Me propus a fazer esta atividade "extra" com dois própositos em mente: auxiliar na compreensão do assunto teórico visto em sala, e também como forma de aprendizado de uma nova linguagem de programação - _C++_, especificamente. Assim, alguns ou vários trechos de código encontrados aqui podem não ser considerados "boas práticas" em _C++_.

## Descrição

Esta aplicação implementa o algoritmo de classificação Naïve Bayes para decisão simples baseado em um conjunto pequeno de variáveis aleatórias.

Existem 4 conjuntos de variáveis aleatórias:

* __Outlook__: Sunny, Overcast, Rain
* __Temperature__: Hot, Mild, Cool
* __Humidity__: Normal, High
* __Wind__: Weak, Strong

E as seguintes classes:

* __PlayTennis__: Yes, No

## Base de dados

O agente foi treinado com uma base de dados simples, especificada na imagem a seguir:

![Base de dados](training_data.png)

A base de dados é composta por 14 amostras, cada uma com 4 variáveis aleatórias e a classe daquela amostra respectiva.

Por estarmos lidando com uma quantidade pequena de dados, optei por definir a base de dados diretamente no código-fonte, ao invés de ler de um arquivo externo.

```cpp
const std::array<const std::array<std::string, 5>, 14> training_data = {{
    {{ "Sunny", "Hot", "High", "Weak", "No" }},
    {{ "Sunny", "Hot", "High", "Strong", "No" }},
    {{ "Overcast", "Hot", "High", "Weak", "Yes" }},
    {{ "Rain", "Mild", "High", "Weak", "Yes" }},
    {{ "Rain", "Cool", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Cool", "Normal", "Strong", "No" }},
    {{ "Overcast", "Cool", "Normal", "Strong", "Yes" }},
    {{ "Sunny", "Mild", "High", "Weak", "No" }},
    {{ "Sunny", "Cool", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Mild", "Normal", "Weak", "Yes" }},
    {{ "Sunny", "Mild", "Normal", "Strong", "Yes" }},
    {{ "Overcast", "Mild", "High", "Strong", "Yes" }},
    {{ "Overcast", "Hot", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Mild", "High", "Strong", "No" }}
}};
```

## Como executar

Com a ferramenta `make`
  * Para compilar e executar automaticamente a aplicação, rode o comando `make` neste diretório raiz;
  * Para apenas compilar o código-fonte, rode o comando `make compile` neste diretório raiz.

Caso não possua a ferramenta `make`, execute o comando
> `g++ -Wall -pedantic -O2 -std=c++20 -Werror src/main.cpp src/stats.cpp -o bin/main`

Em qualquer um dos casos, o binário será gerado no diretório [`bin`](bin/).
