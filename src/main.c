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

                int linhas, colunas;
                double matriz_coeficientes[MAX_ROWS][MAX_COLS];
                double termos_constantes[MAX_ROWS];
                // double saida[MAX_COLS];

                printf("Digite o numero de linhas (equacoes): ");
                scanf("%d", &linhas);
                printf("Digite o numero de colunas (incognitas): ");
                scanf("%d", &colunas);

                if (linhas < 1 || linhas > MAX_ROWS || colunas < 1 || colunas > MAX_COLS) 
                {
                    printf("Dimensoes invalidas. Maximo e 3x3.\n");
                    return 1;
                }

                printf("Digite os coeficientes da matriz (%dx%d):\n", linhas, colunas);
                for (int i = 0; i < linhas; i++) 
                {
                    for (int j = 0; j < colunas; j++) 
                    {
                        printf("matriz_coeficientes[%d][%d] = ", i, j);
                        scanf("%lf", &matriz_coeficientes[i][j]);
                    }
                }

                printf("Digite os termos constantes:\n");
                for (int i = 0; i < linhas; i++) 
                {
                    printf("termos_constantes[%d] = ", i);
                    scanf("%lf", &termos_constantes[i]);
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
                int ordem;

                // Tipo raizes declarado no autov.h
                raizes autovae;

                printf("Digite a ordem da matriz quadrada (nxn)\n> ");
                scanf("%d", &ordem);

                if (ordem < 1 || ordem > 2)
                {
                    printf("Digite uma ordem válida!\n\n");
                    break;
                }

                double matrizAtv[ordem][ordem];
                scanm(ordem, matrizAtv);
                autova(ordem, matrizAtv, &autovae);
                autove(ordem, matrizAtv, &autovae);

                if (ordem == 1)
                {
                    printf("Os autovalores são: A1 = %.2lf\n", autovae.delta1);
                    printf("OS autovetores são qualquer valor diferente de 0!\n\n");
                }
                else
                {
                    
                    printf("Os autovalores são: A1 = %.2lf\n"
                        "A2 = %.2lf\n\n", autovae.delta1, autovae.delta2
                    );

                    printf("OS autovetores são: A1 = %.2lf\n" 
                        "A2 = %.2lf\n\n", autovae.delta1, autovae.delta2
                    );

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

        printf("Deseja armazenar o resultado?\n> ");
        scanf(" %c", &armazenar);

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