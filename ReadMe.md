# 🌌 Gerenciador Espacial

Sistema desenvolvido em **C++** para gerenciamento e manipulação de pontos em um plano cartesiano, utilizando estruturas de dados e recursos de programação orientada a objetos.

O projeto permite inserir, remover, importar e visualizar coordenadas, além de implementar operações de **Lista, Pilha (LIFO) e Fila (FIFO)**.

A visualização dos pontos é realizada por meio da biblioteca **OpenCV**, permitindo representar graficamente as coordenadas e também inserir pontos utilizando cliques na interface.

---

## 🎯 Objetivo

O projeto tem como objetivo praticar conceitos fundamentais de **Estruturas de Dados e Programação Orientada a Objetos em C++**, aplicados a um sistema de gerenciamento espacial.

Entre os principais conceitos trabalhados estão:

* 📋 Listas;
* 📚 Pilhas;
* 🚶 Filas;
* 📐 Coordenadas cartesianas;
* 🧮 Cálculo de distância;
* 📍 Busca do ponto mais próximo;
* 📊 Centroide regional;
* ⭕ Geração de pontos em uma circunferência;
* 📁 Leitura de coordenadas a partir de arquivos;
* 🖱️ Interação gráfica com OpenCV;
* 🧱 Classes e encapsulamento;
* 🗂️ Separação entre arquivos `.h` e `.cpp`.

---

# 🧠 Estrutura do sistema

O programa possui três estruturas principais:

```text
                    ┌─────────────────────┐
                    │  GERENCIADOR        │
                    │     ESPACIAL        │
                    └──────────┬──────────┘
                               │
             ┌─────────────────┼─────────────────┐
             │                 │                 │
             ▼                 ▼                 ▼
      ┌────────────┐    ┌────────────┐    ┌────────────┐
      │    Lista   │    │   Pilha    │    │    Fila    │
      │   Geral    │    │   (LIFO)   │    │   (FIFO)   │
      └────────────┘    └────────────┘    └────────────┘
             │                 │                 │
             └─────────────────┼─────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Pontos (X, Y)       │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │     OpenCV           │
                    │ Visualização gráfica │
                    └─────────────────────┘
```

O menu principal do programa disponibiliza os módulos de **Lista de Coordenadas, Pilha e Fila**.

---

# 📋 Lista de Coordenadas

A estrutura de lista representa o conjunto geral de pontos armazenados no sistema.

É possível adicionar coordenadas de diferentes maneiras:

* No início;
* No final;
* Em um índice específico;
* A partir de arquivo;
* Como centroide regional próximo;
* Por meio da geração de uma circunferência.

Também é possível remover pontos:

* Primeiro elemento;
* Último elemento;
* Por índice;
* Ponto mais próximo de uma coordenada informada.

### Exemplo conceitual

```text
Lista:

[1] → (10, 20)
[2] → (15, 30)
[3] → (25, 40)
[4] → (50, 60)
```

É possível inserir ou remover elementos preservando a ordem da estrutura.

---

# 📚 Pilha — LIFO

O projeto implementa uma **pilha (Stack)** seguindo o princípio:

> **LIFO — Last In, First Out**

Ou seja:

```text
Último elemento inserido
          ↓
       primeiro
       a sair
```

### Operações

**Push**

Adiciona um ponto ao final da estrutura.

```text
Antes:

A → B → C

Push(D)

Depois:

A → B → C → D
```

**Pop**

Remove o último elemento.

```text
Antes:

A → B → C → D

Pop()

Depois:

A → B → C
```

No projeto, o `push` utiliza a inserção no final e o `pop` utiliza `pop_back()`.

---

# 🚶 Fila — FIFO

O projeto também implementa uma **fila (Queue)** seguindo o princípio:

> **FIFO — First In, First Out**

Ou seja:

```text
Primeiro elemento inserido
          ↓
       primeiro
       a sair
```

### Operações

**Enqueue**

Adiciona um ponto no final:

```text
A → B → C

Enqueue(D)

A → B → C → D
```

**Dequeue**

Remove o primeiro elemento:

```text
A → B → C → D

Dequeue()

B → C → D
```

A implementação utiliza a inserção no final da estrutura e a remoção do primeiro elemento.

---

# 📐 Gerenciamento de coordenadas

Cada ponto é representado por duas coordenadas:

```text
P = (X, Y)
```

A classe `ponto` encapsula essas informações.

Ela possui operações para:

* Criar um ponto;
* Alterar `X` e `Y`;
* Consultar `X`;
* Consultar `Y`.

A implementação da classe está separada em `ponto.h` e `ponto.cpp`.

---

# 📍 Busca do ponto mais próximo

O sistema possui uma função para encontrar o ponto mais próximo de uma coordenada de referência.

Para isso, é calculada a distância entre os pontos utilizando a distância euclidiana ao quadrado:

```text
d² = (x₂ - x₁)² + (y₂ - y₁)²
```

O programa compara as distâncias e retorna o índice do ponto com menor distância.

Essa funcionalidade é utilizada, por exemplo, para:

* Encontrar o ponto mais próximo;
* Remover o ponto mais próximo;
* Trabalhar com o centroide regional.

---

# 🎯 Centroide regional

O sistema também possui uma operação para calcular um **centroide regional** próximo de uma coordenada informada.

O algoritmo:

1. Localiza o ponto mais próximo da coordenada de referência;
2. Determina uma região de proximidade;
3. Seleciona os pontos que estão dentro dessa região;
4. Soma suas coordenadas `X` e `Y`;
5. Calcula a média das coordenadas;
6. Cria um novo ponto representando o centroide.

Matematicamente:

```text
Cx = ΣXi / n

Cy = ΣYi / n
```

O centroide calculado é então adicionado à estrutura espacial, desde que não seja um ponto duplicado.

---

# ⭕ Geração de circunferência

O sistema permite gerar automaticamente vários pontos distribuídos ao redor de uma circunferência.

São informados:

```text
Centro:
(Xc, Yc)

Raio:
r

Quantidade de pontos:
n
```

Os pontos são calculados aproximadamente por:

```text
X = Xc + cos(θ) × r

Y = Yc + sin(θ) × r
```

O ângulo é incrementado de acordo com a quantidade de pontos desejada.

Isso permite gerar uma representação discreta de uma circunferência utilizando pontos no plano cartesiano.

---

# 🖱️ Interface gráfica com OpenCV

Uma das principais características do projeto é a integração com **OpenCV** para visualização espacial.

Os pontos são renderizados em uma janela de aproximadamente:

```text
800 × 800 pixels
```

O sistema utiliza uma escala para converter coordenadas cartesianas em coordenadas da imagem.

Além disso, o usuário pode selecionar uma coordenada diretamente clicando na janela gráfica.

### Fluxo de interação

```text
Usuário
   │
   ├── Digita X e Y
   │
   └── Clica na interface
             │
             ▼
       Coordenada (X,Y)
             │
             ▼
       Estrutura espacial
             │
             ▼
       Renderização OpenCV
```

---

# 📁 Importação de arquivos

O programa permite carregar pontos armazenados em arquivos `.txt`.

Atualmente são disponibilizados:

```text
pontos1.txt
pontos2.txt
```

O formato esperado para cada coordenada é:

```text
X - Y
```

Por exemplo:

```text
10 - 20
15 - 30
25 - 40
50 - 60
```

Durante a importação, o sistema verifica se o ponto já existe para evitar duplicidades.

---

# 🚫 Controle de pontos duplicados

O sistema impede que duas coordenadas exatamente iguais sejam adicionadas.

Por exemplo:

```text
(10, 20)
```

já existente na estrutura impede a inserção de outro:

```text
(10, 20)
```

Essa verificação é realizada antes das operações de inserção.

---

# 🏗️ Organização do código

O projeto utiliza separação entre **interface, implementação e estrutura de dados**.

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

A branch `cmaismais` atualmente contém esses arquivos e também configurações do VS Code para o ambiente C++/OpenCV.

---

# 📄 Responsabilidade dos arquivos

| Arquivo                    | Responsabilidade                               |
| -------------------------- | ---------------------------------------------- |
| `main.cpp`                 | Ponto de entrada da aplicação                  |
| `lista.h`                  | Declaração da classe de gerenciamento da lista |
| `lista.cpp`                | Implementação das operações sobre os pontos    |
| `ponto.h`                  | Declaração da classe `ponto`                   |
| `ponto.cpp`                | Implementação da classe `ponto`                |
| `menu.h`                   | Declaração das funções de menu                 |
| `menu.cpp`                 | Implementação da interface textual             |
| `pontos1.txt`              | Conjunto de coordenadas para importação        |
| `pontos2.txt`              | Segundo conjunto de coordenadas                |
| `.vscode/`                 | Configurações do ambiente de desenvolvimento   |
| `gerenciador_espacial.exe` | Executável compilado                           |

---

# 🧱 Arquitetura simplificada

O relacionamento entre as principais classes pode ser representado como:

```text
              ┌─────────────────┐
              │      main       │
              └────────┬────────┘
                       │
                       ▼
              ┌─────────────────┐
              │      menu       │
              └────────┬────────┘
                       │
                       ▼
              ┌─────────────────┐
              │      lista      │
              └────────┬────────┘
                       │
                       │ possui
                       ▼
              ┌─────────────────┐
              │      ponto      │
              ├─────────────────┤
              │      varx       │
              │      vary       │
              └─────────────────┘
                       │
                       ▼
                  ┌─────────┐
                  │ OpenCV  │
                  └─────────┘
```

---

# 🛠️ Tecnologias utilizadas

| Tecnologia             | Utilização                                |
| ---------------------- | ----------------------------------------- |
| **C++**                | Desenvolvimento principal                 |
| **C++20**              | Padrão utilizado na compilação            |
| **G++**                | Compilação                                |
| **GDB**                | Debugging                                 |
| **OpenCV**             | Interface gráfica e visualização espacial |
| **MSYS2 UCRT64**       | Ambiente de desenvolvimento               |
| **Visual Studio Code** | IDE/editor                                |

A configuração do projeto utiliza `g++`, padrão **C++20** e bibliotecas OpenCV como `opencv_core`, `opencv_imgproc`, `opencv_highgui` e `opencv_videoio`.

---

# ⚙️ Configuração do ambiente

## 1. Instalar o MSYS2

Instale o MSYS2 e utilize o terminal:

```text
MSYS2 UCRT64
```

O projeto foi configurado especificamente para esse ambiente.

---

## 2. Atualizar o sistema

No terminal UCRT64:

```bash
pacman -Syu
```

---

## 3. Instalar compilador e OpenCV

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-opencv
```

Esses pacotes fornecem o compilador, debugger e bibliotecas OpenCV utilizados pelo projeto.

---

# 🔧 Configuração do PATH

Adicione ao `PATH` do Windows:

```text
C:\msys64\ucrt64\bin
```

Isso permite que o Windows encontre as DLLs necessárias durante a execução do programa.

---

# 📥 Clonando o projeto

Clone o repositório:

```bash
git clone https://github.com/Cvtr-C/LP.git
```

Depois entre na branch:

```bash
cd LP
git checkout cmaismais
```

---

# 🔨 Compilação

O projeto possui uma configuração de build no `.vscode/tasks.json`.

A compilação utiliza:

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

A configuração também está disponível no próprio projeto.

---

# ▶️ Execução

Após a compilação:

```bash
./gerenciador_espacial.exe
```

No VS Code, também é possível utilizar:

```text
Ctrl + Shift + B
```

para executar a tarefa de build configurada no workspace.

---

# 🖥️ Menu principal

Ao iniciar o programa, o usuário encontra:

```text
================================
       GERENCIADOR ESPACIAL
================================

[1] - Lista de Coordenadas (Geral)
[2] - Pilha (LIFO)
[3] - Fila (FIFO)
[4] - Sair do Sistema
```

Cada opção direciona para um módulo específico da aplicação.

---

# 📚 Conceitos de Estruturas de Dados

O projeto demonstra na prática três estruturas clássicas:

### Lista

```text
Inserção:
Início
Fim
Índice

Remoção:
Início
Fim
Índice
Por proximidade
```

### Pilha

```text
Push  → adiciona no final
Pop   → remove do final
```

### Fila

```text
Enqueue → adiciona no final
Dequeue → remove do início
```

Essas operações são implementadas utilizando `std::vector` como estrutura de armazenamento subjacente.

---

# 📐 Conceitos matemáticos

Além de estruturas de dados, o projeto aplica conceitos de geometria computacional:

* Distância euclidiana;
* Coordenadas cartesianas;
* Média de coordenadas;
* Centroide;
* Circunferência;
* Funções trigonométricas;
* Transformação de coordenadas para visualização.

---

# 🎓 Objetivos acadêmicos

O projeto serve como prática para conceitos importantes de **Programação Orientada a Objetos e Estruturas de Dados**, incluindo:

```text
C++
 │
 ├── Classes
 │
 ├── Encapsulamento
 │
 ├── Construtores
 │
 ├── Destrutores
 │
 ├── Métodos
 │
 ├── Arquivos .h / .cpp
 │
 ├── std::vector
 │
 ├── Listas
 │
 ├── Pilhas
 │
 ├── Filas
 │
 ├── Manipulação de arquivos
 │
 └── OpenCV
```

---

# 🚀 Possíveis evoluções

Algumas melhorias que podem ser incorporadas futuramente:

* [ ] Implementar persistência automática dos pontos;
* [ ] Adicionar exportação para `.txt` ou `.csv`;
* [ ] Melhorar a interface gráfica;
* [ ] Permitir zoom e deslocamento do plano;
* [ ] Diferenciar visualmente pontos normais e centroides;
* [ ] Implementar seleção de pontos diretamente na janela;
* [ ] Adicionar cálculo de distância entre dois pontos selecionados;
* [ ] Adicionar busca por região;
* [ ] Utilizar `std::deque` para representar a fila;
* [ ] Utilizar uma implementação própria de lista encadeada;
* [ ] Criar testes automatizados;
* [ ] Separar melhor a camada de interface da lógica de negócio.

---

# 👨‍💻 Autor

**Carlos Vitor Taleires Rodrigues**

GitHub:

https://github.com/Cvtr-C

---

## 📄 Licença

Projeto desenvolvido para fins **acadêmicos e educacionais**.

---

⭐ Se este projeto foi útil para seus estudos, considere deixar uma estrela no repositório!

4. Execute o arquivo gerado no terminal integrado:
   ```bash
   ./gerenciador_espacial.exe
   ```
