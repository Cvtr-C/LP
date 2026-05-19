#include <stdio.h> 
#include "veto.h"
int main()
{
    int V[10];
    int i, Ma, Me, S = 0;
    float Md, Ds, C = 0;
    for(i = 0; i < 10; i++)
    {
        printf("Digite o vetor[%d]=", i);
        scanf("%d", &V[i]);
        if(i == 0)
        {
          Ma = V[0];
          Me = V[0];  
        }
        else
        {
          if(Ma < V[i])
            {
                Ma = V[i];
            }
            else
            {
                if(Me > V[i])
                {
                    Me = V[i];
                }
            }  
        }
        if(primo(V[i]) == 1)
        {
            printf("O V[%d] e primo", i);
        }
        else
        {
            printf("O V[%d] nao e primo", i);
        }
        printf("\nA soma dos digitos do V[%d] e %d\n\n", i, som(V[i]));
        S = S+V[i];
    }
    Md = (float)S/i;
    for(i = 0; i < 10; i++)
    {
      C +=(V[i] - Md)*(V[i] - Md);
    }
    Ds = raiz(C/i);
    printf("\nMaior=%d \nMenor=%d \nMedia=%.2f \nDesvio padrao=%.2f", Ma, Me, Md, Ds);   
}