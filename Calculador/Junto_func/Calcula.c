#include <stdio.h>
#define Pi 3.14159265358979323846
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
        printf("não tem fatorial");
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
        printf("não tem raiz real");
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
int main()
{
    int op, a, b;
    printf("===============================\n");
    printf("\tCalculadora\n");
    printf("===============================\n");
    printf("Escolha uma opção: \n(1)Soma \n(2)Subtração \n(3)Multiplicação \n(4)Divisão \n(5)Fatorial \n(6)Cosseno em radianos \n(7)cosseno em graus \n(8)Somatorio dos digitos \n(9)Raiz quadrada \n:");
    scanf("%d", &op);
    printf("Digite um número:");
    scanf("%d", &a);
    switch(op)
    {
        case 1:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("A soma de %d + %d = %d", a, b, soma(a, b));
        break;

        case 2:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("A subtração de %d - %d = %d", a, b, sub(a, b));
        break;

        case 3:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("A multiplicação de %d * %d = %d", a, b, mult(a, b));
        break;

        case 4:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("A divisão de %d/%d = %.2f", a, b, div(a, b));
        break;

        case 5:
        printf("O fatorial de %d! = %d", a, fat(a));
        break;

        case 6:
        printf("O cosseno de %drad = %.2f", a, cosrad(a));
        break;

        case 7:
        printf("O cosseno de %d° = %.2f", a, coss(a));
        break;

        case 8:
        printf("O somatorio dos digitos de %d = %d", a, som(a));
        break;

        case 9:
        printf("A raiz quadrada de %d = %.2f", a, raiz(a));
        break;

        default:
        printf("opção inválida");
    }
    return 0;
}
