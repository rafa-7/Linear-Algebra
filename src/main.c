#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../include/det.h"
#include "../include/scanm.h"
#include "../include/autov.h"
#include "../include/escal.h"
#include "../include/diag.h"
#include "../include/classificar_funcao.h"
#include "../include/scansys.h"
#include "../include/parserAutov.h"

int main()
{
    bool tui = true;
    
    // Verifica o sistema operacional e limpa a tela antes
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif

    // TUI (Terminal User-Interface) 
    while (tui)
    {
        int escolha;
        char continuar;
        char armazenar;

        

        printf("\n"
            "       _____  .__                ___.                  \n"
            "      /  _  \\ |  |    ____   ____\\_ |______________   \n"
            "     /  /_\\  \\|  |   / ___\\_/ __ \\| __ \\_  __ \\__  \\  \n"
            "    /    |    \\  |__/ /_/  >  ___/| \\_\\ \\  | \\// __ \\_\n"
            "    \\____|__  /____/\\___  / \\___  >___  /__|  (____  /\n"
            "            \\/     /_____/      \\/    \\/           \\/ \n"
            "    .____     .__                                      \n"
            "    |    |    |__| ____   ____ _____ _______           \n"
            "    |    |    |  |/    \\_/ __ \\\\__  \\\\_  __ \\          \n"
            "    |    |___|  |   |  \\  ___/ / __ \\|  | \\/          \n"
            "    |_______ \\__|___|  /\\___  >____  /__|             \n"
            "            \\/       \\/     \\/     \\/                 \n"
        "\n");
    
        // Apesar de muito pouco, declarar um printf assim economiza processamento

 // Apesar de muito pouco, declarar um printf assim economiza processamento

        printf("O que deseja fazer?\n"
        "(1) Resolver sistemas lineares\n"
        "(2) Dimensão do núcleo, Dimensão da imagem, Verificar Injetividade, Sobrejetividade e Bijetividade\n"
        "(3) Determinar bases\n"
        "(4) Calcular autovalores e/ou autovetores\n"
        "(5) Diagonalização de matrizes\n"
        "(6) Calcular determinantes\n"
        "(0) Finalizar programa\n"
        "\n> ");
        
        scanf("%d", &escolha);

        typedef enum {
            fim = 0,
            resolverSistemas,
            verificarProp, // Núcleo, imagem, injetividade...
            determinarBases,
            calcAutov,
            diagonalizacao,
            determinante
        } Menu;
        
        Menu opcao = (Menu) escolha; // Converte o int para o tipo do Enum

        switch (opcao)
        {
            // Resolver sistemas lineares
            case resolverSistemas:
            {

                int linhas;
                int num_vars = 0;
                char variaveis[MAX_COLS] = {0}; // Guarda a ordem encontrada (ex: ['x', 'y'])
                double saida[MAX_COLS] = {0}; // Vetor que receberá as respostas do sistema
                
                // Armazena o resultado nessa variável
                double matriz_coeficientes[MAX_ROWS][MAX_COLS] = {
                    {0}
                };
                double termos_constantes[MAX_ROWS] = {0};

                printf("Quantas equacoes tem o sistema linear?\n> ");
                scanf("%d", &linhas);
                getchar(); // Limpa o '\n' deixado pelo scanf para não quebrar o fgets

                if (linhas < 1 || linhas > MAX_ROWS) 
                {
                    printf("Quantidade de linhas invalida.\n");
                    break;
                }

                printf("Digite as equacoes (Ex: 4x + y = 2):\n");
                for (int i = 0; i < linhas; i++) 
                {
                    char equacao_str[100];
                    printf("Equacao %d: ", i + 1);
                    fgets(equacao_str, sizeof(equacao_str), stdin);
                    
                    // Extrai os coeficientes diretamente da string digitada
                    scansys(equacao_str, matriz_coeficientes[i], variaveis, &num_vars, &termos_constantes[i]);
                }

                int classificacao = escal(matriz_coeficientes, termos_constantes, linhas, num_vars, saida);

                if (classificacao == 1) 
                {
                    printf("Sistema Possivel e Determinado (SPD)\n");
                    printf("Solucao unica encontrada:\n");
                    
                    // Mapeia o resultado numérico de volta para a letra digitada pelo usuário
                    for (int j = 0; j < num_vars; j++) 
                    {
                        printf("%c = %.4f\n", variaveis[j], saida[j]);
                    }
                    printf("\n");
                } 
                else if (classificacao == 0) 
                {
                    printf("Sistema Possivel e Indeterminado (SPI)\n");
                    printf("O sistema possui infinitas solucoes (Variaveis livres detectadas).\n\n");
                } 
                else if (classificacao == -1) 
                {
                    printf("Sistema Impossivel (SI)\n");
                    printf("O sistema nao possui solucao (Equacoes contraditorias).\n\n");
                }


                tui = false;
                break;
            }
             
            // Verificar Injetividade, Sobrejetividade e Bijetividade
            case verificarProp:
            {
                tui = false;
                break;
            }
            
            // Determinar bases
            case determinarBases:
            {
                tui = false;
                break;
            }
            
            // Calcular autovalores e/ou autovetores
            case calcAutov:
            {
                int ordem = 2; // Forçado em 2 para os exemplos do R² da imagem
                raizes autovae;
                double matrizAtv[MAX_ROWS][MAX_COLS] = {
                    {0}
                };
                int modo_leitura;

                printf("Como deseja inserir o operador linear T:R^2 -> R^2?\n");
                printf("(1) Digitar a expressao completa - Ex: (2x+2y, -x+4y)\n");
                printf("(2) Digitar os coeficientes da matriz um por um\n> ");
                scanf("%d", &modo_leitura);
                getchar(); // Limpa o buffer de quebra de linha

                if (modo_leitura == 1) {
                    char expressao[100];
                    printf("\nDigite o operador (Aceita fracoes como 5/2 e espacos):\n> ");
                    fgets(expressao, sizeof(expressao), stdin);

                    // Filtra os valores da string e preenche matrizAtv
                    analisar_operador(expressao, matrizAtv);
                } 
                else {
                    printf("Digite a ordem da matriz quadrada (nxn)\n> ");
                    scanf("%d", &ordem);
                    if (ordem < 1 || ordem > 2) {
                        printf("Ordem invalida.\n\n");
                        break;
                    }
                    scanm(ordem, matrizAtv);
                }

                // Exibe a matriz extraída para conferência do usuário
                printf("\n--- Matriz do Operador Gerada ---\n");
                printf("[ %6.2f  %6.2f ]\n", matrizAtv[0][0], matrizAtv[0][1]);
                printf("[ %6.2f  %6.2f ]\n", matrizAtv[1][0], matrizAtv[1][1]);
                printf("---------------------------------\n");

                // Executa os cálculos que criamos anteriormente
                autova(ordem, matrizAtv, &autovae);

                if (autovae.possuiRaiz == false) {
                    printf("\nNao existem autovalores reais para este operador (Raizes Complexas).\n\n");
                } else {
                    printf("\nOs autovalores encontrados sao:\n");
                    printf("A1 = %.2lf\n", autovae.delta1);
                    printf("A2 = %.2lf\n\n", autovae.delta2);

                    printf("Calculando os autovetores associados:\n");
                    autove(ordem, matrizAtv, &autovae);
                }

                tui = false;
                break;
            }
            
            // Diagonalização de matrizes
            case diagonalizacao:
            {
                tui = false;
                break;
            }

            // Calcular determinantes
            case determinante:
            {
                int ordem;
                

                printf("Digite a ordem da matriz quadrada (nxn)\n> ");
                scanf("%d", &ordem);

                if (ordem < 1)
                {
                    printf("Digite uma ordem válida!\n\n");
                    break;
                }
                double matrizDet[ordem][ordem];

                printf("Digite a matriz:\n");

                scanm(ordem, matrizDet);
                printf("\nO determinante da matriz é: %.2lf\n\n", det(ordem, matrizDet));

                break;


            }
                
            case 0:
            {
                printf("\nPrograma encerrado.\n");
                tui = false;
                return 0;
                break;
            }
                
            default:
            {
                printf("Digite um valor válido!\n\n");
                tui = false;
                break;
            }
        }

        printf("Deseja armazenar o resultado? (y/n)\n> ");
        scanf(" %c", &armazenar);

        if (armazenar = 'y')
        {

        }
        else
        {
            continue;
        }

        printf("Deseja voltar ao menu inicial? (y/n)\n> ");
        scanf(" %c", &continuar);

        if (continuar == 'y')
        {
            tui = true;
        }
        else
        {
            tui = false;
        }
        
    }
}


/*
⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄
⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁
⠀⠀⣀⣼⠷⠀⠀⠁ 𝑺𝑬𝑬 𝒀𝑶𝑼 𝑺𝑷𝑨𝑪𝑬
⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀𝑪𝑶𝑾𝑩𝑶𝒀 . . .
⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⠏⠉
⠀⠀⠀⠀⠸⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠟⠁⠀⠀⠀⠀ ⠀⠀
*/