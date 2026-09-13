# Gerenciador Espacial

> Projeto acadêmico desenvolvido para a disciplina de **Programação Avançada**.

Aplicação desenvolvida em C++ para armazenar, organizar e visualizar pontos em um plano cartesiano. O projeto permite manipular as coordenadas como lista, pilha e fila, além de apresentar uma representação gráfica utilizando a biblioteca OpenCV.

## Funcionalidades

- Adição de pontos no início, no fim ou em uma posição específica;
- remoção do primeiro ponto, do último ponto ou de uma posição escolhida;
- remoção do ponto mais próximo de uma coordenada de referência;
- busca do ponto mais próximo por distância euclidiana;
- inserção do ponto médio do par consecutivo mais próximo;
- geração de pontos distribuídos em uma circunferência;
- importação de coordenadas a partir de arquivos de texto;
- prevenção de coordenadas duplicadas;
- operações de pilha no padrão LIFO;
- operações de fila no padrão FIFO;
- escolha de coordenadas pelo teclado ou por clique;
- visualização dos pontos em um plano cartesiano com escala automática.

## Tecnologias utilizadas

- C++17;
- biblioteca padrão do C++ (`std::vector`);
- OpenCV para interface gráfica e renderização;
- GCC/G++ fornecido pelo ambiente MSYS2 UCRT64;
- script Batch para compilação e execução no Windows.

## Estrutura do projeto

| Arquivo | Descrição |
| --- | --- |
| `main.cpp` | Inicia a aplicação e apresenta o menu principal. |
| `menu.cpp` / `menu.h` | Implementam os menus, a leitura de dados e as mensagens exibidas ao usuário. |
| `lista.cpp` / `lista.h` | Implementam o armazenamento e as operações realizadas sobre os pontos. |
| `ponto.cpp` / `ponto.h` | Definem a classe que representa uma coordenada `(x, y)`. |
| `pontos1.txt` / `pontos2.txt` | Contêm exemplos de coordenadas para importação. |
| `rodar.bat` | Compila todos os módulos e executa o programa. |

## Requisitos

O script `rodar.bat` foi configurado para um ambiente Windows com o MSYS2 instalado em `C:\msys64`.

No terminal UCRT64 do MSYS2, as dependências podem ser instaladas com:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-opencv
```

Caso o MSYS2 esteja instalado em outro diretório, ajuste os caminhos definidos em `rodar.bat`.

## Como executar

Clone o repositório:

```bash
git clone https://github.com/Cvtr-C/LP.git
cd LP
```

No Windows, execute `rodar.bat` com um clique duplo ou pelo terminal:

```bat
rodar.bat
```

O script realiza estas etapas automaticamente:

1. verifica se o compilador está instalado;
2. compila os arquivos `.cpp` com C++17;
3. vincula as bibliotecas necessárias do OpenCV;
4. gera o executável `gerenciador_espacial.exe`;
5. inicia o programa.

## Formato dos arquivos de pontos

Cada linha deve possuir duas coordenadas inteiras separadas por um hífen:

```text
30 - 25
10 - -5
-8 - 12
```

O primeiro número representa X e o segundo representa Y. Pontos que já existirem na estrutura não serão adicionados novamente.

## Conceitos demonstrados

O projeto aplica conceitos de orientação a objetos, vetores dinâmicos, modularização, validação de entrada, leitura de arquivos, pilhas, filas, distância euclidiana, ponto médio, trigonometria e transformação entre coordenadas cartesianas e pixels.

## Autor

**Carlos Vitor Taleires Rodrigues**  
Projeto desenvolvido para a aula de **Programação Avançada**.

> Carlos Vitor Taleires Rodrigues
