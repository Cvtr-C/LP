#include <stdio.h>

int main()
{
    FILE *parte1;
    parte1 = fopen("parte1.txt", "r");
    if(parte1 == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    else
    {
        int i, r, A = 1, c = 0;
        double z;
        while(fscanf(parte1, "%d", &i) == 1)
        {
            printf("numero = %d\n", i);

            while(A <= i)
            {
                r = i%A;
                if(r == 0)
                {
                    c++;
                }
                A++;
            }
            if(c == 2)
            {
                printf("%d e primo\n", i);
            }
            else
            {
                printf("%d nao e primo\n", i);
            }
            
            if(i < 0)
            {
                printf("Não tem fatorial\n");
            }
            else
            {
                if(i == 0 || i == 1)
                {
                    printf("O fatorial = 1\n", i);
                }
                else
                {
                    z = i;
                    c = i - 1;
                    while(c > 1)
                    {
                        z = z * c;
                        c--;
                    }
                    printf("O fatorial = %.0lf\n", z);
                }
            }

            A = 1;
            if(i < 0)
            {
                printf("Não tem raiz real");
            }
            else
            {
                if(i == 0)
                {
                    printf("Raiz = 0");
                }
                else
                {
                    z = (float)i/2;
                    while(A < 20)
                    {
                    z = (z*z + i)/(2*z);
                    A++;
                    }
                    printf("A raiz quadrada = %.2lf\n\n", z);
                }   
            } 
            A = 1;
            c = 0;
        }
    }
    fclose(parte1);
    return 0;
}


