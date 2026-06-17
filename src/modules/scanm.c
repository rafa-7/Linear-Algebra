#include <stdio.h>
#include "../../include/scanm.h"

// Essa função vai ser usada na diagonalização de matrizes
// task: Transformar em void
void scanm(int tamanho, double a[tamanho][tamanho])
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
}