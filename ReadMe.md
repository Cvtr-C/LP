# 🌌 Gerenciador Espacial

Sistema desenvolvido em **C++20** para gerenciamento de pontos em um plano cartesiano, utilizando conceitos de **Estruturas de Dados**, **Programação Orientada a Objetos**, **geometria computacional**, manipulação de arquivos e **OpenCV**.

O programa permite:

* 📋 Gerenciar uma lista de coordenadas;
* 📚 Trabalhar com uma estrutura de pilha — **LIFO**;
* 🚶 Trabalhar com uma estrutura de fila — **FIFO**;
* ➕ Adicionar pontos em diferentes posições;
* ➖ Remover pontos;
* 🔎 Encontrar o ponto mais próximo de uma coordenada;
* 🎯 Calcular um centroide regional;
* ⭕ Gerar pontos distribuídos em uma circunferência;
* 📁 Importar coordenadas de arquivos `.txt`;
* 🚫 Impedir coordenadas duplicadas;
* 🖱️ Selecionar coordenadas utilizando cliques;
* 🗺️ Visualizar os pontos graficamente através do OpenCV.

---

# 📌 Índice

* [Sobre o projeto](#-sobre-o-projeto)
* [Conceitos utilizados](#-conceitos-utilizados)
* [Arquitetura](#-arquitetura)
* [Estrutura de dados utilizada](#-estrutura-de-dados-utilizada)
* [Lista](#-lista)
* [Pilha — LIFO](#-pilha--lifo)
* [Fila — FIFO](#-fila--fifo)
* [Gerenciamento de pontos](#-gerenciamento-de-pontos)
* [Ponto mais próximo](#-ponto-mais-próximo)
* [Centroide regional](#-centroide-regional)
* [Geração de circunferência](#-geração-de-circunferência)
* [OpenCV](#-opencv)
* [Importação de arquivos](#-importação-de-arquivos)
* [Organização dos arquivos](#-organização-dos-arquivos)
* [Instalação no Windows](#-instalação-no-windows)
* [Instalação no Linux](#-instalação-no-linux)
* [Compilação no Windows](#-compilação-no-windows)
* [Compilação no Linux](#-compilação-no-linux)
* [Execução](#-execução)
* [Menu principal](#-menu-principal)
* [Solução de problemas](#-solução-de-problemas)
* [Conceitos matemáticos](#-conceitos-matemáticos)
* [Objetivos acadêmicos](#-objetivos-acadêmicos)
* [Possíveis melhorias](#-possíveis-melhorias)

---

# 🎯 Sobre o projeto

O **Gerenciador Espacial** foi desenvolvido como uma aplicação prática para estudar e aplicar conceitos de **Estruturas de Dados e Programação Orientada a Objetos em C++**.

A aplicação trabalha com pontos representados por coordenadas cartesianas:

```text
P = (X, Y)
```

Esses pontos podem ser manipulados através de três comportamentos:

```text
                    GERENCIADOR ESPACIAL
                            │
          ┌─────────────────┼─────────────────┐
          │                 │                 │
          ▼                 ▼                 ▼
       LISTA              PILHA              FILA
       Geral              LIFO              FIFO
          │                 │                 │
          └─────────────────┼─────────────────┘
                            │
                            ▼
                      Pontos (X,Y)
                            │
                            ▼
                         OpenCV
                            │
                            ▼
                  Visualização gráfica
```

A aplicação possui uma interface textual para gerenciamento e uma interface gráfica baseada em OpenCV para visualização e seleção de coordenadas.

---

# 🧠 Conceitos utilizados

O projeto reúne vários conceitos importantes de C++:

### Programação

* C++20;
* Classes;
* Objetos;
* Encapsulamento;
* Construtores;
* Destrutores;
* Métodos;
* Arquivos `.h` e `.cpp`;
* `std::vector`;
* Referências;
* Manipulação de arquivos;
* Entrada e validação de dados.

### Estruturas de Dados

* Lista;
* Pilha;
* Fila;
* Inserção;
* Remoção;
* Busca;
* Índices.

### Matemática

* Plano cartesiano;
* Distância euclidiana;
* Distância euclidiana ao quadrado;
* Centroide;
* Média;
* Circunferência;
* Seno;
* Cosseno;
* Conversão entre coordenadas cartesianas e coordenadas de imagem.

### Computação gráfica

* OpenCV;
* Janelas;
* Imagens;
* Desenho de pontos;
* Eventos de mouse;
* Conversão de coordenadas.

---

# 🏗️ Arquitetura

O fluxo principal da aplicação é:

```text
main.cpp
   │
   ▼
menu.cpp
   │
   ▼
lista
   │
   ├── ponto
   │
   ├── std::vector
   │
   └── OpenCV
```

O `main.cpp` cria uma instância da classe `lista` e utiliza os módulos de menu para oferecer três formas de manipulação:

```text
1 - Lista de Coordenadas
2 - Pilha (LIFO)
3 - Fila (FIFO)
4 - Sair
```

---

# 🗂️ Estrutura de dados utilizada

## ⚠️ Importante

Apesar do projeto utilizar o conceito de **Lista**, a implementação interna não é uma lista encadeada.

O armazenamento é realizado através de:

```cpp
std::vector<ponto> list;
```

Ou seja:

```text
lista
  │
  └── std::vector
          │
          ├── ponto
          ├── ponto
          ├── ponto
          └── ponto
```

A classe `lista` fornece operações que permitem utilizar esse vetor como:

* uma lista geral;
* uma pilha;
* uma fila.

Isso é importante para compreender corretamente a implementação.

---

# 📋 Lista

A lista geral permite inserir e remover pontos em diferentes posições.

## ➕ Operações de inserção

O projeto possui:

```text
adicionarNoComeco()
adicionarNoFim()
adicionarNoIndice()
```

Além dessas operações, existem métodos especializados para:

```text
file()
adicionarCentroideMaisProximo()
circle()
```

---

## `adicionarNoComeco()`

Adiciona um ponto no início da estrutura.

Exemplo:

```text
Antes:

A → B → C

Adicionar D no começo:

D → A → B → C
```

Internamente é utilizado:

```cpp
list.insert(list.begin(), p);
```

### `begin()`

`begin()` retorna um iterador para o primeiro elemento do `vector`.

```text
begin()
  ↓
[A, B, C]
 ^
 primeiro
```

### `insert()`

`insert()` adiciona um elemento na posição indicada.

---

# `adicionarNoFim()`

Adiciona um ponto ao final.

```text
Antes:

A → B → C

Depois:

A → B → C → D
```

A implementação utiliza:

```cpp
list.push_back(p);
```

### `push_back()`

Adiciona um elemento no final do `vector`.

É uma operação especialmente útil para implementar:

* inserção no final da lista;
* `push` de uma pilha;
* `enqueue` de uma fila.

---

# `adicionarNoIndice()`

Insere um ponto em uma posição específica.

O usuário informa um índice começando em **1**.

Exemplo:

```text
Lista:

1 → A
2 → B
3 → C
4 → D
```

Inserindo `X` no índice 2:

```text
1 → A
2 → X
3 → B
4 → C
5 → D
```

O código utiliza:

```cpp
list.insert(list.begin() + (ind - 1), p);
```

O `-1` ocorre porque:

```text
Índice apresentado ao usuário:

1 2 3 4

Índice real do vector:

0 1 2 3
```

---

# ➖ Operações de remoção

A lista possui:

```text
apagarPrimeiroPonto()
apagarUltimoPonto()
apagarIndice()
apagarPontoMaisProximo()
```

---

# `apagarPrimeiroPonto()`

Remove o primeiro elemento.

```text
Antes:

A → B → C → D

Depois:

B → C → D
```

Utiliza:

```cpp
list.erase(list.begin());
```

---

# `apagarUltimoPonto()`

Remove o último elemento.

```text
Antes:

A → B → C → D

Depois:

A → B → C
```

Utiliza:

```cpp
list.pop_back();
```

Essa operação também é utilizada para implementar o **Pop da pilha**.

---

# `apagarIndice()`

Remove o elemento localizado em determinado índice.

Exemplo:

```text
1 → A
2 → B
3 → C
4 → D
```

Removendo o índice `2`:

```text
1 → A
2 → C
3 → D
```

O código utiliza:

```cpp
list.erase(list.begin() + (ind - 1));
```

---

# `apagarPontoMaisProximo()`

Remove o ponto que está mais próximo de uma coordenada informada.

Exemplo:

```text
Referência:

(10, 10)

Pontos:

A → (2, 2)
B → (9, 8)
C → (30, 40)
```

O ponto:

```text
B → (9, 8)
```

será removido porque é o mais próximo de `(10,10)`.

---

# 📚 Pilha — LIFO

A pilha segue o princípio:

> **LIFO — Last In, First Out**

Ou seja:

> O último elemento inserido é o primeiro a sair.

Uma analogia simples é uma pilha de pratos:

```text
        ┌─────┐
        │  D  │ ← último colocado
        ├─────┤
        │  C  │
        ├─────┤
        │  B  │
        ├─────┤
        │  A  │
        └─────┘
           ↑
       primeiro a sair
```

---

# `Push`

O `Push` adiciona um elemento no topo da pilha.

Neste projeto, o topo da pilha é considerado o **final do vector**.

```text
Antes:

A → B → C

Push(D)

Depois:

A → B → C → D
```

A implementação utiliza:

```cpp
adicionarNoFim(x, y);
```

que internamente utiliza:

```cpp
list.push_back(p);
```

---

# `Pop`

O `Pop` remove o elemento que está no topo.

```text
Antes:

A → B → C → D

Pop()

Depois:

A → B → C
```

No projeto:

```cpp
list.apagarUltimoPonto();
```

que utiliza:

```cpp
list.pop_back();
```

Portanto:

```text
Push  → push_back()
Pop   → pop_back()
```

---

# 📌 Exemplo completo de Pilha

```text
Push(A)

A

Push(B)

A → B

Push(C)

A → B → C

Pop()

A → B

Pop()

A
```

A ordem de saída é:

```text
C
B
A
```

Isso caracteriza o comportamento **LIFO**.

---

# 🚶 Fila — FIFO

A fila segue o princípio:

> **FIFO — First In, First Out**

Ou seja:

> O primeiro elemento inserido é o primeiro a sair.

Uma analogia é uma fila de pessoas:

```text
Entrada
  ↓

A → B → C → D
↑
primeiro a chegar

Saída
  ↓
```

---

# `Enqueue`

Adiciona um elemento no final da fila.

```text
Antes:

A → B → C

Enqueue(D)

Depois:

A → B → C → D
```

No projeto:

```cpp
list.adicionarNoFim(x, y);
```

que utiliza:

```cpp
list.push_back(p);
```

---

# `Dequeue`

Remove o primeiro elemento.

```text
Antes:

A → B → C → D

Dequeue()

Depois:

B → C → D
```

No projeto:

```cpp
list.apagarPrimeiroPonto();
```

que utiliza:

```cpp
list.erase(list.begin());
```

Portanto:

```text
Enqueue → push_back()
Dequeue → erase(begin())
```

---

# 📌 Exemplo completo de Fila

```text
Enqueue(A)

A

Enqueue(B)

A → B

Enqueue(C)

A → B → C

Dequeue()

B → C

Dequeue()

C
```

A ordem de saída é:

```text
A
B
C
```

Isso caracteriza o comportamento **FIFO**.

---

# 🔎 Comparação entre Lista, Pilha e Fila

| Estrutura | Inserção          | Remoção                       | Regra    |
| --------- | ----------------- | ----------------------------- | -------- |
| Lista     | início/fim/índice | início/fim/índice/proximidade | flexível |
| Pilha     | final             | final                         | LIFO     |
| Fila      | final             | início                        | FIFO     |

Visualmente:

```text
LISTA

A → B → C → D
↑   ↑   ↑   ↑
várias posições possíveis


PILHA

A → B → C → D
            ↑
          Push/Pop


FILA

A → B → C → D
↑           ↑
saída      entrada
```

---

# 📍 Gerenciamento de pontos

Cada ponto é representado pela classe:

```cpp
ponto
```

Um ponto possui:

```text
X
Y
```

Exemplo:

```text
P = (15, 20)
```

A classe fornece operações para:

* criar um ponto;
* alterar suas coordenadas;
* consultar `X`;
* consultar `Y`.

A implementação está separada em:

```text
ponto.h
ponto.cpp
```

Essa separação permite deixar a declaração da classe no `.h` e sua implementação no `.cpp`.

---

# 🚫 Controle de duplicidade

O projeto não permite adicionar duas vezes exatamente a mesma coordenada.

Por exemplo:

```text
(10,20)
```

já existente significa que:

```text
(10,20)
```

não poderá ser inserido novamente.

A função responsável por verificar isso é:

```cpp
Duplicate(int x, int y)
```

Ela percorre os pontos existentes e compara:

```cpp
list.at(i).x() == x
```

e:

```cpp
list.at(i).y() == y
```

Se os dois valores forem iguais, o ponto é considerado duplicado.

---

# 📍 Ponto mais próximo

A função:

```cpp
encontrarMaisProximo(int x, int y)
```

procura o ponto mais próximo de uma coordenada de referência.

A distância utilizada é:

$$
d^2=(x_2-x_1)^2+(y_2-y_1)^2
$$

O programa utiliza a **distância ao quadrado** porque não precisa calcular a raiz quadrada para descobrir qual distância é menor.

Exemplo:

```text
P1 → d² = 25
P2 → d² = 9
P3 → d² = 36
```

Como:

```text
9 < 25 < 36
```

`P2` é o ponto mais próximo.

A função retorna o **índice** do ponto mais próximo.

Caso a lista esteja vazia:

```cpp
return -1;
```

---

# 🎯 Centroide regional

A função:

```cpp
adicionarCentroideMaisProximo()
```

calcula um centroide baseado nos pontos próximos de uma coordenada de referência.

O processo é:

```text
1. Recebe X,Y de referência
        ↓
2. Encontra o ponto mais próximo
        ↓
3. Define uma região de proximidade
        ↓
4. Seleciona os pontos da região
        ↓
5. Soma X e Y
        ↓
6. Calcula a média
        ↓
7. Cria um novo ponto
        ↓
8. Adiciona o centroide
```

No código, a região utiliza a condição:

```cpp
distSq <= menorDist * 2.5
```

Ou seja, a função não calcula um centroide de todos os pontos da lista. Ela calcula um **centroide regional baseado nos pontos suficientemente próximos da referência**.

As coordenadas são calculadas por:

$$
C_x=\frac{\sum X_i}{n}
$$

$$
C_y=\frac{\sum Y_i}{n}
$$

O resultado é convertido para `int`, portanto existe truncamento da parte decimal.

---

# ⭕ Geração de circunferência

A função:

```cpp
circle(cx, cy, r, np)
```

gera vários pontos distribuídos aproximadamente sobre uma circunferência.

Parâmetros:

```text
cx → coordenada X do centro
cy → coordenada Y do centro
r  → raio
np → número desejado de pontos
```

A fórmula utilizada é:

$$
x=c_x+\cos(\theta)r
$$

$$
y=c_y+\sin(\theta)r
$$

O ângulo é incrementado de acordo com a quantidade de pontos.

Por exemplo:

```text
Centro = (0,0)
Raio   = 10
Pontos = 8
```

Os pontos serão distribuídos ao redor do centro.

Visualmente:

```text
              •
        •           •

     •       (0,0)       •

        •           •
              •
```

O programa também verifica:

```text
np > 0
r >= 0
```

e evita inserir pontos duplicados.

---

# 🖱️ OpenCV

O projeto utiliza **OpenCV** para criar a parte gráfica da aplicação.

A biblioteca é utilizada principalmente para:

* criar a janela gráfica;
* criar a imagem onde os pontos são desenhados;
* desenhar os pontos;
* mostrar a imagem;
* receber cliques do mouse;
* converter o clique em coordenadas cartesianas.

---

# 🖼️ Como o OpenCV representa o plano

O programa cria uma imagem de:

```text
800 × 800 pixels
```

A imagem inicialmente possui fundo branco.

O centro utilizado pelo programa é:

```text
centroX = 400
centroY = 400
```

Assim, aproximadamente:

```text
                imagem
     0                    800
     ┌──────────────────────┐
     │                      │
     │                      │
     │         (0,0)        │
     │          •           │
     │                      │
     │                      │
     └──────────────────────┘
```

O programa utiliza:

```cpp
fatorEscala = 4;
```

para transformar unidades cartesianas em pixels.

---

# 🔄 Conversão de coordenadas

Para desenhar um ponto `(x,y)` na imagem:

```cpp
px = x * fatorEscala + centroX;
py = y * fatorEscala + centroY;
```

Por exemplo:

```text
P = (10, 5)

px = 10 × 4 + 400
px = 440

py = 5 × 4 + 400
py = 420
```

Então o ponto cartesiano:

```text
(10,5)
```

é desenhado aproximadamente no pixel:

```text
(440,420)
```

---

# 🖱️ Clique do mouse

O programa também permite obter uma coordenada clicando na janela.

A função responsável pelo processamento do clique é:

```cpp
clique()
```

Quando o usuário pressiona o botão esquerdo:

```cpp
EVENT_LBUTTONDOWN
```

o programa transforma a posição do pixel novamente em coordenadas cartesianas:

```cpp
x = (pixelX - centroX) / fatorEscala;
y = (pixelY - centroY) / fatorEscala;
```

Assim:

```text
Clique na imagem
       ↓
Coordenada em pixels
       ↓
Conversão matemática
       ↓
Coordenada cartesiana
       ↓
(X,Y)
```

---

# 🪟 `renderizarTela()`

A função:

```cpp
renderizarTela()
```

é responsável por construir a imagem exibida pelo OpenCV.

Ela:

1. cria uma imagem `800 × 800`;
2. utiliza fundo branco;
3. percorre todos os pontos;
4. converte cada coordenada para pixel;
5. desenha os pontos;
6. opcionalmente escreve uma mensagem na imagem.

O desenho dos pontos utiliza:

```cpp
cv::circle()
```

---

# 🖱️ `obterPontoPorClique()`

Essa função cria uma janela para o usuário selecionar uma coordenada.

O fluxo é:

```text
obterPontoPorClique()
        ↓
renderizarTela()
        ↓
namedWindow()
        ↓
setMouseCallback()
        ↓
imshow()
        ↓
aguarda clique
        ↓
converte pixel → coordenada
        ↓
retorna X,Y
```

O usuário também pode pressionar:

```text
ESC
```

para cancelar a operação.

---

# 📺 `mostrarPontos()`

A função:

```cpp
mostrarPontos()
```

possui duas responsabilidades:

### Terminal

Mostra os pontos:

```text
[1] -> X: 10 | Y: 20
[2] -> X: 15 | Y: 30
[3] -> X: 25 | Y: 40
```

### OpenCV

Também cria a janela:

```text
Mapeamento Espacial
```

e mostra graficamente os pontos.

---

# 📁 Importação de arquivos

O projeto possui dois arquivos de exemplo:

```text
pontos1.txt
pontos2.txt
```

O formato esperado é:

```text
X - Y
```

Exemplo:

```text
10 - 20
15 - 30
25 - 40
50 - 60
```

A função:

```cpp
file()
```

abre o arquivo, lê cada coordenada e adiciona os pontos.

Durante a leitura, também verifica duplicidades.

---

# 📂 Organização dos arquivos

```text
LP/
│
├── .vscode/
│
├── main.cpp
│
├── lista.cpp
├── lista.h
│
├── ponto.cpp
├── ponto.h
│
├── menu.cpp
├── menu.h
│
├── pontos1.txt
├── pontos2.txt
│
├── gerenciador_espacial.exe
│
└── ReadMe.md
```

---

# 📄 Responsabilidade de cada arquivo

| Arquivo                    | Responsabilidade                             |
| -------------------------- | -------------------------------------------- |
| `main.cpp`                 | Ponto de entrada da aplicação                |
| `lista.h`                  | Declaração da classe `lista`                 |
| `lista.cpp`                | Implementação das operações da lista         |
| `ponto.h`                  | Declaração da classe `ponto`                 |
| `ponto.cpp`                | Implementação da classe `ponto`              |
| `menu.h`                   | Declaração das funções de menu               |
| `menu.cpp`                 | Implementação dos menus e entrada do usuário |
| `pontos1.txt`              | Primeiro conjunto de coordenadas             |
| `pontos2.txt`              | Segundo conjunto de coordenadas              |
| `.vscode/`                 | Configurações do Visual Studio Code          |
| `gerenciador_espacial.exe` | Executável compilado no Windows              |

---

# 🪟 Instalação no Windows

## Requisitos

Para compilar o projeto no Windows, recomenda-se utilizar:

* Windows;
* Git;
* MSYS2;
* UCRT64;
* GCC;
* GDB;
* OpenCV;
* Visual Studio Code.

O projeto atual foi configurado para o ambiente **MSYS2 UCRT64**.

> **Importante:** abra o terminal **MSYS2 UCRT64**, e não o terminal MSYS comum.

O MSYS2 utiliza ambientes diferentes; este projeto utiliza especificamente o **UCRT64**.

---

# 📥 1. Instalar o MSYS2

Baixe e instale o MSYS2.

Depois da instalação, abra:

```text
MSYS2 UCRT64
```

O ambiente UCRT64 fornece o GCC compatível com a configuração utilizada pelo projeto.

---

# 🔄 2. Atualizar o MSYS2

No terminal **MSYS2 UCRT64**:

```bash
pacman -Syu
```

Se o MSYS2 solicitar o fechamento do terminal, feche, abra novamente o **UCRT64** e execute novamente a atualização.

---

# 📦 3. Instalar GCC, GDB e OpenCV

Execute:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc \
          mingw-w64-ucrt-x86_64-gdb \
          mingw-w64-ucrt-x86_64-opencv
```

Isso instala:

```text
GCC     → compilador C++
GDB     → debugger
OpenCV  → biblioteca de visão computacional
```

O pacote OpenCV disponibilizado pelo MSYS2 fornece os arquivos necessários para incluir e vincular a biblioteca ao projeto.

---

# 🔧 4. Configurar o PATH no Windows

Adicione:

```text
C:\msys64\ucrt64\bin
```

ao `PATH` do Windows.

Isso é importante principalmente para que as DLLs necessárias do ambiente UCRT64 possam ser encontradas durante a execução do programa.

---

# 🔎 5. Verificar a instalação

No MSYS2 UCRT64:

```bash
g++ --version
```

Depois:

```bash
gdb --version
```

E:

```bash
pkg-config --modversion opencv4
```

Se os comandos retornarem versões, o ambiente está configurado.

---

# 🐧 Instalação no Linux

O processo no Linux é diferente do Windows.

Em distribuições baseadas em Debian/Ubuntu, podemos utilizar o gerenciador de pacotes `apt`.

## 1. Atualizar os pacotes

```bash
sudo apt update
```

---

# 📦 2. Instalar compilador e OpenCV

Execute:

```bash
sudo apt install build-essential g++ libopencv-dev pkg-config
```

Os principais componentes são:

```text
build-essential → ferramentas básicas de compilação
g++             → compilador C++
libopencv-dev   → headers e bibliotecas de desenvolvimento do OpenCV
pkg-config      → auxilia na obtenção das flags de compilação
```

A documentação oficial do OpenCV também apresenta a instalação e compilação para Linux, inclusive utilizando CMake/Ninja quando se deseja compilar a própria biblioteca a partir do código-fonte. Para este projeto, entretanto, `libopencv-dev` é muito mais simples.

---

# 🔎 3. Verificar o OpenCV no Linux

Execute:

```bash
pkg-config --modversion opencv4
```

Também é possível verificar:

```bash
g++ --version
```

---

# 📥 Clonar o projeto

No Windows ou Linux:

```bash
git clone https://github.com/Cvtr-C/LP.git
```

Entre no projeto:

```bash
cd LP
```

Troque para a branch:

```bash
git checkout cmaismais
```

Ou, em versões recentes do Git:

```bash
git switch cmaismais
```

---

# 🪟 Compilação no Windows

No **MSYS2 UCRT64**, dentro da pasta do projeto:

```bash
g++ *.cpp \
-o gerenciador_espacial.exe \
-IC:/msys64/ucrt64/include/opencv4 \
-LC:/msys64/ucrt64/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_videoio \
-std=c++20
```

### O que cada parte significa?

```text
g++
```

Executa o compilador C++.

```text
*.cpp
```

Compila todos os arquivos `.cpp` do projeto.

```text
-o gerenciador_espacial.exe
```

Define o nome do executável.

```text
-I...
```

Informa onde estão os arquivos de cabeçalho.

```text
-L...
```

Informa onde estão as bibliotecas.

```text
-lopencv_core
```

Vincula o módulo principal do OpenCV.

```text
-lopencv_imgproc
```

Vincula funcionalidades de processamento de imagem.

```text
-lopencv_highgui
```

Vincula funcionalidades de interface gráfica, janelas e interação.

```text
-lopencv_videoio
```

Vincula o módulo de entrada/saída de vídeo.

```text
-std=c++20
```

Solicita compilação utilizando o padrão C++20.

---

# 🐧 Compilação no Linux

No Linux, a forma mais prática é utilizar `pkg-config` para descobrir automaticamente onde estão os headers e bibliotecas do OpenCV.

Dentro da pasta do projeto:

```bash
g++ *.cpp \
-o gerenciador_espacial \
$(pkg-config --cflags --libs opencv4) \
-std=c++20
```

O `pkg-config` fornece automaticamente as opções equivalentes a:

```text
-I...
-L...
-l...
```

necessárias para o OpenCV instalado pelo sistema.

---

# ▶️ Executando no Windows

Depois da compilação:

```bash
./gerenciador_espacial.exe
```

Também é possível executar o arquivo pelo Windows.

---

# ▶️ Executando no Linux

Depois da compilação:

```bash
./gerenciador_espacial
```

Caso seja necessário conceder permissão de execução:

```bash
chmod +x gerenciador_espacial
```

e depois:

```bash
./gerenciador_espacial
```

---

# 💻 Executando pelo VS Code

Abra a pasta do projeto:

```text
LP/
```

no Visual Studio Code.

A branch já possui configurações dentro de:

```text
.vscode/
```

O projeto possui uma tarefa de compilação configurada para o ambiente Windows/MSYS2.

No Windows, é possível utilizar:

```text
Ctrl + Shift + B
```

para executar a tarefa de build configurada.

No Linux, recomenda-se utilizar o comando de compilação mostrado anteriormente, pois a configuração existente em `.vscode` foi criada especificamente para os caminhos do MSYS2 no Windows.

---

# 🖥️ Menu principal

Ao iniciar o programa:

```text
=======================================
        GERENCIADOR ESPACIAL
=======================================

[1] - Lista de Coordenadas (Geral)
[2] - Pilha (LIFO)
[3] - Fila (FIFO)
[4] - Sair do Sistema
```

---

# 📋 Menu da Lista

A lista possui duas categorias principais:

```text
[1] Adicionar Coordenada
[2] Excluir Coordenada
[3] Voltar
```

## Adicionar

```text
[1] No Inicio
[2] No Final
[3] Em Indice Especifico
[4] De Arquivo
[5] No Centroide Proximo
[6] Gerar Circulo
[7] Voltar
```

## Excluir

```text
[1] Primeiro
[2] Ultimo
[3] Por Indice
[4] Proximo de (X,Y)
[5] Voltar
```

---

# 📚 Menu da Pilha

```text
[1] Push (Adicionar no Fim)
[2] Pop (Remover do Fim)
[3] Voltar
```

O usuário também pode inserir dados através de:

```text
- Coordenadas digitadas;
- Arquivo;
- Circunferência.
```

---

# 🚶 Menu da Fila

```text
[1] Enqueue (Adicionar no Fim)
[2] Dequeue (Remover do Inicio)
[3] Voltar
```

Também é possível inserir pontos através de:

```text
- Coordenadas;
- Arquivo;
- Circunferência.
```

---

# ⌨️ Entrada de coordenadas

Quando uma operação precisa de uma coordenada, o programa oferece:

```text
[1] Digitar (Teclado)
[2] Clicar (Interface Grafica)
```

### Teclado

O usuário informa:

```text
X
Y
```

### Interface gráfica

O usuário clica diretamente na janela OpenCV.

O programa transforma a posição do mouse em coordenadas cartesianas.

---

# ⚠️ Validação de entrada

A função:

```cpp
lerInteiro()
```

garante que o usuário forneça um número inteiro.

Se for digitado algo inválido:

```text
abc
```

o programa apresenta uma mensagem de erro e solicita uma nova entrada.

Isso é feito utilizando:

```cpp
cin.clear();
cin.ignore(...);
```

para limpar o estado de erro do fluxo de entrada.

---

# 🧮 Complexidade das principais operações

Como a implementação utiliza `std::vector`, algumas operações possuem custos diferentes.

| Operação            | Complexidade aproximada |
| ------------------- | ----------------------: |
| Adicionar no final  |         O(1) amortizado |
| Remover no final    |                    O(1) |
| Acessar por índice  |                    O(1) |
| Buscar duplicidade  |                    O(n) |
| Buscar mais próximo |                    O(n) |
| Inserir no início   |                    O(n) |
| Remover do início   |                    O(n) |
| Inserir no meio     |                    O(n) |
| Remover do meio     |                    O(n) |

Isso é importante principalmente para entender por que a implementação da fila não é ideal para grandes quantidades de elementos: `Dequeue` utiliza `erase(begin())`, fazendo os demais elementos serem deslocados.

---

# 🧪 Conceitos matemáticos

O projeto utiliza:

### Distância euclidiana

$$
d=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}
$$

### Distância ao quadrado

$$
d^2=(x_2-x_1)^2+(y_2-y_1)^2
$$

### Centroide

$$
C_x=\frac{\sum X_i}{n}
$$

$$
C_y=\frac{\sum Y_i}{n}
$$

### Circunferência

$$
x=x_c+r\cos(\theta)
$$

$$
y=y_c+r\sin(\theta)
$$

---

# 🛠️ Tecnologias utilizadas

| Tecnologia    | Função                           |
| ------------- | -------------------------------- |
| C++20         | Linguagem utilizada              |
| G++           | Compilação                       |
| GDB           | Debugging                        |
| `std::vector` | Armazenamento dos pontos         |
| OpenCV        | Interface gráfica e visualização |
| MSYS2 UCRT64  | Ambiente C++ no Windows          |
| VS Code       | Editor/IDE                       |
| Git           | Controle de versão               |

---

# 🔧 Solução de problemas

## `opencv2/opencv.hpp: No such file or directory`

### Windows

Verifique se o OpenCV está instalado:

```bash
pacman -S mingw-w64-ucrt-x86_64-opencv
```

E confira se o comando de compilação contém:

```text
-I C:/msys64/ucrt64/include/opencv4
```

---

### Linux

Instale:

```bash
sudo apt install libopencv-dev
```

Depois verifique:

```bash
pkg-config --modversion opencv4
```

---

# `cannot find -lopencv_core`

No Windows, verifique:

```text
C:\msys64\ucrt64\lib
```

e confirme se as bibliotecas OpenCV estão instaladas.

Também confira:

```text
-LC:/msys64/ucrt64/lib
```

---

# DLL do OpenCV não encontrada no Windows

Se o programa compilar mas não executar por causa de DLLs, confira se:

```text
C:\msys64\ucrt64\bin
```

está no `PATH` do Windows.

Depois abra um novo terminal para que a alteração seja reconhecida.

---

# `pkg-config: command not found`

No Linux:

```bash
sudo apt install pkg-config
```

Depois:

```bash
pkg-config --modversion opencv4
```

---

# Programa compila, mas a janela OpenCV não aparece

Verifique se o ambiente possui suporte gráfico e se o programa está sendo executado em uma sessão gráfica.

O projeto utiliza funcionalidades como:

```cpp
namedWindow()
imshow()
waitKey()
setMouseCallback()
```

Portanto, ele precisa conseguir criar uma janela gráfica.

---

# 📚 Possíveis melhorias futuras

Algumas melhorias podem tornar o projeto ainda mais robusto:

* [ ] Criar um `CMakeLists.txt`;
* [ ] Criar um sistema de build multiplataforma;
* [ ] Separar melhor a implementação da lista, pilha e fila;
* [ ] Utilizar `std::deque` para uma implementação mais eficiente de fila;
* [ ] Criar uma classe específica para `Pilha`;
* [ ] Criar uma classe específica para `Fila`;
* [ ] Adicionar persistência automática;
* [ ] Exportar pontos para `.txt`;
* [ ] Exportar pontos para `.csv`;
* [ ] Adicionar zoom no plano;
* [ ] Adicionar deslocamento da câmera;
* [ ] Melhorar a interface gráfica;
* [ ] Permitir seleção de pontos com o mouse;
* [ ] Diferenciar centroides de pontos comuns;
* [ ] Adicionar cálculo da distância entre dois pontos;
* [ ] Adicionar busca por região;
* [ ] Criar testes automatizados;
* [ ] Melhorar o tratamento de exceções;
* [ ] Criar documentação automática da API.

---

# 🎓 Objetivos acadêmicos

Este projeto permite praticar conceitos fundamentais de:

```text
C++
 │
 ├── Classes
 ├── Objetos
 ├── Encapsulamento
 ├── Construtores
 ├── Destrutores
 ├── Métodos
 │
 ├── std::vector
 ├── Lista
 ├── Pilha
 ├── Fila
 │
 ├── Manipulação de arquivos
 ├── Validação de entrada
 │
 ├── Geometria computacional
 ├── Coordenadas cartesianas
 ├── Distâncias
 ├── Centroide
 ├── Circunferência
 │
 └── OpenCV
```

Além de estudar as estruturas de dados, o projeto demonstra como conceitos matemáticos podem ser utilizados em uma aplicação gráfica.

---

# 📌 Resumo da implementação

```text
                    GERENCIADOR ESPACIAL
                            │
              ┌─────────────┼─────────────┐
              │             │             │
              ▼             ▼             ▼
           LISTA          PILHA          FILA
              │            LIFO           FIFO
              │             │             │
              └─────────────┼─────────────┘
                            │
                            ▼
                       std::vector
                            │
                            ▼
                          ponto
                         /     \
                        X       Y
                            │
                            ▼
                         OpenCV
                            │
             ┌──────────────┴──────────────┐
             │                             │
             ▼                             ▼
       Visualização                  Clique do mouse
       dos pontos                         │
             │                            │
             └────────────┬───────────────┘
                          ▼
                    Coordenada (X,Y)
```

---

# 🚀 Execução rápida

## Windows — MSYS2 UCRT64

```bash
git clone https://github.com/Cvtr-C/LP.git
cd LP
git switch cmaismais

g++ *.cpp \
-o gerenciador_espacial.exe \
-IC:/msys64/ucrt64/include/opencv4 \
-LC:/msys64/ucrt64/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_videoio \
-std=c++20

./gerenciador_espacial.exe
```

## Linux — Ubuntu/Debian

Instalação:

```bash
sudo apt update
sudo apt install build-essential g++ libopencv-dev pkg-config
```

Clone:

```bash
git clone https://github.com/Cvtr-C/LP.git
cd LP
git switch cmaismais
```

Compilação:

```bash
g++ *.cpp \
-o gerenciador_espacial \
$(pkg-config --cflags --libs opencv4) \
-std=c++20
```

Execução:

```bash
./gerenciador_espacial
```

---

# 👨‍💻 Autor

**Cvtr-C**

Projeto desenvolvido para estudo e prática de **C++, Estruturas de Dados, Programação Orientada a Objetos e OpenCV**.

---

# 📄 Licença

Este projeto é disponibilizado para fins acadêmicos e educacionais.
