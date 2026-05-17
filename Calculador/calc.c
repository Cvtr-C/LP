#include <stdio.h>
#include "calc.h"

int soma(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mult(int a, int b)
{
    return a * b;
}

float div(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    return (float)a/b;
}

int fat(int a)
{
    int b;
    if(a < 0)
    {
        printf("Não tem fatorial\n");
        return 0;
    }
    else
    {
        if (a == 0 || a == 1)
        {
            return 1;
        }
        else
        {
       
            b = a - 1;
            while (b > 1)
            {
                a = a * b;
                b--;
            } 
            return a;
        }  
    }
}

double cosrad(double a)
{
    double coseno = 0, s = 0, b = 1, c = 1;
    while (s <= 50)
    {
        coseno += c/b;
        c *= a*a*(-1);
        s += 2;
        b *= (s - 1) * s; 
    }
    return coseno;
}

double coss(double a)
{
    double coseno = 0, s = 0, b = 1, c = 1;
    a = (a*Pi)/180;
    while (s <= 50)
    { 
        coseno += c/b;
        c *= a*a*(-1);
        s += 2;
        b *= (s - 1) * s;
    }
    return coseno;
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