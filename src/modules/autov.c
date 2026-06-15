#include "../../include/autov.h"
#include <math.h>

// Objetivo:
// Calcular autovalores e autovetores
// Apenas para matrizes 2x2

// O static garante que a função somente existirá dentro desse arquivo C e não irá para a main
// Definir como static
static raizes bhaskara(double a, double b, double c)
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


// Receber uma matriz de ordem no máximo 2x2
// Retornar autovetores e autovalores
void autova(int ordem, double matriz[ordem][ordem], double *autova1, double *autova2)
{
    // Cálculo para os autovalores  
    if (ordem == 2)
    {
        double traco = matriz[0][0] + matriz[1][1];
        double detMatriz = det(2, matriz);
        raizes eq = bhaskara(1, traco, detMatriz);

        // Printar autova1 e autova2 na main
        *autova1 = *eq.delta1;
        *autova2 = *eq.delta2;
    }
    else if (ordem == 1)
    { 
        *autova1 = matriz[0][0];
    }
    else
    {
        return;
    }
}