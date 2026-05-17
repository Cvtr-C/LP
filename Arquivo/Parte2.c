#include <stdio.h>

int main()
{
    FILE *parte2;
    parte2 = fopen("parte2.txt", "r");
    if (parte2 == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    else
    {
        int L1, L2, L3;
       while(fscanf(parte2, "%d %d %d", &L1, &L2, &L3) == 3)
       {
        printf("Lado 1 = %d\nLado 2 = %d\nLado 3 = %d\n", L1, L2, L3);
        if(L1 < L2 + L3 && L2 < L1 + L3 && L3 < L1 + L2)
        {
            if(L1 == L2 && L2 == L3)
            {
                printf("E um triangulo equilatero\n\n");
            }
            else
            {
                if(L1 == L2 || L2 == L3 || L1 == L3)
                {
                    printf("E um triangulo isoceles\n\n");
                }
                else
                {
                    printf("E um triangulo escaleno\n\n");
                }
            }
        }
        else
        {
            printf("Nao e um triangulo\n\n");
        }
       }
    }
    fclose(parte2);
}