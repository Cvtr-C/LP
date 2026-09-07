# 💻 Linguagem de Programação — C

Repositório destinado ao armazenamento e organização das atividades, exercícios e práticas desenvolvidas durante os estudos de **Linguagem de Programação**, utilizando a linguagem **C**.

O projeto reúne diferentes conceitos fundamentais de programação, incluindo operações matemáticas, estruturas de repetição e decisão, vetores, matrizes, funções, manipulação de arquivos e modularização de código.

---

## 📚 Conteúdos

O repositório está organizado em diferentes diretórios, cada um abordando um conjunto de conceitos da linguagem C:

```text
LP/
├── Arquivo/
├── Calculador/
├── Matriz/
├── Vetores/
└── README.md
```

---

## 📁 Organização do projeto

### 📄 Arquivo

Diretório dedicado a exercícios envolvendo **manipulação de arquivos em C**.

Os programas utilizam `FILE`, `fopen()`, `fscanf()` e `fclose()` para realizar a leitura de dados armazenados em arquivos de texto.

Entre os exercícios estão:

* Leitura de números a partir de arquivos;
* Verificação de números primos;
* Cálculo de fatorial;
* Operações com números;
* Classificação de triângulos a partir dos lados.

Os arquivos de entrada utilizados pelos programas também estão presentes no diretório:

```text
Arquivo/
├── Parte1.c
├── Parte2.c
├── parte1.txt
└── parte2.txt
```

---

### 🧮 Calculador

Conjunto de programas que implementam uma **calculadora em C**, explorando diferentes formas de organização do código.

A implementação principal apresenta um menu interativo com operações como:

* ➕ Soma;
* ➖ Subtração;
* ✖️ Multiplicação;
* ➗ Divisão;
* `n!` Fatorial;
* `cos(x)` em radianos;
* `cos(x)` em graus;
* Soma dos dígitos de um número;
* √ Raiz quadrada.

A versão principal utiliza uma estrutura `switch` para selecionar a operação desejada.

O diretório possui diferentes versões do exercício:

```text
Calculador/
├── Junto/
│   └── mainn.c
│
├── Junto_func/
│   └── Calcula.c
│
└── Separado/
    ├── Main.c
    ├── calc.c
    └── calc.h
```

A organização em `Junto_func` e `Separado` permite trabalhar também com a separação entre implementação, funções e arquivos de cabeçalho.

---

### 🔢 Matriz

Exercício envolvendo **matrizes bidimensionais** em C.

O programa trabalha com uma matriz de:

```text
3 × 10
```

ou seja, três notas para dez alunos.

O programa permite inserir os valores, exibir a matriz e realizar cálculos relacionados às notas, incluindo operações de média e identificação de maiores e menores valores.

Estrutura:

```text
Matriz/
└── Matriz.c
```

---

### 📊 Vetores

Diretório dedicado ao estudo de **vetores e funções auxiliares**.

O programa utiliza um vetor com 10 posições e realiza operações como:

* Identificação do maior valor;
* Identificação do menor valor;
* Cálculo da média;
* Cálculo do desvio padrão;
* Verificação de números primos;
* Soma dos dígitos dos números.

O projeto utiliza arquivos `.c` e `.h` para separar funcionalidades:

```text
Vetores/
├── veto.c
├── veto.h
└── vetor.c
```

O arquivo `veto.c` contém funções auxiliares para cálculo de raiz quadrada, verificação de números primos e soma dos dígitos.

---

## 🧠 Conceitos praticados

Ao longo dos exercícios presentes neste repositório são trabalhados diversos fundamentos da linguagem C:

### Estruturas básicas

* Variáveis;
* Tipos de dados;
* Entrada e saída com `scanf()` e `printf()`;
* Operadores aritméticos;
* Operadores relacionais;
* Operadores lógicos.

### Controle de fluxo

* `if`;
* `else`;
* `while`;
* `for`;
* `switch`;
* `break`.

### Estruturas de dados

* Vetores;
* Matrizes;
* Strings e dados armazenados em arquivos.

### Funções

* Declaração de funções;
* Parâmetros;
* Retorno de valores;
* Organização de funções em arquivos separados.

### Modularização

O projeto também apresenta exemplos utilizando arquivos de cabeçalho `.h` e arquivos de implementação `.c`, permitindo separar diferentes responsabilidades do programa.

### Manipulação de arquivos

São utilizados recursos da biblioteca padrão de C para:

```c
FILE *
fopen()
fscanf()
fclose()
```

permitindo que os programas leiam informações armazenadas externamente.

---

## ⚙️ Tecnologias utilizadas

| Tecnologia | Utilização                         |
| ---------- | ---------------------------------- |
| **C**      | Linguagem principal dos exercícios |
| **GCC**    | Compilação dos programas           |
| **Git**    | Controle de versão                 |
| **GitHub** | Hospedagem do código               |

---

## 🚀 Como executar

### 1. Clone o repositório

```bash
git clone https://github.com/Cvtr-C/LP.git
```

O comando `git clone` cria uma cópia local do repositório para que os arquivos possam ser compilados e modificados localmente.

### 2. Entre no diretório

```bash
cd LP
```

### 3. Compile um dos programas

Por exemplo:

```bash
gcc Matriz/Matriz.c -o matriz
```

### 4. Execute

No Linux:

```bash
./matriz
```

No Windows:

```bash
matriz.exe
```

---

## 🧪 Exemplo

Para compilar o programa de vetores:

```bash
gcc Vetores/vetor.c Vetores/veto.c -o vetor
```

Depois:

```bash
./vetor
```

O programa solicitará os valores do vetor e realizará os cálculos implementados.

---

## 🎯 Objetivo

Este repositório tem como objetivo registrar a evolução prática no aprendizado da linguagem **C**, servindo como material de estudo e consulta para conceitos fundamentais de programação.

Os exercícios são utilizados para praticar principalmente:

```text
Lógica de programação
       ↓
Estruturas de controle
       ↓
Vetores e matrizes
       ↓
Funções
       ↓
Modularização
       ↓
Manipulação de arquivos
```

---

## 📈 Evolução

O projeto acompanha diferentes etapas do aprendizado de programação em C, partindo de programas mais simples e avançando para exercícios que utilizam:

* Organização em múltiplos arquivos;
* Funções reutilizáveis;
* Arquivos de cabeçalho;
* Manipulação de arquivos;
* Estruturas de dados;
* Operações matemáticas;
* Cálculos estatísticos básicos.

---

## 👨‍💻 Autor

**Carlos Vitor Taleires Rodrigues**

GitHub:
https://github.com/Cvtr-C

---

## 📄 Licença

Este repositório é destinado principalmente a fins **educacionais e acadêmicos**.

---

⭐ Se este repositório for útil para seus estudos, considere deixar uma estrela no projeto!
