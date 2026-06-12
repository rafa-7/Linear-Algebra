#include "../../include/autov.h"
#include <math.h>

// Objetivo:
// Calcular autovalores e autovetores
// Apenas para matrizes 2x2


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