#include <iostream>

#include "lista.h"

#include "menu.h"

using namespace std;

int main()
{
    int opc;
    lista list;

    do
    {
        imprimirCabecalho("GERENCIADOR ESPACIAL");
        list.mostrarPontos();

        imprimirCabecalho("MENU PRINCIPAL");
        cout << " [1] - Lista de Coordenadas (Geral)" << endl;
        cout << " [2] - Pilha (LIFO)" << endl;
        cout << " [3] - Fila (FIFO)" << endl;
        cout << " [4] - Sair do Sistema" << endl;
        imprimirSeparador();

        opc = lerInteiro(" [>] Digite a opcao desejada: ");

        switch (opc)
        {
        case 1:
            executarMenuLista(list);
            break;
        case 2:
            executarMenuPilha(list);
            break;
        case 3:
            executarMenuFila(list);
            break;
        case 4:
            mostrarSucesso("Encerrando aplicacao. Ate a proxima aula!");
            break;
        default:
            mostrarErro("Opcao invalida no menu principal. Tente novamente.");
        }
    } while (opc != 4);

    return 0;
}