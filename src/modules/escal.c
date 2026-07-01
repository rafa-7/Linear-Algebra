#include <stdio.h>
#include <math.h>

#define MAX_ROWS 3 // define o tamanho máximo que podera ser aceito nos sistemas
#define MAX_COLS 3 // define o tamanho máximo que podera ser aceito nos sistemas

// Agora a função retorna o Posto (Rank) da matriz, essencial para classificar o sistema depois
int escalonamento(double matriz_coeficientes[MAX_ROWS][MAX_COLS], double termos_constantes[MAX_ROWS], int linhas, int colunas, double saida[MAX_COLS]);


// ? Resolve um sistema linear de até 3x3 usando o método do escalonamento
// ? (Eliminação de Gauss).

// ? Retorno:
// ? 1 se encontrou solução única
// ? 0 se o sistema não tem solução única (indeterminado ou impossivel)

int main() {
    int linhas, colunas;
    double matriz_coeficientes[MAX_ROWS][MAX_COLS];
    double termos_constantes[MAX_ROWS];
    double saida[MAX_COLS];

    printf("Digite o numero de linhas (equacoes): ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas (incognitas): ");
    scanf("%d", &colunas);

    if (linhas < 1 || linhas > MAX_ROWS || colunas < 1 || colunas > MAX_COLS) {
        printf("Dimensoes invalidas. Maximo e 3x3.\n");
        return 1;
    }

    printf("Digite os coeficientes da matriz (%dx%d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz_coeficientes[%d][%d] = ", i, j);
            scanf("%lf", &matriz_coeficientes[i][j]);
        }
    }

    printf("Digite os termos constantes:\n");
    for (int i = 0; i < linhas; i++) {
        printf("termos_constantes[%d] = ", i);
        scanf("%lf", &termos_constantes[i]);
    }

    // Inicializa o vetor de saída com zero
    for (int j = 0; j < colunas; j++) saida[j] = 0.0;

    int posto = escalonamento(matriz_coeficientes, termos_constantes, linhas, colunas, saida);

    printf("\n--- Analise do Sistema ---\n");
    printf("Posto da Matriz: %d\n", posto);

    // Regras de classificação para qualquer matriz (Teorema de Rouché-Capelli)
    if (posto == colunas && posto == linhas) {
        printf("Sistema Possivel e Determinado (Solucao Unica).\n");
        for (int i = 0; i < colunas; i++) {
            printf("x%d = %.4f\n", i + 1, saida[i]);
        }
    } else if (posto < colunas && posto == linhas) {
        printf("Sistema Possivel e Indeterminado (Infinitas Solucoes).\n");
    } else {
        // Se houver uma linha de zeros na matriz de coeficientes, mas o termo constante correspondente for diferente de zero
        printf("Sistema Impossivel (Nao ha solucao) ou Indeterminado.\n");
    }

    return 0;
}

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