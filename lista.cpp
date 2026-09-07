#include "lista.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;

int centroX = 400;
int centroY = 400;
int fatorEscala = 4;

Mat lista::renderizarTela(string status)
{
    Mat image(800, 800, CV_8UC3, Scalar(255, 255, 255));

    for (int i = 0; i < (int)list.size(); i++)
    {
        int px = (list.at(i).x() * fatorEscala) + centroX;
        int py = (list.at(i).y() * fatorEscala) + centroY;
        cv::circle(image, Point(px, py), 5, Scalar(0, 0, 255), FILLED);
    }

    if (!status.empty())
    {
        putText(image, status, Point(20, 40), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 0, 0), 2);
    }
    return image;
}

void lista::clique(int event, int x, int y, int flags, void *userdata)
{
    ClickData *data = static_cast<ClickData *>(userdata);
    if (event == EVENT_LBUTTONDOWN)
    {
        data->x = (x - centroX) / fatorEscala;
        data->y = (y - centroY) / fatorEscala;
        data->clicked = true;
    }
}

bool lista::obterPontoPorClique(int &x, int &y, string acao)
{
    string tituloJanela = "Selecione o Ponto - " + acao;
    Mat imagem = renderizarTela("Acao: " + acao + " - Clique na tela");
    namedWindow(tituloJanela, WINDOW_AUTOSIZE);

    ClickData data;
    setMouseCallback(tituloJanela, clique, &data);
    imshow(tituloJanela, imagem);

    while (!data.clicked)
    {
        char tecla = (char)waitKey(10);
        if (tecla == 27 || getWindowProperty(tituloJanela, WND_PROP_VISIBLE) < 1)
        {
            destroyWindow(tituloJanela);
            return false;
        }
    }

    x = data.x;
    y = data.y;
    destroyWindow(tituloJanela);
    return true;
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

void lista::circle(const int &cx, const int &cy, const float &r, const int &np)
{
    if (np <= 0)
    {
        mostrarErro("O numero de pontos do circulo deve ser maior que zero.");
        return;
    }
    if (r < 0)
    {
        mostrarErro("O raio do circulo nao pode ser negativo.");
        return;
    }

    int x, y;
    double ang, temp;
    double np_double = (double)np;
    ang = 2 * 3.1415 / np_double;
    int gerados = 0;

    for (temp = 0; temp < 2 * 3.1415; temp = temp + ang)
    {
        x = cx + (int)(cos(temp) * r);
        y = cy + (int)(sin(temp) * r);
        if (!Duplicate(x, y))
        {
            ponto p(x, y);
            list.push_back(p);
            gerados++;
        }
    }
    mostrarSucesso("Circulo gerado com " + to_string(gerados) + " pontos espaciais!");
}

void lista::file(char *fileName)
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
    int idx = encontrarMaisProximo(x, y);
    if (idx == -1)
    {
        msgErroVazia("calcular o centroide");
        return;
    }

    double menorDist = pow(list.at(idx).x() - x, 2) + pow(list.at(idx).y() - y, 2);
    long long somaX = 0, somaY = 0;
    int contador = 0;

    for (int i = 0; i < (int)list.size(); i++)
    {
        double distSq = pow(list.at(i).x() - x, 2) + pow(list.at(i).y() - y, 2);
        if (distSq <= menorDist * 2.5)
        {
            somaX += list.at(i).x();
            somaY += list.at(i).y();
            contador++;
        }
    }

    if (contador == 0)
    {
        mostrarErro("Nenhum ponto proximo o suficiente da referencia informada.");
        return;
    }

    int cx = somaX / contador, cy = somaY / contador;
    if (Duplicate(cx, cy))
    {
        mostrarErro("O centroide calculado ja existe na estrutura espacial.");
        return;
    }

    ponto centroide(cx, cy);
    list.push_back(centroide);
    msgSucessoAdicao("como centroide regional", cx, cy);
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
        try
        {
            if (cv::getWindowProperty("Mapeamento Espacial", cv::WND_PROP_VISIBLE) >= 0)
            {
                cv::destroyWindow("Mapeamento Espacial");
            }
        }
        catch (...)
        {
        }
        return;
    }

    imprimirCabecalho("MAPEAMENTO ESPACIAL");
    for (int i = 0; i < (int)list.size(); i++)
    {
        cout << "  [" << i + 1 << "] -> X: " << list.at(i).x() << " | Y: " << list.at(i).y() << endl;
    }
    imprimirSeparador();

    namedWindow("Mapeamento Espacial", WINDOW_AUTOSIZE);
    Mat img = renderizarTela();
    imshow("Mapeamento Espacial", img);
    waitKey(50);
}
