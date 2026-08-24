#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *A = NULL, res, t = 0, r;

  while (1)
  {
    printf("====================\n");
    printf("--------FILA--------\n");
    printf("====================\n");
    printf("(1) - Adicionar\n(2) - Excluir\n(3) - Mostrar\n(4) - Finalizar\n");
    printf("Digite a operação que você quer:");
    scanf("%d", &res);

    switch (res)
    {
    case 1:
      t = t + 1;
      A = (int *)realloc(A, t * sizeof(int));
      if (A == NULL)
      {
        printf("Erro na alocação!\n");
        return 1;
      }
      printf("Digite o número que você quer adicionar:\n");
      scanf("%d", &r);
      A[t - 1] = r;
      break;

    case 2:
      if (t == 0)
      {
        printf("A fila está vazia!\n");
      }
      else
      {
        printf("O número %d foi removido\n", A[0]);
        for (int l = 0; l < t - 1; l++)
        {
          A[l] = A[l + 1];
        }
        t = t - 1;
        if (t == 0)
        {
          printf("A fila está vazia agora!\n");
          free(A);
          A = NULL;
        }
        else
        {
          A = (int *)realloc(A, t * sizeof(int));
        }
      }
      break;

    case 3:
      if (A == NULL)
      {
        printf("A fila está vazia!\n");
      }
      else
      {
        printf("------Base------\n");
        for (int l = 0; l < t; l++)
        {
          printf("%d\n", A[l]);
        }
        printf("------TOPO------\n");
      }
      break;

    case 4:
      printf("Finalizando o processo...!\n");
      if (A != NULL)
      {
        free(A);
      }
      return 0;

    default:
      printf("Opção invalida!\n");
      break;
    }
  }
  return 0;
}