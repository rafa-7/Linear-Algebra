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
        "(7) Mostrar resultados na memória\n"
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
            determinante,
            memoriaArq
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
                int linhas, colunas;
                double matriz_prop[MAX_ROWS][MAX_COLS] = {
                    {0}
                };

                int modo_leitura;

                printf("Como deseja inserir a Transformacao Linear T:R^n -> R^m?\n");
                printf("(1) Digitar a expressao completa - Ex: (3x - 2.5y, 0.5y)\n");
                printf("(2) Digitar as dimensoes e os coeficientes manualmente\n> ");
                scanf("%d", &modo_leitura);
                getchar(); // Limpa o buffer do '\n'

                if (modo_leitura == 1) {
                    char expressao[100];
                    printf("\nDigite o operador linear no formato (2x+y, x-y, 3z):\n> ");
                    fgets(expressao, sizeof(expressao), stdin);

                    // Reutiliza o seu parser que varre strings!
                    // Nota: Para operadores genéricos, certifique-se de que o parser conte 
                    // quantas linhas (vírgulas + 1) e colunas foram identificadas dinamicamente.
                    // Para o R^2 -> R^2 fixo da função anterior, linhas=2 e colunas=2.
                    linhas = 2; 
                    colunas = 2;
                    verificaPonto(expressao, matriz_prop);
                } 
                else {
                    printf("Defina a dimensao do espaco de CHEGADA (m) [Numero de Linhas]:\n> ");
                    scanf("%d", &linhas);
                    printf("Defina a dimensao do espaco de PARTIDA (n) [Numero de Colunas]:\n> ");
                    scanf("%d", &colunas);

                    if (linhas < 1 || linhas > MAX_ROWS || colunas < 1 || colunas > MAX_COLS) {
                        printf("Dimensoes invalidas. O limite maximo e %dx%d.\n\n", MAX_ROWS, MAX_COLS);
                        break;
                    }

                    // Usa sua função padrão para ler a matriz
                    scanm(linhas, matriz_prop); 
                }

                // Exibe a matriz gerada para conferência
                printf("\n--- Matriz Associada a Transformacao ---\n");
                for (int i = 0; i < linhas; i++) {
                    printf("  [ ");
                    for (int j = 0; j < colunas; j++) {
                        printf("%6.2f ", matriz_prop[i][j]);
                    }
                    printf("]\n");
                }
                printf("----------------------------------------\n");

                // Para rodar o escal(), precisamos simular vetores auxiliares de termos constantes e saída
                double constantes_ficticias[MAX_ROWS] = {0};
                double saida_ficticia[MAX_COLS] = {0};
                
                // O escalonamento vai triangular a matriz e retornar a quantidade de pivôs reais (O POSTO)
                int posto_calculado = escal(matriz_prop, constantes_ficticias, linhas, colunas, saida_ficticia);

                // --- CHAMADA DA SUA FUNÇÃO DE CLASSIFICAÇÃO ---
                classificar_transformacao(posto_calculado, linhas, colunas);

                tui = false;
                break;
            }
            
            // Determinar bases
            case determinarBases:
            {
                int dimensao, num_vetores;

                printf("Qual a dimensao do espaco? (2 para R^2, 3 para R^3):\n> ");
                scanf("%d", &dimensao);

                if (dimensao < 1 || dimensao > MAX_ROWS) 
                {
                    printf("Dimensao nao suportada. O maximo e %d.\n\n", MAX_ROWS);
                    break;
                }

                printf("Quantos vetores tem o conjunto?\n> ");
                scanf("%d", &num_vetores);

                // Matriz onde cada linha representa um vetor inserido pelo usuário
                double matriz_base[MAX_ROWS][MAX_COLS] = {
                    {0}
                };

                printf("\nDigite os componentes de cada vetor:\n");
                for (int i = 0; i < num_vetores; i++) 
                {
                    printf("Vetor V%d:\n", i + 1);
                    for (int j = 0; j < dimensao; j++) 
                    {
                        printf("  Componente %d: ", j + 1);
                        scanf("%lf", &matriz_base[i][j]);
                    }
                }

                if (num_vetores == dimensao) 
                {
                    double determinante_base = det(dimensao, matriz_base);

                    // Se o determinante for diferente de zero, os vetores sao LI e geram o espaco
                    if (fabs(determinante_base) > 1e-12) 
                    {
                        printf("\nO conjunto é uma base!\n");
                        printf("Motivo: O numero de vetores e igual a dimensao (%d) e eles sao\n", dimensao);
                        printf("Linearmente Independentes, pois o Determinante da matriz vira %.2lf.\n\n", determinante_base);
                    } 
                    // Se o determinante for zero, eles sao LD (nao formam base)
                    else 
                    {
                        printf("\nNão é uma base!\n");
                        printf("Motivo: Os vetores sao Linearmente Dependentes (Determinante = 0).\n");
                        printf("Existe redundancia linear entre os vetores digitados.\n\n");
                        
                        // Rodamos o escalonamento para achar o subconjunto LI
                        printf("Analise Extra (Subconjunto LI)\n");
                        double constantes[MAX_ROWS] = {0};
                        double saida[MAX_COLS] = {0};
                        
                        // O escalonamento vai zerar as linhas redundantes (LD)
                        int posto = escal(matriz_base, constantes, num_vetores, dimensao, saida);
                        printf("A dimensao do subconjunto LI maximo e %d (Posto da matriz).\n", posto);
                        printf("A matriz escalonada gerada foi:\n");
                        for (int i = 0; i < num_vetores; i++) 
                        {
                            printf("  [ ");
                            for (int j = 0; j < dimensao; j++) 
                            {
                                printf("%6.2f ", matriz_base[i][j]);
                            }
                            printf("]\n");
                        }
                        printf("Dica para completar: Adicione vetores canonicos nas direcoes das linhas nulas.\n\n");
                    }
                } 
                else 
                {
                    printf("\nNão é uma base!\n");
                    printf("Motivo Estrito: A quantidade de vetores (%d) e diferente da dimensao do espaco (%d).\n", num_vetores, dimensao);
                    
                    if (num_vetores > dimensao) 
                    {
                        printf("O conjunto e Linearmente Dependente (LD) por excesso de vetores.\n");
                        printf("Para extrair uma base, voce precisa remover os vetores redundantes via escalonamento.\n\n");
                    } 
                    else 
                    {
                        printf("O conjunto e insuficiente para gerar o espaco tridimensional (Faltam vetores).\n");
                        printf("Para transformar em base, voce precisa completar o conjunto adicionando mais %d vetor(es) LI.\n\n", dimensao - num_vetores);
                    }
                }
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

                if (modo_leitura == 1) 
                {
                    char expressao[100];
                    printf("\nDigite o operador (Aceita fracoes como 2/3 e espacos):\n> ");
                    fgets(expressao, sizeof(expressao), stdin);

                    // Filtra os valores da string e preenche matrizAtv
                    verificaPonto(expressao, matrizAtv);
                } 
                else 
                {
                    printf("Digite a ordem da matriz quadrada (nxn)\n> ");
                    scanf("%d", &ordem);
                    if (ordem < 1 || ordem > 2) 
                    {
                        printf("Ordem invalida.\n\n");
                        break;
                    }
                    scanm(ordem, matrizAtv);
                }

                // Exibe a matriz extraída para conferência do usuário
                // printf("\n--- Matriz do Operador Gerada ---\n");
                // printf("[ %6.2f  %6.2f ]\n", matrizAtv[0][0], matrizAtv[0][1]);
                // printf("[ %6.2f  %6.2f ]\n", matrizAtv[1][0], matrizAtv[1][1]);
                // printf("---------------------------------\n");

                // Executa os cálculos que criamos anteriormente
                autova(ordem, matrizAtv, &autovae);

                if (autovae.possuiRaiz == false) 
                {
                    printf("\nNao existem autovalores reais para este operador (Raizes Complexas).\n\n");
                } 
                else 
                {
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

        // Limpa a tela no final, o ponto é armazenar as respostas anteriores no arquivo
        #ifdef _WIN32
        system("cls");
        #elif __linux__
        system("clear");
        #endif
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