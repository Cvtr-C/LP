@echo off
setlocal

cd /d "%~dp0"

set "COMPILADOR=C:\msys64\ucrt64\bin\g++.exe"
set "PROGRAMA=gerenciador_espacial.exe"
set "PATH=C:\msys64\ucrt64\bin;%PATH%"

if not exist "%COMPILADOR%" (
    echo ERRO: Compilador nao encontrado em:
    echo %COMPILADOR%
    echo.
    echo Instale o MSYS2 UCRT64 ou ajuste a variavel COMPILADOR neste arquivo.
    pause
    exit /b 1
)

echo Compilando...
"%COMPILADOR%" -std=c++17 -Wall -Wextra -pedantic ^
    -IC:\msys64\ucrt64\include\opencv4 ^
    main.cpp lista.cpp menu.cpp ponto.cpp ^
    -LC:\msys64\ucrt64\lib ^
    -lopencv_highgui -lopencv_imgproc -lopencv_core ^
    -o "%PROGRAMA%"

if errorlevel 1 (
    echo.
    echo A compilacao falhou.
    pause
    exit /b 1
)

echo.
echo Executando %PROGRAMA%...
echo.
"%~dp0%PROGRAMA%"

echo.
pause
