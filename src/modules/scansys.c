#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../../include/scansys.h"

// Função auxiliar para encontrar a coluna de uma variável (ex: 'x' -> 0, 'y' -> 1)
int colunaVar(char var, char *variaveis, int *num_vars) 
{
    for (int i = 0; i < *num_vars; i++) 
    {
        if (variaveis[i] == var) return i;
    }
    // Se for uma variável nova, adiciona na lista
    if (*num_vars < MAX_VAR) 
    {
        variaveis[*num_vars] = var;
        (*num_vars)++;
        return *num_vars - 1;
    }
    return -1;
}

// Analisa uma única linha de equação (ex: "3y-x=1")
void scansys(char *str, double *linha_matriz, char *variaveis, int *num_vars, double *termo_constante) {
    int i = 0;
    int sinal = 1;
    bool posIgual = false;

    while (str[i] != '\0' && str[i] != '\n') 
    {
        // Ignora espaços mas NÃO reseta o sinal acumulado!
        if (isspace(str[i])) 
        { 
            i++; 
            continue; 
        }

        // Captura de sinais e igualdade
        if (str[i] == '+') 
        { 
            sinal = 1; 
            i++; 
            continue; 
        }

        if (str[i] == '-') 
        { 
            sinal = -1; 
            i++; 
            continue; 
        }

        if (str[i] == '=') 
        { 
            posIgual = true; 
            sinal = 1; 
            i++; 
            continue; 
        }

        // Se encontrar um número
        if (isdigit(str[i]) || str[i] == '.') 
        {
            char *fim_num;
            double valor = strtod(&str[i], &fim_num);
            i = fim_num - str; // Avança o índice para o fim do número

            // Pula possíveis espaços entre o número e a letra (ex: "2  x")
            while (isspace(str[i])) i++;

            if (isalpha(str[i])) 
            {
                int col = colunaVar(str[i], variaveis, num_vars);
                if (col != -1) 
                {
                    linha_matriz[col] += sinal * valor;
                }
                i++;
            } 
            else 
            {
                if (posIgual) 
                {
                    *termo_constante = sinal * valor;
                } 
                else 
                {
                    *termo_constante -= sinal * valor; 
                }
            }
        } 
        // Se encontrar uma letra isolada (ex: "+ z" ou "- y" ou "x")
        else if (isalpha(str[i])) 
        {
            int col = colunaVar(str[i], variaveis, num_vars);
            if (col != -1) 
            {
                linha_matriz[col] += sinal * 1.0;
            }
            i++;
        } 
        else 
        {
            i++;
        }
    }
}