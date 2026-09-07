# 🌌 Gerenciador Espacial - Setup de Ambiente C++ & OpenCV

![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![OpenCV](https://img.shields.io/badge/OpenCV-4.x-green.svg)
![MSYS2](https://img.shields.io/badge/MSYS2-UCRT64-purple.svg)
![Status](https://img.shields.io/badge/Status-Ativo-success.svg)

Este documento descreve o processo de configuração do ambiente de desenvolvimento nativo para C/C++ com a biblioteca **OpenCV** no Windows, utilizando o compilador GCC via **MSYS2 (UCRT64)** e o editor **Visual Studio Code**.

---

## 🛠️ Pré-requisitos e Instalação do Ecossistema

Para garantir compatibilidade de bibliotecas e evitar conflitos de DLLs (_DLL Hell_), utilizamos o ecossistema MSYS2. Siga o passo a passo abaixo.

### 1. Instalação do MSYS2

1. Baixe o instalador no [site oficial do MSYS2](https://www.msys2.org/).
2. Siga a instalação padrão (recomendado manter no diretório `C:\msys64`).
3. Ao finalizar, **não** abra o terminal padrão. Procure no Iniciar do Windows por **`MSYS2 UCRT64`** (ícone azul) e abra-o.

### 2. Instalação do Compilador e OpenCV

Dentro do terminal do **MSYS2 UCRT64**, execute os comandos abaixo.

Primeiro, atualize os pacotes do sistema:

```bash
pacman -Syu
```

Em seguida, instale as ferramentas de build (GCC, GDB) e o OpenCV oficial (que já resolve dependências gráficas como o Qt6):

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-opencv
```

> **Nota:** Pressione `Y` e `Enter` sempre que for solicitada a confirmação de instalação.

### 3. Configuração da Variável de Ambiente (PATH)

Para que o Windows localize as dependências dinâmicas (DLLs) em tempo de execução:

1. Pressione a tecla `Windows` e digite **Variáveis de Ambiente**.
2. Selecione **Editar as variáveis de ambiente do sistema**.
3. Clique no botão **Variáveis de Ambiente...**.
4. Na lista inferior (_Variáveis do sistema_), encontre a variável **`Path`**, selecione-a e clique em **Editar**.
5. Clique em **Novo** e adicione o seguinte caminho:
   ```text
   C:\msys64\ucrt64\bin
   ```
6. Salve e reinicie o seu computador (ou o VS Code) para que as alterações entrem em vigor.

---

## ⚙️ Configuração do Workspace (VS Code)

Para que o IntelliSense e o build automatizado funcionem perfeitamente, o repositório conta com configurações na pasta `.vscode`. Se precisar recriá-las, utilize os arquivos abaixo:

### `c_cpp_properties.json`

Responsável por guiar o IntelliSense do VS Code para não relatar erros falsos de cabeçalho.

```json
{
  "configurations": [
    {
      "name": "windows-ucrt-x64",
      "includePath": [
        "${workspaceFolder}/**",
        "C:/msys64/ucrt64/include",
        "C:/msys64/ucrt64/include/opencv4"
      ],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
      "cStandard": "c17",
      "cppStandard": "c++20",
      "intelliSenseMode": "windows-gcc-x64"
    }
  ],
  "version": 4
}
```

### `settings.json`

Configurações da extensão _C/C++ Runner_ e diretivas de otimização de busca do workspace.

```json
{
  "C_Cpp_Runner.cCompilerPath": "C:/msys64/ucrt64/bin/gcc.exe",
  "C_Cpp_Runner.cppCompilerPath": "C:/msys64/ucrt64/bin/g++.exe",
  "C_Cpp_Runner.debuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
  "C_Cpp_Runner.cStandard": "c17",
  "C_Cpp_Runner.cppStandard": "c++20",
  "C_Cpp_Runner.includePaths": [
    "${workspaceFolder}/**",
    "C:/msys64/ucrt64/include",
    "C:/msys64/ucrt64/include/opencv4"
  ],
  "C_Cpp_Runner.includeSearch": ["*", "**/*"],
  "C_Cpp_Runner.excludeSearch": [
    "**/build",
    "**/build/**",
    "**/.*",
    "**/.vscode"
  ]
}
```

### `tasks.json`

Automatiza a compilação do projeto em um único grafo de dependências e realiza a linkagem das bibliotecas de visão computacional.

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "Compilar Projeto C++ com OpenCV",
      "command": "g++",
      "args": [
        "*.cpp",
        "-o",
        "gerenciador_espacial.exe",
        "-IC:/msys64/ucrt64/include/opencv4",
        "-LC:/msys64/ucrt64/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_videoio",
        "-std=c++20"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "detail": "Unifica os módulos em C++ e realiza a linkagem do OpenCV."
    }
  ]
}
```

---

## 🚀 Como Compilar e Executar

Com o ambiente devidamente parametrizado:

1. Abra o diretório do projeto no VS Code.
2. Pressione `Ctrl + Shift + B` para acionar a tarefa de build (`tasks.json`).
3. Aguarde o terminal indicar sucesso na compilação.
4. Execute o arquivo gerado no terminal integrado:
   ```bash
   ./gerenciador_espacial.exe
   ```
