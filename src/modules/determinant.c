#include <stdio.h>
#include "../../include/determinant.h"

// O determinante pode apenas ser calculado para matrizes quadradas

/*
Para chamar a função, vamos utilizar uma matriz 2x2 como exemplo:

int matrixTeste[2][2] =
{
    {1, 2},
    {3, 4}
};

int det(2, matrixTeste);
*/
int det(int ordem, int a[ordem][ordem])
{
    if (ordem == 1)
    {
        // O determinante de uma matriz 1x1 é o próprio elemento
        return a[0][0];
    }
    else if (ordem == 2)
    {
        return a[0][0] * a[1][1] - a[1][0] * a[0][1];
    }
    else if (ordem == 3)
    {
        // Regra de Sarrus decomposta
        return a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2];
    }
    // else if (ordem >= 4)
    // {
    //     // Teorema de Laplace
    //     int cofator;

    //     // Procurar por algum elemento equivalente a 0
    //     for (int i = 0; i < ordem; i++)
    //     {
    //         for (int j = 0; j < ordem; j++)
    //         {
    //             if (a[i][j] == 0)
    //             {
    //                 int posicao =  
    //             }
    //             // Para o infortúnio de não haver nenhum elemento 0
    //             else
    //             {

    //             }
    //         }
    //     }

    // }
    else
    {
        printf("Digite uma ordem válida!\n");
        return 1;
    }
}