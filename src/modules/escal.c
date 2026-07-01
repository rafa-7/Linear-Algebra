#include <stdio.h>
#include <math.h>

#define MAX_ROWS 3 // define o tamanho máximo que podera ser aceito nos sistemas
#define MAX_COLS 3 // define o tamanho máximo que podera ser aceito nos sistemas


// ? Resolve um sistema linear de até 3x3 usando o método do escalonamento
// ? (Eliminação de Gauss).

// ? Retorno:
// ? 1 se encontrou solução única
// ? 0 se o sistema não tem solução única (indeterminado ou impossivel)

int escalonamento(double matriz_coeficientes[MAX_ROWS][MAX_COLS], double termos_constantes[MAX_ROWS], int linhas, int colunas, double saida[MAX_COLS]) {
    double aug[MAX_ROWS][MAX_COLS + 1]; // Matriz que receberá os valores da matriz original para poder ser feitas alterações, sem prejudicar a principal.
    int i, j, k;

    // Monta a matriz aumentada
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            aug[i][j] = matriz_coeficientes[i][j];
        }
        aug[i][colunas] = termos_constantes[i];
    }

    int linha_pivo_atual = 0;
    int posto = 0;

    // Varre coluna por coluna
    for (k = 0; k < colunas && linha_pivo_atual < linhas; k++) {

        // Encontra o maior elemento na coluna k, a partir da linha_pivo_atual para baixo
        int linhaPivo = linha_pivo_atual;
        double maiorValor = fabs(aug[linha_pivo_atual][k]);
        for (i = linha_pivo_atual + 1; i < linhas; i++) {
            if (fabs(aug[i][k]) > maiorValor) {
                maiorValor = fabs(aug[i][k]);
                linhaPivo = i;
            }
        }

        // Se o maior valor nesta coluna for zero, pulamos para a próxima coluna (Variável livre)
        if (maiorValor < 1e-12) {
            continue; 
        }

        // Troca as linhas, se necessário
        if (linhaPivo != linha_pivo_atual) {
            for (j = 0; j <= colunas; j++) {
                double tmp = aug[linha_pivo_atual][j];
                aug[linha_pivo_atual][j] = aug[linhaPivo][j];
                aug[linhaPivo][j] = tmp;
            }
        }

        // Zera os elementos abaixo do pivô na coluna k
        for (i = linha_pivo_atual + 1; i < linhas; i++) {
            double fator = aug[i][k] / aug[linha_pivo_atual][k];
            for (j = k; j <= colunas; j++) {
                aug[i][j] -= fator * aug[linha_pivo_atual][j];
            }
        }

        posto++;
        linha_pivo_atual++; // Avança para a próxima linha para buscar o próximo pivô
    }

    // ---- Substituição reversa (Só faz sentido se houver solução única) ----
    if (posto == colunas && posto == linhas) {
        for (i = linhas - 1; i >= 0; i--) {
            double soma = aug[i][colunas];
            for (j = i + 1; j < colunas; j++) {
                soma -= aug[i][j] * saida[j];
            }
            saida[i] = soma / aug[i][i];
        }
    }

    return posto; // Retorna o posto calculado para o main tomar as decisões
}