#include <stdio.h>

int main()
{
    int M[3][10], Alunos, Notas, Ma, Me, S = 0, s =0;
    float Mdn, Mda;
    for(Notas = 0; Notas < 3; Notas++)
    {
        for(Alunos = 0; Alunos < 10; Alunos++)
        {
            printf("M[%d][%d]:", Notas, Alunos);
            scanf("%d", &M[Notas][Alunos]);
        }  
    }
    for(Notas = 0; Notas < 3; Notas++)
    {
        for(Alunos = 0; Alunos < 10; Alunos++)
        {
            printf("%d\t", M[Notas][Alunos]);
        }   
        printf("\n");
    }
    for(Alunos = 0; Alunos < 10; Alunos++)
    {
        printf("Aluno %d\n", (Alunos + 1));
        for(Notas = 0; Notas < 3; Notas++)
        {
          s += M[Notas][Alunos];
        } 
        Mda = (float)s/Notas;
        printf("Média = %.2f\n", Mda);
        if(Mda >= 6)
        {
            printf("Aprovado");
        }
        else
        {
            printf("Reprovado");
        }
        s = 0;
        printf("\n\n");
    }
    for(Notas = 0; Notas < 3; Notas++)
    {
        for(Alunos = 0; Alunos < 10; Alunos++)
        {
             S += M[Notas][Alunos];
            if(Alunos == 0)
            {
                Ma = M[Notas][Alunos];
                Me = M[Notas][Alunos];
            }
            else
            {
                if(Ma < M[Notas][Alunos])
                {
                    Ma = M[Notas][Alunos];
                }
                else
                {
                    if(Me > M[Notas][Alunos])
                    {
                        Me = M[Notas][Alunos];
                    }
                }
            }
        }
        Mdn = (float)S/10;
        printf("Média da prova %d = %.2f \nMaior nota da prova %d = %d \nMenor nota da prova %d = %d\n\n", Notas + 1, Mdn, Notas + 1, Ma, Notas + 1, Me);
        S = 0;
    }
    return 0;
}