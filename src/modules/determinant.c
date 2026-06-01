#include <stdio.h>

// Usando o abs para módulo
#include <stdlib.h>
#include "../../include/determinant.h"

// O determinante pode apenas ser calculado para matrizes quadradas

/*
Para chamar a função, vamos utilizar uma matriz 4x4 como exemplo:

    int matrizTeste[2][2] =
    {
        {1, 2, 3.2, 5},
        {3, 4, 290.23, 3.14159},
        {0, 8, 900, 325},
        {1, 6, 7, 3.14159},
    };

    printf("det(A)=%.1lf\n",det(2, matrizTeste));
    Isso retorna o determinante
*/

double det(int ordem, double a[ordem][ordem])
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
    else if (ordem >= 4)
    {
        // Eliminação Gaussiana
        for (int i = 0; i < ordem; i++)
        {
            for (int j = i + 1; j < ordem; j++)
            {
                // A intenção é definir o maior pivô pra não termos divisão por zero aqui
                if (a[j][i] > a[i][i])
                {

                }
            }
        }


    }
    else
    {
        printf("Digite uma ordem válida!\n");
        return 1;
    }
}