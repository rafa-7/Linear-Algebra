#include <stdio.h>
#include <math.h>
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

// Será necessário fazer uma função para a matriz reduzida
// Essa deve ser void e deve retornar a matriz reduzida por referência
void matrixRedu(int ordem, double rootMatrix[ordem][ordem], double subMatrix[ordem][ordem])
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if ()
            {
                rootMatrix[i][j]
            }
        }
    }
}


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
        
        int zeros = 0;
        double linha[tamanho];
        double coluna[tamanho];
        // Teorema de Laplace
        /*
        Task:
        Sinais variando sempre
        Pensar em uma maneira de fazer isso via algoritmo
        + - + - +
        - + - + -
        + - + - +
        - + - + -
        */
        
        /*
        Task:
        Verificar linhas e colunas, a que tiver mais 
        zeros será usado pra cálculo (opcional, o programa 
        vai funcionar de qualquer jeito, tendo 0 ou não)
        */

        
        for (int i = 0; i < ordem; i++)
        {
            for (int j = 0; j < ordem; j++)
            {
                if (a[i][j] == 0)
                {
                    zeros++;
                    

                }
                else
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