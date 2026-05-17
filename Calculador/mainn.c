#include <stdio.h>

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
        printf("Soma: %d", a+b);
        break;

        case 2:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("Subtração: %d", a-b);
        
        break;

        case 3:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("Multiplicação: %d", a*b);
        break;

        case 4:
        printf("Digite outro número:");
        scanf("%d", &b);
        printf("Divisão: %.2f", (float)a/b);
        break;

        case 5:
        int b;
        if(a < 0)
        {
            printf("Não tem fatorial\n");
        }
        else
        {
            if (a == 0 || a == 1)
            {
                printf("Fatorial: 1");
            }
            else
            {
                b = a - 1;
                while (b > 1)
                {
                    a = a * b;
                    b--;
                }
                printf("Fatorial: %d", a);
            }
        }
        
        break;

        case 6:
        double cosrad = 0, sa = 0, da = 1, ca = 1;
        while (sa <= 20)
        {
            cosrad += ca/da;
            ca *= a*a*(-1);
            sa += 2;
            da *= (sa - 1) * sa; 
        }
        printf("Cosseno em radianos: %.2lf", cosrad);
        break;

        case 7:
        double coseno = 0, d = 1, c = 1, N = a;
        int s = 0;
        #define Pi 3.14159265358979323846
        N = (N*Pi)/180;
        while (s <= 20)
        { 
            coseno += c/d;
            c *= N*N*(-1);
            s += 2;
            d *= (s - 1) * s;
        }
        printf("Cosseno em graus: %.2lf", coseno);
        break;

        case 8:
         int res = 0, ds = 0;
        while (a > 0)
        {
            res = a%10;
            ds = res + ds;
            a = a/10;
        }
        printf("Somatório dos dígitos: %d", ds);
        break;

        case 9:
        int cont = 1; 
        float X;
        if(a < 0)
        {
            printf("Não tem raiz real\n");
        }
        else
        {
            X = a/2;
            if(X == 0)
            {
                printf("Raiz = 0");
            }
            else
            {
                while(cont < 20)
                {
                    X = (X*X + a)/(2*X);
                    cont++;
                }
                printf("Raiz quadrada: %.2f", X);
            }    
        }
        break;

        default:
        printf("opção inválida");
    }
}