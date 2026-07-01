#pragma once

#define MAX_LINHAS 10
#define MAX_VAR 10

int colunaVar(char var, char *variaveis, int *num_vars);

void scansys(char *str, double *linha_matriz, char *variaveis, int *num_vars, double *termo_constante);