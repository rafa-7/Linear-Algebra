#include "../../include/autov.h"
#include "../../include/det.h"
#include <math.h>
#include <stdio.h>

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
raizes autova(int ordem, double matriz[ordem][ordem], double *autova1, double *autova2)
{
    // Cálculo para os autovalores  
    if (ordem == 2)
    {
        double traco = matriz[0][0] + matriz[1][1];
        double detMatriz = det(2, matriz);
        raizes eq = bhaskara(1, traco, detMatriz);
        return eq;
    }
    else if (ordem == 1)
    { 
        raizes va1; 
        va1.delta1 = matriz[0][0];
        
        return va1;

    }
    else
    {
        return;
    }
}

// Matrizes de ordem no máximo 2
// Receber autovalores e matriz para cálculo de autovetores
double autove(int ordem, double matriz[ordem][ordem], raizes valores)
{
    return 1;


}