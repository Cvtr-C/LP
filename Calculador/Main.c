#include <stdio.h>
#include "calc.h"
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
