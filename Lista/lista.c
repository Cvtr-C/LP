#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r, res, *A = NULL, t = 0, g;

  while (1)
  {
    printf("===================");
    printf("-------LISTA-------");
    printf("===================");
    printf("(1) - Novo\n(2) - Atualizar\n (3) - Excluir\n(4) - Mostrar\n(5) - Finalizar\n");
    printf("Digite o processo que você quer:");
    scanf("%d", &res);

    switch (res)
    {
    case 1:
      t = t + 1;

      A = (int *)realloc(A, t * sizeof(int));
      if (A == NULL)
      {
        printf("Erro de alocação");
        return 1;
      }

      printf("Digite o número que você quer adicionar");
      scanf("%d", &r);
      A[t - 1] = r;
      break;

    case 2:
      if (t == 0)
      {
        printf("A lista está vazia então não é possivel atualizar!");
      }
      else
      {
        g = -1;
        while (g < 0 || g > t - 1)
        {
          printf("\nDigite uma posição de 0 à %d!!!\n", t - 1);
          printf("Digite onde você quer atualizar o número:");
          scanf("%d", &g);
        }
        printf("\nDigite o número que você quer substituir:");
        scanf("%d", &r);
        A[g] = r;
      }
      break;

    case 3:
      if (t == 0)
      {
        printf("A lista está vazia!");
      }
      else
      {
        g = -1;
        while (g < 0 || g > t - 1)
        {
          printf("Digite uma posição de 0 à %d!!!", t - 1);
          printf("Digite a posição que você quer excluir:");
          scanf("%d", &g);
        }
        printf("O número %d foi removido!", A[g]);
        for (int l = g; l < t - 1; l++)
        {
          A[l] = A[l + 1];
        }
        t = t - 1;
        if (t == 0)
        {
          printf("A lista está vazia agora!");
          free(A);
          A = NULL;
        }
        else
        {
          A = (int *)realloc(A, t * sizeof(int));
        }
      }
      break;

    case 4:
      if (t == 0)
      {
        printf("A lista está vazia!\n");
      }
      else
      {
        printf("A = [%d", A[0]);
        int l;
        for (l = 1; l < t; l++)
        {
          printf(", %d", A[l]);
        }
        printf("]\n");
      }
      break;

    case 5:
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