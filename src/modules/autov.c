#include "../../include/autov.h"
#include <math.h>

// Objetivo:
// Calcular autovalores e autovetores
// Apenas para matrizes 2x2

// O static garante que a função somente existirá dentro desse arquivo C e não irá para a main
// Definir como static
raizes bhaskara(double a, double b, double c)
{
    double delta = (b * b) - (4 * a * c);
    raizes deltas;


    if (delta < 0)
    {
        deltas.delta1 = 0.0;
        deltas.delta2 = 0.0;
        return deltas;
    }
    else
    {
        deltas.delta1 = (-b + sqrt(delta)) / (2 * a);
        deltas.delta2 = (-b - sqrt(delta)) / (2 * a);
        return deltas;
    }
}

// Usada no autov pra cálculo de matrizes identidades
static void iMatrix(int ordem, double matriz[ordem][ordem], double matrizIden[ordem][ordem])
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            matrizIden[i][j] = matriz[i][j];

            if(i == j)
            {
                matrizIden[i][j] = 1.0;
            }
            else
            {
                matrizIden[i][j] = 0.0;
            }
        }
    }
}

// Receber uma matriz de ordem no máximo 2x2
// Retornar autovetores e autovalores
double autov(int ordem, double matriz[ordem][ordem])
{
    double matrizI[ordem][ordem];
    if(ordem > 2)
    {
        return 1;
    }
    else
    {
        // Fim
        return 1;
    }
}