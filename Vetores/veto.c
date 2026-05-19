#include <stdio.h>
#include "veto.h"
float raiz(float a)
{
    int cont = 1;
    float X;
    if(a < 0)
    {
        printf("Não tem raiz real\n");
        return 0;
    }
    else
    {
        X = a/2;
        if(X == 0)
        {
            return 0;
        }
        else
        {
            while(cont < 20)
            {
                X = (X*X + a)/(2*X);
                cont++;
            }
            return X;
        }
    }
}

int primo(int a)
{
    int R, s = 1, cont = 0;
    while(s <= a)
    {
        R = a%s;
        if(R == 0)
        {
           cont++;
        }
        s++;
    }
    if(cont == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int som(int a)
{
    int res = 0, b = 0;
    while (a > 0)
    {
        res = a%10;
        b = res + b;
        a = a/10;
    }
    return b;
}