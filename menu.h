#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

void imprimirSeparador();
void imprimirCabecalho(string titulo);
void mostrarErro(string mensagem);
void mostrarSucesso(string mensagem);

int lerInteiro(string mensagem);
void obterCoordenadas(int &x, int &y, lista &list, string acao);
void menuImportarArquivo(lista &list);
void menuGerarCirculo(lista &list, string acao);

void executarMenuLista(lista &list);
void executarMenuPilha(lista &list);
void executarMenuFila(lista &list);

void msgErroDuplicado(int x, int y);
void msgErroVazia(string contexto);
void msgSucessoAdicao(string contexto, int x, int y);
void msgSucessoRemocao(string contexto, int x, int y);
#endif