#include "menu.h"

void imprimirSeparador()
{
  cout << "---------------------------------------" << endl;
}

void imprimirCabecalho(string titulo)
{
  cout << "\n=======================================" << endl;
  cout << "          " << titulo << "          " << endl;
  cout << "=======================================" << endl;
}

void mostrarErro(string mensagem)
{
  cout << " [!] Erro: " << mensagem << endl;
}

void mostrarSucesso(string mensagem)
{
  cout << " [+] " << mensagem << endl;
}

int lerInteiro(string mensagem)
{
  int valor;
  cout << mensagem;
  while (!(cin >> valor))
  {
    mostrarErro("Entrada invalida. Digite apenas numeros inteiros.");
    cout << " [>] Tente novamente: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  return valor;
}

void obterCoordenadas(int &x, int &y, lista &list, string acao)
{
  int escolha;
  cout << " [1] Digitar (Teclado) | [2] Clicar (Interface Grafica)\n";
  escolha = lerInteiro(" [>] Escolha o metodo: ");

  if (escolha == 1)
  {
    x = lerInteiro(" [+] Informe X: ");
    y = lerInteiro(" [+] Informe Y: ");
  }
  else
  {
    if (!list.obterPontoPorClique(x, y, acao))
    {
      mostrarErro("Operacao grafica cancelada.");
      x = -1;
      y = -1;
    }
  }
}

void menuImportarArquivo(lista &list)
{
  int opc;
  do
  {
    imprimirSeparador();
    list.mostrarPontos();
    imprimirCabecalho("IMPORTAR ARQUIVO");
    cout << " [1] - Carregar 'pontos1.txt'\n [2] - Carregar 'pontos2.txt'\n [3] - Voltar\n";
    imprimirSeparador();
    opc = lerInteiro(" [>] Digite a opcao desejada: ");

    if (opc == 1)
      list.file((char *)"pontos1.txt");
    else if (opc == 2)
      list.file((char *)"pontos2.txt");
  } while (opc != 3);
}

void menuGerarCirculo(lista &list, string acao)
{
  int x, y, r, n;
  obterCoordenadas(x, y, list, acao);
  if (x != -1)
  {
    r = lerInteiro(" [?] Informe o raio r: ");
    n = lerInteiro(" [?] Informe a quantidade de pontos n: ");
    list.circle(x, y, r, n);
  }
}

void executarMenuLista(lista &list)
{
  int opc2, opc3, x, y, ind;
  do
  {
    imprimirCabecalho("MODULO: LISTA (GERAL)");
    list.mostrarPontos();
    cout << " [1] - Adicionar Coordenada\n [2] - Excluir Coordenada\n [3] - Voltar\n";
    imprimirSeparador();
    opc2 = lerInteiro(" [>] Digite a opcao: ");

    if (opc2 == 1)
    {
      do
      {
        imprimirCabecalho("LISTA: ADICIONAR");
        list.mostrarPontos();
        list.mostrarGrafico();
        cout << " [1] No Inicio\n [2] No Final\n [3] Em Indice Especifico\n";
        cout << " [4] De Arquivo\n [5] No Centroide Proximo\n [6] Gerar Circulo\n [7] Voltar\n";
        imprimirSeparador();
        opc3 = lerInteiro(" [>] Digite a opcao: ");

        if (opc3 == 1)
        {
          obterCoordenadas(x, y, list, "Inserir Inicio");
          if (x != -1)
            list.adicionarNoComeco(x, y);
        }
        else if (opc3 == 2)
        {
          obterCoordenadas(x, y, list, "Inserir Fim");
          if (x != -1)
            list.adicionarNoFim(x, y);
        }
        else if (opc3 == 3)
        {
          ind = lerInteiro(" [?] Informe o indice alvo (1 a N): ");
          obterCoordenadas(x, y, list, "Inserir no Indice");
          if (x != -1)
            list.adicionarNoIndice(x, y, ind);
        }
        else if (opc3 == 4)
          menuImportarArquivo(list);
        else if (opc3 == 5)
        {
          obterCoordenadas(x, y, list, "Centroide");
          if (x != -1)
            list.adicionarCentroideMaisProximo(x, y);
        }
        else if (opc3 == 6)
          menuGerarCirculo(list, "Circulo Lista");

      } while (opc3 != 7);
    }
    else if (opc2 == 2)
    {
      do
      {
        imprimirCabecalho("LISTA: EXCLUIR");
        list.mostrarPontos();
        list.mostrarGrafico();
        cout << " [1] Primeiro\n [2] Ultimo\n [3] Por Indice\n [4] Proximo de (X,Y)\n [5] Voltar\n";
        imprimirSeparador();
        opc3 = lerInteiro(" [>] Digite a opcao: ");

        if (opc3 == 1)
          list.apagarPrimeiroPonto();
        else if (opc3 == 2)
          list.apagarUltimoPonto();
        else if (opc3 == 3)
        {
          ind = lerInteiro(" [?] Informe o indice: ");
          list.apagarIndice(ind);
        }
        else if (opc3 == 4)
        {
          obterCoordenadas(x, y, list, "Apagar Proximo");
          if (x != -1)
            list.apagarPontoMaisProximo(x, y);
        }
      } while (opc3 != 5);
    }
  } while (opc2 != 3);
}

void executarMenuPilha(lista &list)
{
  int opc2, opc3, x, y;
  do
  {
    imprimirCabecalho("MODULO: PILHA (LIFO)");
    list.mostrarPontos();
    cout << " [1] - Push (Adicionar no Fim)\n [2] - Pop (Remover do Fim)\n [3] - Voltar\n";
    imprimirSeparador();
    opc2 = lerInteiro(" [>] Digite a opcao: ");

    if (opc2 == 1)
    {
      do
      {
        imprimirCabecalho("PILHA: ADICIONAR");
        list.mostrarPontos();
        list.mostrarGrafico();
        cout << " [1] No Fim da Pilha\n [2] De Arquivo\n [3] Gerar Circulo\n [4] Voltar\n";
        imprimirSeparador();
        opc3 = lerInteiro(" [>] Digite a opcao: ");

        if (opc3 == 1)
        {
          obterCoordenadas(x, y, list, "Pilha Push");
          if (x != -1)
            list.adicionarNoFim(x, y);
        }
        else if (opc3 == 2)
          menuImportarArquivo(list);
        else if (opc3 == 3)
          menuGerarCirculo(list, "Circulo Pilha");
      } while (opc3 != 4);
    }
    else if (opc2 == 2)
      list.apagarUltimoPonto();
    list.mostrarGrafico();

  } while (opc2 != 3);
}

void executarMenuFila(lista &list)
{
  int opc2, opc3, x, y;
  do
  {
    imprimirCabecalho("MODULO: FILA (FIFO)");
    list.mostrarPontos();
    cout << " [1] - Enqueue (Adicionar no Fim)\n [2] - Dequeue (Remover do Inicio)\n [3] - Voltar\n";
    imprimirSeparador();
    opc2 = lerInteiro(" [>] Digite a opcao: ");

    if (opc2 == 1)
    {
      do
      {
        imprimirCabecalho("FILA: ADICIONAR");
        list.mostrarPontos();
        list.mostrarGrafico();
        cout << " [1] No Fim da Fila\n [2] De Arquivo\n [3] Gerar Circulo\n [4] Voltar\n";
        imprimirSeparador();
        opc3 = lerInteiro(" [>] Digite a opcao: ");

        if (opc3 == 1)
        {
          obterCoordenadas(x, y, list, "Fila Enqueue");
          if (x != -1)
            list.adicionarNoFim(x, y);
        }
        else if (opc3 == 2)
          menuImportarArquivo(list);
        else if (opc3 == 3)
          menuGerarCirculo(list, "Circulo Fila");
      } while (opc3 != 4);
    }
    else if (opc2 == 2)
      list.apagarPrimeiroPonto();
    list.mostrarGrafico();

  } while (opc2 != 3);
}

void msgErroDuplicado(int x, int y)
{
  cout << " [!] Erro: Ponto (X: " << x << " | Y: " << y << ") ja existe na malha! Duplicidade proibida." << endl;
}

void msgErroVazia(string contexto)
{
  cout << " [!] Erro: Lista vazia! Impossivel realizar operacao: " << contexto << "." << endl;
}

void msgSucessoAdicao(string contexto, int x, int y)
{
  cout << " [+] Sucesso: Ponto adicionado " << contexto << " -> X: " << x << " | Y: " << y << endl;
}

void msgSucessoRemocao(string contexto, int x, int y)
{
  cout << " [-] Removendo " << contexto << " -> X: " << x << " | Y: " << y << endl;
}