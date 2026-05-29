#include <stdio.h>

// Necessário pra diagonalização
int printm(int tamanho, double a[tamanho][tamanho])
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
}