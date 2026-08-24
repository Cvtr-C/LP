#include <stdio.h>
#include <stdlib.h>

int main()
{
  int res, t = 0, r, *A = NULL;
  while (1)
  {
    printf("=========================\n");
    printf("------Menu-da-Pilha------\n");
    printf("=========================\n");
    printf("(1) - Adicionar\n(2) - Excluir\n(3) - Mostrar\n(4) - Finalizar\n");
    printf("Digite o processo que voce quer:");
    scanf("%d", &res);

    switch (res)
    {
    case 1:
      t = t + 1;
      A = (int *)realloc(A, t * sizeof(int));
      if (A == NULL)
      {
        printf("Erro de alocação\n");
        return 1;
      }
      printf("Digite o número que você quer adicionar:");
      scanf("%d", &r);
      A[t - 1] = r;
      break;

    case 2:
      if (t == 0)
      {
        printf("A pilha está vazia\n");
      }
      else
      {
        printf("O número %d foi removido!\n", A[t - 1]);

        t = t - 1;
        if (t == 0)
        {
          printf("A pilha está vazia agora!\n");
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
      if (t == 0)
      {
        printf("Lista vazia!\n");
      }
      else
      {
        printf("------TOPO------\n");
        for (int l = t; l > 0; l--)
        {
          printf("%d\n", A[l - 1]);
        }
        printf("------BASE------\n");
      }
      break;

    case 4:
      printf("Encerrando programa...!\n");
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