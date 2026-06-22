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
void autova(int ordem, double matriz[ordem][ordem], raizes *autovalores)
{
    raizes eq;
    // Cálculo para os autovalores  
    if (ordem == 2)
    {
        double traco = matriz[0][0] + matriz[1][1];
        double detMatriz = det(2, matriz);
        eq = bhaskara(1, -traco, detMatriz);
        autovalores->delta1 = eq.delta1;
        autovalores->delta2 = eq.delta2;   
    }
    else if (ordem == 1)
    {  
        autovalores->delta1 = matriz[0][0];
        return;
    }
    else
    {
        return;
    }
}

// Matrizes de ordem no máximo 2
// Receber autovalores e matriz para cálculo de autovetores
void autove(int ordem, double matriz[ordem][ordem], raizes *valores)
{
    // Qualquer número diferente de 0 se enquadra como um autovetor de matrizes 1x1
    if (ordem == 1) return 1;

    // Para o primeiro autovalor

    matriz[0][0] -= valores->delta1;
    matriz[1][1] -= valores->delta1;

    // Cálculo do sistema linear gerado . . . (escalonamento)

    // Para o segundo autovalor
    matriz[0][0] -= valores.delta2;
    matriz[1][1] -= valores.delta2;

    // Cálculo do sistema linear gerado . . . (escalonamento)

    return 1;


}