#include "lista.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;

double fatorEscala = 40.0;

Mat lista::renderizarTela(string status)
{
    const int largura = 800;
    const int altura = 800;
    Mat image(altura, largura, CV_8UC3, Scalar(255, 255, 255));

    double centroX = largura / 2.0;
    double centroY = altura / 2.0;

    int maiorValor = 20;

    for (int i = 0; i < (int)list.size(); i++)
    {
        maiorValor = max(maiorValor, abs(list.at(i).x()));
        maiorValor = max(maiorValor, abs(list.at(i).y()));
    }

    int margem = 50;
    int tamanhoUtilX = largura / 2 - margem;
    int tamanhoUtilY = altura / 2 - margem;

    int tamanhoUtil = min(tamanhoUtilX, tamanhoUtilY);

    fatorEscala = (double)tamanhoUtil / maiorValor;

    int intervalo = 1;

    while (intervalo * fatorEscala < 100.0)
    {
        intervalo *= 2;
    }

    int distGrade = (int)(intervalo * fatorEscala);

    for (int x = (int)centroX; x < largura; x += distGrade)
    {
        line(image, Point(x, 0), Point(x, altura), Scalar(230, 230, 230), 1);
    }
    for (int x = (int)centroX - distGrade; x >= 0; x -= distGrade)
    {
        line(image, Point(x, 0), Point(x, altura), Scalar(230, 230, 230), 1);
    }

    for (int y = (int)centroY; y < altura; y += distGrade)
    {
        line(image, Point(0, y), Point(largura, y), Scalar(230, 230, 230), 1);
    }
    for (int y = (int)centroY - distGrade; y >= 0; y -= distGrade)
    {
        line(image, Point(0, y), Point(largura, y), Scalar(230, 230, 230), 1);
    }

    line(image, Point(0, (int)centroY), Point(largura, (int)centroY), Scalar(0, 0, 0), 2);
    line(image, Point((int)centroX, 0), Point((int)centroX, altura), Scalar(0, 0, 0), 2);

    int limiteX = (int)(largura / 2.0 / fatorEscala / intervalo) * intervalo;

    for (int valor = -limiteX; valor <= limiteX; valor += intervalo)
    {
        if (valor == 0)
            continue;

        int px = (int)(centroX + valor * fatorEscala);

        if (px >= 0 && px < largura)
        {
            line(image, Point(px, (int)centroY - 5), Point(px, (int)centroY + 5), Scalar(0, 0, 0), 1);
            putText(image, to_string(valor), Point(px - 10, (int)centroY + 25), FONT_HERSHEY_SIMPLEX, 0.45, Scalar(0, 0, 0), 1);
        }
    }

    int limiteY = (int)(altura / 2.0 / fatorEscala / intervalo) * intervalo;

    for (int valor = -limiteY; valor <= limiteY; valor += intervalo)
    {
        if (valor == 0)
            continue;

        int py = (int)(centroY - valor * fatorEscala);

        if (py >= 0 && py < altura)
        {
            line(image, Point((int)centroX - 5, py), Point((int)centroX + 5, py), Scalar(0, 0, 0), 1);
            putText(image, to_string(valor), Point((int)centroX + 10, py + 5), FONT_HERSHEY_SIMPLEX, 0.45, Scalar(0, 0, 0), 1);
        }
    }

    putText(image, "0", Point((int)centroX + 8, (int)centroY + 20), FONT_HERSHEY_SIMPLEX, 0.45, Scalar(0, 0, 0), 1);

    for (int i = 0; i < (int)list.size(); i++)
    {
        double px = centroX + list.at(i).x() * fatorEscala;
        double py = centroY - list.at(i).y() * fatorEscala;
        if (px >= 0 && px < largura && py >= 0 && py < altura)
        {
            cv::circle(image, Point((int)px, (int)py), 2, Scalar(0, 0, 255), FILLED, LINE_AA);
            if (list.size() <= 40)
            {
                string texto = "(" + to_string(list.at(i).x()) + ", " + to_string(list.at(i).y()) + ")";
                putText(image, texto, Point((int)px + 8, (int)py - 8), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(0, 0, 0), 1, LINE_AA);
            }
        }
    }

    if (!status.empty())
    {
        putText(image, status, Point(20, 30), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 0, 0), 2);
    }
    return image;
}

void lista::clique(int event, int x, int y, int flags, void *userdata)
{
    if (event != EVENT_LBUTTONDOWN)
        return;

    ClickData *data = static_cast<ClickData *>(userdata);

    int largura = 800;
    int altura = 800;

    double centroX = largura / 2.0;
    double centroY = altura / 2.0;

    data->x = (int)round((x - centroX) / fatorEscala);
    data->y = (int)round((centroY - y) / fatorEscala);
    data->clicked = true;
}

bool lista::obterPontoPorClique(int &x, int &y, string acao)
{
    string tituloJanela = "Plano Cartesioano - " + acao;
    namedWindow(tituloJanela, WINDOW_AUTOSIZE);

    ClickData data;
    setMouseCallback(tituloJanela, lista::clique, &data);

    while (true)
    {
        Mat imagem = renderizarTela("Clique para selecionar um ponto | ESC para cancelar");

        imshow(tituloJanela, imagem);

        int tecla = waitKey(20);

        if (tecla == 27)
        {
            destroyWindow(tituloJanela);
            return false;
        }

        if (data.clicked)
        {
            x = data.x;
            y = data.y;

            destroyWindow(tituloJanela);
            return true;
        }
    }
}

//*************************************CONSTRUTORES*************************************//
lista::lista() {}

bool lista::Duplicate(int x, int y)
{
    for (int i = 0; i < (int)list.size(); i++)
    {
        if (list.at(i).x() == x && list.at(i).y() == y)
            return true;
    }
    return false;
}

int lista::encontrarMaisProximo(int x, int y)
{
    if (list.empty())
        return -1;

    int indiceMaisProximo = 0;
    double menorDistanciaSq = pow(list.at(0).x() - x, 2) + pow(list.at(0).y() - y, 2);

    for (int i = 1; i < (int)list.size(); i++)
    {
        double distanciaSq = pow(list.at(i).x() - x, 2) + pow(list.at(i).y() - y, 2);
        if (distanciaSq < menorDistanciaSq)
        {
            menorDistanciaSq = distanciaSq;
            indiceMaisProximo = i;
        }
    }
    return indiceMaisProximo;
}

lista::lista(int x, int y)
{
    ponto p(x, y);
    list.push_back(p);
}

void lista::circle(int cx, int cy, int r, int np)
{
    if (np <= 0)
    {
        mostrarErro("O numero de pontos do circulo deve ser maior que zero.");
        return;
    }
    if (r <= 0)
    {
        mostrarErro("O raio do circulo nao pode ser negativo ou zero.");
        return;
    }

    constexpr double PI = 3.1415926535;
    int gerados = 0;

    for (int i = 0; i < np; i++)
    {
        double ang = 2.0 * PI * i / np;
        int x = cx + (int)round(cos(ang) * r);
        int y = cy + (int)round(sin(ang) * r);
        if (!Duplicate(x, y))
        {
            ponto p(x, y);
            list.push_back(p);
            gerados++;
        }
    }
    mostrarSucesso("Circulo gerado com " + to_string(gerados) + " pontos de " + to_string(np) + " solicitados.");
}

void lista::file(const char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        mostrarErro("Nao foi possivel abrir o arquivo solicitado.");
        return;
    }

    int vx, vy, pontosAdicionados = 0;
    while (fscanf(fp, "%d - %d", &vx, &vy) == 2)
    {
        if (!Duplicate(vx, vy))
        {
            ponto p(vx, vy);
            list.push_back(p);
            pontosAdicionados++;
        }
    }
    fclose(fp);
    mostrarSucesso("Arquivo processado! " + to_string(pontosAdicionados) + " novos pontos.");
}

lista::~lista() {}

void lista::adicionarNoFim(int x, int y)
{
    if (Duplicate(x, y))
    {
        msgErroDuplicado(x, y);
        return;
    }
    ponto p(x, y);
    list.push_back(p);
    msgSucessoAdicao("no fim da malha", x, y);
}

void lista::adicionarNoComeco(int x, int y)
{
    if (Duplicate(x, y))
    {
        msgErroDuplicado(x, y);
        return;
    }
    ponto p(x, y);
    list.insert(list.begin(), p);
    msgSucessoAdicao("no inicio da malha", x, y);
}

void lista::adicionarNoIndice(int x, int y, int ind)
{
    if (Duplicate(x, y))
    {
        msgErroDuplicado(x, y);
        return;
    }
    if (ind >= 1 && ind <= (int)list.size() + 1)
    {
        ponto p(x, y);
        list.insert(list.begin() + (ind - 1), p);
        msgSucessoAdicao("na posicao " + to_string(ind), x, y);
    }
    else
    {
        mostrarErro("Indice fora dos limites validos para insercao.");
    }
}

void lista::adicionarCentroideMaisProximo(int x, int y)
{
    if (list.size() < 2)
    {
        msgErroVazia("Sao necessarios pelo menos dois pontos.");
        return;
    }

    int ind = -1;
    double menorDist = DBL_MAX;

    for (int i = 0; i < (int)list.size() - 1; i++)
    {
        double cx = (list.at(i).x() + list.at(i + 1).x()) / 2.0;
        double cy = (list.at(i).y() + list.at(i + 1).y()) / 2.0;

        double dx = x - cx;
        double dy = y - cy;

        double distSq = dx * dx + dy * dy;

        if (distSq < menorDist)
        {
            menorDist = distSq;
            ind = i;
        }
    }

    if (ind == -1)
    {
        mostrarErro("Não foi possivel encontrar dois pontos.");
        return;
    }

    int novoX = (int)round((list.at(ind).x() + list.at(ind + 1).x()) / 2.0);
    int novoY = (int)round((list.at(ind).y() + list.at(ind + 1).y()) / 2.0);

    if (Duplicate(novoX, novoY))
    {
        mostrarErro("O ponto médio calculado já existe na estrutura espacial.");
        return;
    }

    ponto novoPonto(novoX, novoY);
    list.insert(list.begin() + ind + 1, novoPonto);

    msgSucessoAdicao("Entre os dois pontos mais proximos", novoX, novoY);
}

void lista::apagarPontoMaisProximo(int x, int y)
{
    if (list.empty())
    {
        msgErroVazia("excluir por proximidade");
        return;
    }
    int idx = encontrarMaisProximo(x, y);
    if (idx == -1)
    {
        mostrarErro("Nenhum ponto valido encontrado.");
        return;
    }

    msgSucessoRemocao("ponto mais proximo na posicao " + to_string(idx + 1), list.at(idx).x(), list.at(idx).y());
    list.erase(list.begin() + idx);
}

void lista::apagarIndice(int ind)
{
    if (list.empty())
    {
        msgErroVazia("excluir por indice");
        return;
    }
    if (ind >= 1 && ind <= (int)list.size())
    {
        msgSucessoRemocao("ponto na posicao " + to_string(ind), list.at(ind - 1).x(), list.at(ind - 1).y());
        list.erase(list.begin() + (ind - 1));
    }
    else
    {
        mostrarErro("Indice invalido para exclusao! Verifique os limites.");
    }
}

void lista::apagarUltimoPonto()
{
    if (list.empty())
    {
        msgErroVazia("remover o ultimo elemento");
        return;
    }
    msgSucessoRemocao("ultimo elemento (Pop)", list.back().x(), list.back().y());
    list.pop_back();
}

void lista::apagarPrimeiroPonto()
{
    if (list.empty())
    {
        msgErroVazia("remover o primeiro elemento");
        return;
    }
    msgSucessoRemocao("primeiro elemento (Dequeue)", list.front().x(), list.front().y());
    list.erase(list.begin());
}

void lista::mostrarPontos()
{
    if (list.empty())
    {
        cout << "[i] O ambiente espacial esta vazio." << endl;
        return;
    }

    imprimirCabecalho("MAPEAMENTO ESPACIAL");
    for (int i = 0; i < (int)list.size(); i++)
    {
        cout << "  [" << i + 1 << "] -> X: " << list.at(i).x() << " | Y: " << list.at(i).y() << endl;
    }
    imprimirSeparador();
}

void lista::mostrarGrafico()
{
    if (list.empty())
    {
        cout << "[i] Nenhum ponto para mostrar." << endl;
        return;
    }
    Mat img = renderizarTela("Mapeamento Espacial");
    namedWindow("Mapeamento Espacial", WINDOW_AUTOSIZE);
    imshow("Mapeamento Espacial", img);
    waitKey(0);
    destroyWindow("Mapeamento Espacial");
}
