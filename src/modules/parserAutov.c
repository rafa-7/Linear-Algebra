#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ROWS 3
#define MAX_COLS 3

// Função auxiliar para mapear a variável ('x' -> Coluna 0, 'y' -> Coluna 1)
static int coluna_operador(char var) 
{
    if (var == 'x' || var == 'X') return 0;
    if (var == 'y' || var == 'Y') return 1;
    return -1; // Variável inválida para R²
}

// Analisa o operador completo digitado, ex: "(2x+2y, -x+4y)"
void verificaPonto(char *str, double matriz[MAX_ROWS][MAX_COLS]) 
{
    int i = 0;
    int linha_atual = 0; // Começa na linha 0 (antes da vírgula)
    int sinal = 1;

    // Zera a matriz 2x2 receptora antes de começar
    for(int i = 0; i < 2; i++) 
    {
        for(int j = 0; j < 2; j++)
        {
            matriz[i][j] = 0.0;
        } 
    }

    while (str[i] != '\0' && str[i] != '\n') 
    {
        // Ignora parênteses e espaços em branco
        if (str[i] == '(' || str[i] == ')' || isspace(str[i])) 
        { 
            i++; 
            continue; 
        }

        // Se encontrar uma vírgula, muda para a segunda componente (Linha 1)
        if (str[i] == ',') 
        {
            linha_atual = 1;
            sinal = 1; // Reseta o sinal padrão para positivo
            i++;
            continue;
        }

        // Captura de sinais
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

        // Se encontrar um número (coeficiente inteiro, decimal ou fração)
        if (isdigit(str[i]) || str[i] == '.') {
            char *fim_num;
            double valor = strtod(&str[i], &fim_num);
            i = fim_num - str;

            // Tratamento de Fração (ex: 5/2)
            if (str[i] == '/') 
            {
                i++; // Pula a barra '/'
                double denominador = strtod(&str[i], &fim_num);
                i = fim_num - str;
                
                if (denominador != 0) 
                {
                    valor /= denominador;
                }
            }

            // Pula eventuais espaços entre o número e a letra
            while (isspace(str[i]))
            {
                i++;
            } 

            // Associa à coluna da letra encontrada
            if (isalpha(str[i])) 
            {
                int col = coluna_operador(str[i]);

                if (col != -1 && linha_atual < 2) 
                {
                    matriz[linha_atual][col] += sinal * valor;
                }

                i++;
            }
        }
        // Se encontrar uma letra pura isolada (ex: "-y" ou "x")
        else if (isalpha(str[i])) 
        {
            int col = coluna_operador(str[i]);

            if (col != -1 && linha_atual < 2) 
            {
                matriz[linha_atual][col] += sinal * 1.0;
            }

            i++;
        } 
        else 
        {
            i++;
        }
    }
}