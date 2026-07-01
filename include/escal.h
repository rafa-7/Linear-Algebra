#ifndef ESCALONAMENTO_H
#define ESCALONAMENTO_H

// "If Not Defined" (Se não estiver definido). O compilador lê a primeira linha: "A chave ESCALONAMENTO_H já existe?
// Se não existe, ele entra, define a chave na linha seguinte (#define ESCALONAMENTO_H) e lê o arquivo
// Se ele tentar ler esse header de novo mais tarde, o #ifndef vai dar falso e o compilador vai pular direto para o #endif

#define MAX_ROWS 3 // definir qual será o limite das linhas
#define MAX_COLS 3 // definir qual será o limite das colunas

// Apenas a linha de assinatura terminando com ponto e vírgula
int escalonamento(double matriz_coeficientes[MAX_ROWS][MAX_COLS], double termos_constantes[MAX_ROWS], int linhas, int colunas, double saida[MAX_COLS]);

#endif