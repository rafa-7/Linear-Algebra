#include <stdio.h>
#include <math.h>
#include "../../include/diag.h"
#include "../../include/det.h"
// #include "../include/autovetores.h" // <- Inclua o header da SUA função aqui se estiver em outro arquivo

int diag(double A[2][2], double D[2][2], double P[2][2]) {
    // 1. Calcular o Polinômio Característico: l^2 - Traço(A)*l + Det(A) = 0
    double traco = A[0][0] + A[1][1];
    double determinante = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);

    // Equação: l^2 - traco*l + determinante = 0
    double delta = (traco * traco) - (4 * determinante);

    // Se o delta for negativo, os autovalores são complexos (Não diagonalizável nos Reais)
    if (delta < -1e-9) {
        return 0; 
    }

    // Calcular os dois autovalores (lambda 1 e lambda 2)
    double l1 = (traco + sqrt(delta)) / 2.0;
    double l2 = (traco - sqrt(delta)) / 2.0;

    // Inicializa as matrizes com zero
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            D[i][j] = 0.0;
            P[i][j] = 0.0;
        }
    }

    // Preenche a matriz diagonal D com os autovalores encontrados
    D[0][0] = l1;
    D[1][1] = l2;

    // 2. CHAMADA DA SUA FUNÇÃO DE AUTOVETORES
    // Aqui você substitui pelo nome exato da sua função. 
    // Passamos a matriz A, os autovalores e a matriz P para ela preencher as colunas com os autovetores.
    
    // Exemplo de como chamaria para o primeiro autovalor (coluna 0 de P):
    // calcular_autovetor(A, l1, P, 0); 
    
    // Exemplo de como chamaria para o segundo autovalor (coluna 1 de P):
    // calcular_autovetor(A, l2, P, 1);

    // 3. Validação de segurança matemática
    // Verifica se os autovetores achados pela sua função são LI (Determinante de P != 0)
    double detP = (P[0][0] * P[1][1]) - (P[0][1] * P[1][0]);
    if (fabs(detP) < 1e-9) {
        return 0; // Se forem LD, a matriz não é diagonalizável
    }

    return 1; // Sucesso!
}