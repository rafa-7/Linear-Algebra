#pragma once

// Maneira de retornar dois valores na função
typedef struct
{
    double delta1;
    double delta2;
} raizes;

raizes bhaskara(double a, double b, double c);

void autova(int ordem, double matriz[ordem][ordem], double *autova1, double *autova2);