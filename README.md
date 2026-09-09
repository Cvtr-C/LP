# 🗺️ Gerenciador Espacial

Sistema de gerenciamento de pontos em um plano cartesiano desenvolvido em **C++**, utilizando **estruturas de dados**, **programação orientada a objetos** e **OpenCV** para interação gráfica.

O projeto permite cadastrar, remover, consultar e manipular pontos `(x, y)` por meio de uma interface de terminal, além de possibilitar a inserção de coordenadas utilizando o **mouse em um plano cartesiano renderizado com OpenCV**.

---

## 📌 Sobre o projeto

O **Gerenciador Espacial** foi desenvolvido como um projeto acadêmico para aplicação prática de conceitos fundamentais de programação e estruturas de dados.

O sistema trabalha com pontos bidimensionais e disponibiliza diferentes estruturas para armazená-los e manipulá-los:

* 📋 Lista
* 📚 Pilha
* 🚶 Fila
* 📐 Plano cartesiano
* 🖱️ Interação gráfica com mouse
* ⌨️ Entrada de coordenadas pelo teclado

Além das operações tradicionais de estruturas de dados, o projeto possui uma representação gráfica dos pontos utilizando o **OpenCV**.

---

# 🎯 Objetivos

O projeto tem como principais objetivos:

1. Aplicar conceitos de **C++**.
2. Utilizar **Programação Orientada a Objetos (POO)**.
3. Trabalhar com estruturas de dados lineares.
4. Implementar operações de inserção e remoção.
5. Trabalhar com índices e posições em estruturas de dados.
6. Representar matematicamente pontos no plano cartesiano.
7. Converter coordenadas cartesianas para coordenadas de tela.
8. Utilizar eventos do mouse com OpenCV.
9. Implementar interação entre terminal e interface gráfica.
10. Praticar organização de código em múltiplos arquivos `.cpp` e `.h`.

---

# ✨ Funcionalidades

## 📍 Gerenciamento de pontos

O sistema permite trabalhar com pontos bidimensionais representados por:

```text
(x, y)
```

Exemplo:

```text
(10, 5)
(-3, 8)
(0, 0)
(-1, -1)
```

Coordenadas negativas são permitidas.

---

## 📋 Lista

A estrutura de lista permite realizar operações como:

* ➕ Inserção no início
* ➕ Inserção no final
* ➕ Inserção em posição específica
* ❌ Remoção de elementos
* 🔎 Busca
* 📄 Exibição dos elementos
* 📏 Consulta de tamanho
* 🔍 Localização do ponto mais próximo
* 🚫 Verificação de duplicidade

A implementação utiliza `std::vector` como estrutura de armazenamento.

---

## 📚 Pilha

A pilha segue o princípio:

> **LIFO — Last In, First Out**

Ou seja, o último elemento inserido é o primeiro a ser removido.

Exemplo:

```text
Inserção:

A
B
C

Topo → C

Remoção:

C
B
A
```

---

## 🚶 Fila

A fila segue o princípio:

> **FIFO — First In, First Out**

Ou seja, o primeiro elemento inserido é o primeiro a ser removido.

Exemplo:

```text
Entrada:

A → B → C

Saída:

A
B
C
```

---

# 🖥️ Interface gráfica

O projeto utiliza a biblioteca **OpenCV** para criar uma representação visual do plano cartesiano.

A interface gráfica apresenta:

* Eixo X
* Eixo Y
* Origem `(0,0)`
* Pontos armazenados
* Coordenadas dos pontos
* Escala do plano
* Interação através do mouse

---

# 🖱️ Inserção de pontos pelo mouse

O usuário pode escolher entre dois métodos para informar uma coordenada:

```text
[1] Digitar (Teclado)
[2] Clicar (Interface Gráfica)
```

### ⌨️ Teclado

O programa solicita:

```text
[+] Informe X:
[+] Informe Y:
```

Por exemplo:

```text
X = -5
Y = 8
```

Resultando no ponto:

```text
(-5, 8)
```

### 🖱️ Mouse

O usuário pode clicar diretamente no plano cartesiano.

O programa converte a posição em pixels do monitor para uma coordenada cartesiana.

---

# 📐 Sistema de coordenadas

A interface gráfica trabalha com dois sistemas de coordenadas diferentes.

## Coordenadas cartesianas

São as coordenadas matemáticas utilizadas pelo programa:

```text
        Y
        ↑
        |
        |
--------+--------→ X
        |
        |
```

Por exemplo:

```text
P = (5, 3)
```

---

## Coordenadas da tela

O OpenCV utiliza coordenadas baseadas em pixels.

A origem da tela está localizada no canto superior esquerdo:

```text
(0,0) ─────────────→ X
  |
  |
  |
  ↓
  Y
```

Portanto, o eixo Y cresce para baixo.

Isso é diferente do sistema cartesiano tradicional.

---

# 🔄 Conversão entre coordenadas

Para permitir a interação entre o plano cartesiano e a tela, o projeto realiza uma transformação matemática.

Considerando:

```text
centroX = posição horizontal da origem
centroY = posição vertical da origem
fatorEscala = quantidade de pixels por unidade
```

A transformação de coordenadas cartesianas para pixels é:

```text
pixelX = centroX + x × fatorEscala
pixelY = centroY - y × fatorEscala
```

O sinal negativo no eixo Y é necessário porque:

* no plano cartesiano, Y positivo aponta para cima;
* na tela, Y positivo aponta para baixo.

---

## 🔄 Conversão inversa

Quando o usuário clica na tela, o programa precisa descobrir qual coordenada cartesiana corresponde ao pixel clicado.

A transformação inversa é:

```text
x = (pixelX - centroX) / fatorEscala
y = (centroY - pixelY) / fatorEscala
```

Essa transformação permite que um clique na interface seja convertido em um ponto matemático.

---

# 🎯 Exemplo de transformação

Considere:

```text
centroX = 500
centroY = 500
fatorEscala = 40
```

Para o ponto:

```text
(3, 2)
```

temos:

```text
pixelX = 500 + 3 × 40
pixelX = 620
```

e:

```text
pixelY = 500 - 2 × 40
pixelY = 420
```

Portanto:

```text
(3,2) → (620,420)
```

na tela.

---

# ⛔ Cancelamento da operação gráfica

A operação de seleção gráfica pode ser cancelada pressionando:

```text
ESC
```

O sistema utiliza o retorno booleano da função para diferenciar:

```text
true  → coordenada obtida com sucesso
false → operação cancelada
```

Isso evita utilizar valores de coordenadas como indicadores de erro.

Por exemplo:

```text
(-1,-1)
```

é uma coordenada perfeitamente válida.

Portanto, o programa **não utiliza `-1` como marcador de coordenada inválida**.

---

# 🔢 Índices e valores sentinela

É importante diferenciar **coordenadas** de **índices**.

Uma coordenada pode ser:

```text
(-1,-1)
```

sem nenhum problema.

Já um índice de um `vector` normalmente começa em:

```text
0
```

Assim, uma função que procura um elemento pode utilizar:

```text
-1
```

para indicar que nenhum índice válido foi encontrado.

Por exemplo:

```cpp
int indice = encontrarMaisProximo(x, y);

if (indice == -1)
{
    // Nenhum ponto encontrado
}
```

Nesse caso, `-1` representa um **índice inválido**, e não uma coordenada.

---

# 🏗️ Estrutura do projeto

A organização dos arquivos segue uma separação de responsabilidades:

```text
Gerenciador Espacial
│
├── main.cpp
├── menu.cpp
├── menu.h
├── lista.cpp
├── lista.h
├── ponto.cpp
├── ponto.h
└── README.md
```

---

# 📂 Responsabilidade dos arquivos

## `main.cpp`

É o ponto de entrada da aplicação.

Responsável por iniciar o programa e controlar o fluxo principal.

---

## `ponto.h`

Define a classe responsável pela representação de um ponto.

Um ponto possui:

```text
x
y
```

---

## `ponto.cpp`

Contém a implementação dos métodos da classe `ponto`.

---

## `lista.h`

Declara a classe responsável pelo gerenciamento dos pontos.

Também contém as declarações das operações realizadas sobre a estrutura.

---

## `lista.cpp`

Implementa as operações da lista e funcionalidades relacionadas ao plano cartesiano e OpenCV.

Entre elas estão operações envolvendo:

* inserção;
* remoção;
* busca;
* ordenação;
* pontos;
* duplicidade;
* ponto mais próximo;
* renderização;
* interação gráfica.

---

## `menu.h`

Contém as declarações relacionadas aos menus e funções auxiliares de interação com o usuário.

---

## `menu.cpp`

Implementa os menus do sistema e a interação entre o usuário e as estruturas de dados.

Também contém funções auxiliares para leitura de dados e obtenção de coordenadas.

---

# 🧱 Arquitetura simplificada

O fluxo geral da aplicação pode ser representado como:

```text
                    ┌───────────────┐
                    │    main.cpp   │
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │   menu.cpp    │
                    └───────┬───────┘
                            │
             ┌──────────────┼──────────────┐
             │              │              │
             ▼              ▼              ▼
        ┌─────────┐    ┌─────────┐    ┌─────────┐
        │  Lista  │    │  Pilha  │    │  Fila   │
        └────┬────┘    └────┬────┘    └────┬────┘
             │              │              │
             └──────────────┼──────────────┘
                            ▼
                       ┌─────────┐
                       │  ponto  │
                       └─────────┘
                            │
                            ▼
                       ┌─────────┐
                       │ OpenCV  │
                       └─────────┘
```

---

# 🧠 Conceitos utilizados

O projeto aplica diversos conceitos importantes de programação.

## C++

* Classes
* Objetos
* Métodos
* Encapsulamento
* Referências
* Funções
* `const`
* `std::vector`
* Iteradores
* Condicionais
* Loops
* Ponteiros/referências quando necessários
* Separação entre `.h` e `.cpp`
* Compilação e linking

---

# 🧩 Programação Orientada a Objetos

O projeto utiliza classes para representar entidades e responsabilidades.

Por exemplo:

```cpp
ponto
```

representa um ponto no espaço.

Enquanto:

```cpp
lista
```

é responsável pelo gerenciamento dos pontos.

Essa separação permite organizar melhor o código e reduzir o acoplamento entre componentes.

---

# 📦 Estrutura de dados

A estrutura principal de armazenamento utiliza:

```cpp
std::vector
```

O `vector` fornece acesso por índice e permite operações eficientes de acesso aos elementos.

Exemplo conceitual:

```text
vector

[0] → ponto
[1] → ponto
[2] → ponto
[3] → ponto
```

---

# 🔍 Busca pelo ponto mais próximo

O sistema possui uma operação para encontrar o ponto mais próximo de uma coordenada fornecida.

Conceitualmente, para um ponto de consulta:

```text
Q = (x,y)
```

e um ponto armazenado:

```text
P = (px,py)
```

a distância euclidiana é:

$$
d(P,Q)=\sqrt{(px-x)^2+(py-y)^2}
$$

O ponto com a menor distância é considerado o mais próximo.

Para comparação, não é necessário calcular necessariamente a raiz quadrada.

Podemos comparar:

$$
d^2=(px-x)^2+(py-y)^2
$$

Isso evita a operação de raiz quadrada e preserva a ordem das distâncias.

---

# 🚫 Controle de pontos duplicados

O projeto também verifica se uma coordenada já está presente antes de adicionar determinados pontos.

Dois pontos são considerados iguais quando:

```text
x1 = x2
e
y1 = y2
```

Por exemplo:

```text
(5,10)
(5,10)
```

representam o mesmo ponto.

Enquanto:

```text
(5,10)
(5,11)
```

são pontos diferentes.

---

# 📚 Estruturas implementadas

| Estrutura | Princípio            | Característica                     |
| --------- | -------------------- | ---------------------------------- |
| Lista     | Sequencial           | Permite inserções e remoções       |
| Pilha     | LIFO                 | Último a entrar, primeiro a sair   |
| Fila      | FIFO                 | Primeiro a entrar, primeiro a sair |
| Ponto     | Abstração geométrica | Representa `(x,y)`                 |

---

# 🛠️ Tecnologias utilizadas

* **C++**
* **OpenCV**
* **GCC**
* **MSYS2**
* **UCRT64**
* **Git**
* **GitHub**

---

# 💻 Requisitos

Para compilar o projeto no Windows, é necessário possuir:

### Compilador

```text
G++
```

### Ambiente

```text
MSYS2 UCRT64
```

### Biblioteca

```text
OpenCV 4
```

O projeto considera a instalação do OpenCV nos seguintes diretórios:

```text
C:/msys64/ucrt64/include/opencv4
C:/msys64/ucrt64/lib
```

---

# 🚀 Compilação

Abra o terminal **MSYS2 UCRT64** na pasta do projeto.

Execute:

```bash
g++ main.cpp lista.cpp menu.cpp ponto.cpp -o gerenciador_espacial.exe -IC:/msys64/ucrt64/include/opencv4 -LC:/msys64/ucrt64/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio
```

Se a compilação for concluída sem erros, será gerado:

```text
gerenciador_espacial.exe
```

---

# ▶️ Execução

Após compilar:

```bash
./gerenciador_espacial.exe
```

O programa será iniciado no terminal.

---

# ⚙️ Explicação do comando de compilação

O comando utilizado é:

```bash
g++ main.cpp lista.cpp menu.cpp ponto.cpp -o gerenciador_espacial.exe -IC:/msys64/ucrt64/include/opencv4 -LC:/msys64/ucrt64/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio
```

Cada parte possui uma função específica.

### `g++`

Invoca o compilador C++.

---

### Arquivos `.cpp`

```text
main.cpp
lista.cpp
menu.cpp
ponto.cpp
```

São compilados juntos para formar o programa final.

---

### `-o`

Define o nome do arquivo executável:

```bash
-o gerenciador_espacial.exe
```

---

### `-I`

Define onde o compilador deve procurar os arquivos de cabeçalho:

```bash
-I C:/msys64/ucrt64/include/opencv4
```

Isso permite encontrar:

```cpp
#include <opencv2/opencv.hpp>
```

---

### `-L`

Define onde o linker deve procurar as bibliotecas:

```bash
-L C:/msys64/ucrt64/lib
```

---

### Bibliotecas OpenCV

O projeto utiliza:

```text
-lopencv_core
-lopencv_imgproc
-lopencv_highgui
-lopencv_imgcodecs
-lopencv_videoio
```

#### `opencv_core`

Funcionalidades fundamentais do OpenCV.

#### `opencv_imgproc`

Processamento de imagens.

#### `opencv_highgui`

Criação de janelas e interação com eventos.

#### `opencv_imgcodecs`

Leitura e gravação de imagens.

#### `opencv_videoio`

Entrada e saída de vídeo.

---

# 🧪 Exemplo de execução

Ao iniciar o programa, o usuário encontra o menu principal.

O fluxo geral pode ser semelhante a:

```text
================================
      GERENCIADOR ESPACIAL
================================

[1] Lista
[2] Pilha
[3] Fila
[0] Sair

[>] Escolha uma opção:
```

Ao realizar uma operação que necessita de coordenadas:

```text
[1] Digitar (Teclado)
[2] Clicar (Interface Grafica)

[>] Escolha o metodo:
```

---

# 🖱️ Interação gráfica

Quando o modo gráfico é selecionado, o programa abre uma janela do plano cartesiano.

O usuário pode selecionar uma coordenada utilizando o mouse.

Para cancelar a operação:

```text
ESC
```

---

# 🔄 Fluxo de obtenção de coordenadas

A função responsável por obter coordenadas pode trabalhar com dois métodos:

```text
              obterCoordenadas()
                       │
             ┌─────────┴─────────┐
             │                   │
             ▼                   ▼
          Teclado              Mouse
             │                   │
             ▼                   ▼
          Ler X/Y         OpenCV + clique
             │                   │
             └─────────┬─────────┘
                       ▼
                  Coordenada
                    (x,y)
```

A função retorna:

```text
true
```

quando uma coordenada foi obtida com sucesso.

E:

```text
false
```

quando a operação foi cancelada ou não pôde ser concluída.

---

# 🧹 Boas práticas aplicadas

O projeto busca aplicar boas práticas como:

* Separação entre interface e lógica;
* Organização em arquivos `.h` e `.cpp`;
* Uso de classes;
* Uso de referências quando apropriado;
* Validação de entrada;
* Separação entre coordenadas e índices;
* Uso de valores booleanos para representar estados de operação;
* Evitar valores sentinela ambíguos para coordenadas;
* Organização das estruturas de dados.

---

# ⚠️ Possíveis problemas de compilação

## OpenCV não encontrado

Caso apareça:

```text
fatal error: opencv2/opencv.hpp: No such file or directory
```

verifique se o diretório existe:

```text
C:/msys64/ucrt64/include/opencv4
```

e se o comando contém:

```bash
-I C:/msys64/ucrt64/include/opencv4
```

---

## Erro no linker

Caso apareça algo como:

```text
undefined reference to ...
```

pode existir algum problema relacionado às bibliotecas utilizadas no linking.

Verifique:

```text
C:/msys64/ucrt64/lib
```

e confirme se as bibliotecas do OpenCV estão instaladas.

---

# 🐛 Tratamento de erros

O programa possui mecanismos para tratar situações como:

* Entrada inválida;
* Operações canceladas;
* Estruturas vazias;
* Índices inválidos;
* Pontos inexistentes;
* Tentativa de operações incompatíveis com o estado atual da estrutura.

Um exemplo importante é a utilização de:

```cpp
-1
```

como retorno de uma busca de índice.

Nesse contexto:

```text
-1 = nenhum índice válido encontrado
```

Isso é diferente de uma coordenada:

```text
x = -1
y = -1
```

que continua sendo válida.

---

# 📈 Possíveis melhorias futuras

O projeto pode evoluir posteriormente com funcionalidades como:

* [ ] Salvar pontos em arquivos;
* [ ] Carregar pontos de arquivos;
* [ ] Exportar coordenadas;
* [ ] Zoom no plano cartesiano;
* [ ] Pan/arraste da câmera;
* [ ] Seleção visual de pontos;
* [ ] Exibição de distância entre pontos;
* [ ] Cálculo de distância entre todos os pontos;
* [ ] Cálculo de centroide;
* [ ] Cálculo de área de polígonos;
* [ ] Conexão entre pontos;
* [ ] Renderização de segmentos;
* [ ] Renderização de polígonos;
* [ ] Melhor tratamento de eventos do mouse;
* [ ] Separação completa entre camada gráfica e estrutura de dados;
* [ ] Sistema de testes automatizados;
* [ ] CMake para automatizar a compilação;
* [ ] Documentação automática com Doxygen.

---

# 🔬 Possíveis extensões matemáticas

Como o projeto trabalha com geometria computacional básica, ele pode posteriormente incorporar:

### Distância entre pontos

$$
d=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}
$$

### Ponto médio

$$
M=
\left(
\frac{x_1+x_2}{2},
\frac{y_1+y_2}{2}
\right)
$$

### Inclinação de uma reta

$$
m=\frac{y_2-y_1}{x_2-x_1}
$$

quando:

$$
x_2\neq x_1
$$

### Distância de um ponto até uma reta

Pode ser utilizada posteriormente para implementar funcionalidades geométricas mais avançadas.

---

# 🧑‍💻 Organização recomendada para desenvolvimento

Para contribuir com o projeto:

1. Faça uma alteração;
2. Compile o projeto;
3. Execute os testes manualmente;
4. Verifique as operações gráficas;
5. Verifique coordenadas negativas;
6. Verifique estruturas vazias;
7. Verifique índices inválidos;
8. Verifique cancelamento com `ESC`;
9. Faça o commit;
10. Envie para o GitHub.

---

# 🔀 Git

Para verificar o estado do projeto:

```bash
git status
```

Para adicionar alterações:

```bash
git add .
```

Para criar um commit:

```bash
git commit -m "Descrição da alteração"
```

Para enviar as alterações:

```bash
git push
```

---

# 📚 Conceitos acadêmicos envolvidos

Este projeto permite praticar conceitos presentes em disciplinas como:

* **Programação Orientada a Objetos**
* **Estrutura de Dados**
* **Algoritmos**
* **Geometria Analítica**
* **Programação em C++**
* **Computação Gráfica**
* **Processamento Digital de Imagens**
* **Engenharia de Software**

---

# 👨‍💻 Autor

**Cvtr-C**

Projeto desenvolvido para fins acadêmicos e de aprendizado em programação, estruturas de dados e desenvolvimento de aplicações em C++.

---

# 📄 Licença

Este projeto pode ser utilizado para fins educacionais.

Consulte o repositório para informações adicionais sobre a licença e condições de uso.

---

# ⭐ Considerações finais

O **Gerenciador Espacial** combina estruturas de dados clássicas com uma representação gráfica de pontos em um plano cartesiano.

A aplicação demonstra como conceitos matemáticos e computacionais podem ser integrados em uma única aplicação:

```text
              C++
               │
       ┌───────┴───────┐
       │               │
 Estruturas         Geometria
 de dados              │
       │               │
       └───────┬───────┘
               │
             OpenCV
               │
               ▼
       Interface gráfica
               │
               ▼
        Gerenciador
          Espacial
```

O projeto serve como base para evoluções futuras envolvendo **geometria computacional, visualização, algoritmos espaciais e processamento de imagens**.
