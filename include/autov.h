#pragma once

// Maneira de retornar dois valores na função
typedef struct
{
    double delta1;
    double delta2;
} raizes;

raizes bhaskara(double a, double b, double c);