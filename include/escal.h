#pragma once

#define MAX_ROWS 3 // definir qual será o limite das linhas
#define MAX_COLS 3 // definir qual será o limite das colunas

// Apenas a linha de assinatura terminando com ponto e vírgula
int escal(double matriz_coeficientes[MAX_ROWS][MAX_COLS], double termos_constantes[MAX_ROWS], int linhas, int colunas, double saida[MAX_COLS]);
