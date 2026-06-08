#include <stdio.h>
#include "../../include/determinant.h"

// O determinante pode apenas ser calculado para matrizes quadradas
// Essa função vai ser utilizada para os seguintes problemas:
// - Checking for injectivity, surjectivity, and bijectivity.
// - Determination of Bases
// - Eigenvalue and Eigenvector Calculation
// - Matrix Diagonalization

/*
Para chamar a função, vamos utilizar uma matriz 4x4 como exemplo:

    int matrizTeste[4][4] =
    {
        {1, 2, 3.2, 5},
        {3, 4, 290.23, 3.14159},
        {0, 8, 900, 325},
        {1, 6, 7, 3.14159},
    };

    printf("det(A)=%.1lf\n",det(2, matrizTeste));
    Isso retorna o determinante
*/

void subMatrix(int ordem, double a[ordem][ordem], subMatrix[tamanho][tamanho], int colunaDel, int ordemAtual)
{
    int linhaSub = 0;

    for (int i = 1; i < ordem; i++)
    {
        int colunaSub = 0;
        for (int j = 0; j < ordem; j++)
        {
            if (j == colunaDel) continue;
            subMatrix[linhaSub][colunaSub] = a[i][j];
            colunaSub++;
        }
        linhaSub++;
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
        // Teorema de Laplace 
        // Escolheremos sempre a primeira linha pra facilitar o cálculo
        double resultadoDet = 0.0;
        int sinal = 1;

        double matrixRedu[ordem][ordem];

        
        for (int j = 0; j < ordem; j++)
        {
            subMatrix(ordem, a, matrixRedu, j);
            double elemento = a[0][j];

            resultadoDet += sinal * elemento * det(ordem - 1, matrixRedu);
            sinal = -sinal;
        }
        return resultadoDet;
    }
    else
    {
        printf("Digite uma ordem válida!\n");
        return 1;
    }
}