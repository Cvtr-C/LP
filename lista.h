#ifndef lista_h
#define lista_h

#include "ponto.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

class lista
{
public:
    //*************************************CONSTRUTORES*************************************//

    lista();
    lista(int x, int y);
    lista(int x, int y, float raio, int numero_pontos);
    lista(char *fileName);

    ~lista();

    void adicionarNoFim(int x, int y);
    void adicionarNoComeco(int x, int y);
    void adicionarNoIndice(int x, int y, int ind);

    void circle(const int &cx, const int &cy, const float &r, const int &np);
    void file(char *fileName);

    void mostrarPontos();

    void apagarIndice(int ind);
    void apagarUltimoPonto();
    void apagarPrimeiroPonto();

    bool Duplicate(int x, int y);

    void adicionarCentroideMaisProximo(int x, int y);
    int encontrarMaisProximo(int x, int y);
    void apagarPontoMaisProximo(int x, int y);

    bool obterPontoPorClique(int &x, int &y, string acao);

private:
    struct ClickData
    {
        int x = -1;
        int y = -1;
        bool clicked = false;
    };
    static void clique(int event, int x, int y, int flags, void *userdata);
    cv::Mat renderizarTela(string status = "");

    vector<ponto> list;
};
#endif
