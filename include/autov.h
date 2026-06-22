#pragma once

// Maneira de retornar dois valores na função
typedef struct
{
    double delta1;
    double delta2;
} raizes;

void autova(int ordem, double matriz[ordem][ordem], raizes *autovalores);

void autove(int ordem, double matriz[ordem][ordem], raizes *valores);