#include "../../include/autov.h"
#include "../../include/det.h"
#include "../../include/escal.h"
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
        deltas.possuiRaiz = false;
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

// 
void autove(int ordem, double matriz[ordem][ordem], raizes *valores)
{
    // Corrigido: condição de saída sem dupla negação confusa
    if (ordem == 1 || valores->possuiRaiz == false) return;

    // ========================================================
    // CÁLCULO DO AUTOVETOR PARA O PRIMEIRO AUTOVALOR (A1)
    // ========================================================
    double mat_aux1[MAX_ROWS][MAX_COLS] = {0};
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            mat_aux1[i][j] = matriz[i][j];
        }
    }
    
    mat_aux1[0][0] -= valores->delta1;
    mat_aux1[1][1] -= valores->delta1;

    double constantes1[MAX_ROWS] = {0.0, 0.0};
    double solucao1[MAX_COLS] = {0.0, 0.0};

    int classif1 = escal(mat_aux1, constantes1, 2, 2, solucao1);

    printf("-> Para o autovalor A1 = %.2lf:\n", valores->delta1);
    if (classif1 == 0) { 
        // Se a primeira linha for algo como [a, b], então ax + by = 0 -> x = (-b/a)y
        // Arbitrando y = 1.0, temos x = -b/a
        if (fabs(mat_aux1[0][0]) > 1e-12) {
            double x = -mat_aux1[0][1] / mat_aux1[0][0];
            printf("   Um autovetor associado e: v1 = (%.2lf, 1.00)\n\n", x);
        } else {
            // Se 'a' for zero, significa que by = 0 -> y = 0, e x é livre (x = 1)
            printf("   Um autovetor associado e: v1 = (1.00, 0.00)\n\n");
        }
    }

    // ========================================================
    // CÁLCULO DO AUTOVETOR PARA O SEGUNDO AUTOVALOR (A2)
    // ========================================================
    double mat_aux2[MAX_ROWS][MAX_COLS] = {0};
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            mat_aux2[i][j] = matriz[i][j];
        }
    }
    
    // Corrigido: Subtraindo o delta2 corretamente
    mat_aux2[0][0] -= valores->delta2;
    mat_aux2[1][1] -= valores->delta2;

    double constantes2[MAX_ROWS] = {0.0, 0.0};
    double solucao2[MAX_COLS] = {0.0, 0.0};

    int classif2 = escal(mat_aux2, constantes2, 2, 2, solucao2);

    // Corrigido: Printando as informações referentes ao A2
    printf("-> Para o autovalor A2 = %.2lf:\n", valores->delta2);
    if (classif2 == 0) { 
        if (fabs(mat_aux2[0][0]) > 1e-12) {
            double x = -mat_aux2[0][1] / mat_aux2[0][0];
            printf("   Um autovetor associado e: v2 = (%.2lf, 1.00)\n\n", x);
        } else {
            printf("   Um autovetor associado e: v2 = (1.00, 0.00)\n\n");
        }
    }
}