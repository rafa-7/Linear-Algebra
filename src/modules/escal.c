#include <stdio.h>
#include <math.h>

#define MAX_ROWS 3
#define MAX_COLS 3

// Retorna: 
//  1 para Sistema Possível e Determinado (Solução Única)
//  0 para Sistema Possível e Indeterminado (Infinitas Soluções)
// -1 para Sistema Impossível (Nenhuma Solução)
int escal(double matriz_coeficientes[MAX_ROWS][MAX_COLS], double termos_constantes[MAX_ROWS], int linhas, int colunas, double saida[MAX_COLS]) {
    double aug[MAX_ROWS][MAX_COLS + 1];
    int i, j, k;

    // Inicializa o vetor de saída com zero
    for (j = 0; j < colunas; j++) saida[j] = 0.0;

    // Monta a matriz aumentada
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            aug[i][j] = matriz_coeficientes[i][j];
        }
        aug[i][colunas] = termos_constantes[i];
    }

    int linha_pivo_atual = 0;
    // Guardará em qual coluna está o pivô de cada linha (-1 se não houver)
    int coluna_pivo_por_linha[MAX_ROWS]; 
    for (i = 0; i < linhas; i++) coluna_pivo_por_linha[i] = -1;

    // Varre coluna por coluna
    for (k = 0; k < colunas && linha_pivo_atual < linhas; k++) {

        int linhaPivo = linha_pivo_atual;
        double maiorValor = fabs(aug[linha_pivo_atual][k]);
        for (i = linha_pivo_atual + 1; i < linhas; i++) {
            if (fabs(aug[i][k]) > maiorValor) {
                maiorValor = fabs(aug[i][k]);
                linhaPivo = i;
            }
        }

        if (maiorValor < 1e-12) {
            continue; // Coluna sem pivô (variável livre)
        }

        if (linhaPivo != linha_pivo_atual) {
            for (j = 0; j <= colunas; j++) {
                double tmp = aug[linha_pivo_atual][j];
                aug[linha_pivo_atual][j] = aug[linhaPivo][j];
                aug[linhaPivo][j] = tmp;
            }
        }

        // Zera os elementos abaixo do pivô
        for (i = linha_pivo_atual + 1; i < linhas; i++) {
            double fator = aug[i][k] / aug[linha_pivo_atual][k];
            for (j = k; j <= colunas; j++) {
                aug[i][j] -= fator * aug[linha_pivo_atual][j];
            }
        }

        coluna_pivo_por_linha[linha_pivo_atual] = k; // Registra a coluna do pivô
        linha_pivo_atual++;
    }

    int posto = linha_pivo_atual;

    // ---- Verificação de Sistema Impossível ----
    // Se houver qualquer linha onde todos os coeficientes são zero mas o termo independente NÃO é zero
    for (i = 0; i < linhas; i++) {
        bool linha_toda_zero = true;
        for (j = 0; j < colunas; j++) {
            if (fabs(aug[i][j]) > 1e-12) {
                linha_toda_zero = false;
                break;
            }
        }
        if (linha_toda_zero && fabs(aug[i][colunas]) > 1e-12) {
            return -1; // Sistema Impossível (SI)
        }
    }

    // ---- Verificação de Sistema Indeterminado ----
    if (posto < colunas) {
        return 0; // Sistema Possível e Indeterminado (SPI)
    }

    // ---- Substituição Reversa Corrigida (Apenas para SPD) ----
    for (i = posto - 1; i >= 0; i--) {
        int col_pivo = coluna_pivo_por_linha[i];
        if (col_pivo == -1) continue;

        double soma = aug[i][colunas];
        for (j = col_pivo + 1; j < colunas; j++) {
            soma -= aug[i][j] * saida[j];
        }
        saida[col_pivo] = soma / aug[i][col_pivo];
    }

    return 1; // Sistema Possível e Determinado (SPD)
}