#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/det.h"
#include "../include/scanm.h"
#include "../include/autov.h"


int main()
{
    bool tui = true;
    // Limpa a tela antes
    system("clear");

    // TUI (Terminal User-Interface)
    while (tui)
    {
        int escolha;

        

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
    
        printf("O que deseja fazer?\n");    
        printf("(1) Resolver sistemas lineares\n");
        printf("(2) Verificar Injetividade, Sobrejetividade e Bijetividade\n");
        printf("(3) Determinar bases\n");
        printf("(4) Calcular autovalores e/ou autovetores\n");
        printf("(5) Diagonalização de matrizes\n");
        printf("(0) Finalizar programa");
        printf("\n> ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
            {
                break;
            }
                
            case 2:
            {
                break;
            }
                
            case 3:
            {
                break;
            }
            
            case 4:
            {
                break;
            }
            
            case 5:
            {
                break;
            }
                
            case 0:
            {
                printf("Programa encerrado.\n\n");
                tui = false;
                break;
            }
                
            default:
            {
                printf("Digite um valor válido!\n\n");
                tui = false;
                break;
            }
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