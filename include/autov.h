#pragma once

// Maneira de retornar dois valores na função
typedef struct
{
    double delta1;
    double delta2;
} raizes;

raizes autova(int ordem, double matriz[ordem][ordem], double *autova1, double *autova2);

double autove(int ordem, double matriz[ordem][ordem], raizes valores);