// Teste as funções ou qualquer outra coisa aqui

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/det.h"
#include "../include/scanm.h"
#include "../include/autov.h"

int main()
{


    // Matriz pra teste 4x4
    double test4[4][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 10},
        {11, 12, 13, 14}
    };

    // Matriz pra teste 3x3
    double test3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matriz pra teste 2x2
    double test2[2][2] = {
        {2, 1},
        {0, 2}
    };

    // Matriz pra teste 1x1
    double test1[1][1] = {
        {1}
    };


    printf("O determinante dessa matriz é equivalente a %.1lf\n",det(2, test2));


    double res1;
    double res2;
    double res3;
    double res4;
    autova(2, test2, &res1, &res2);
    autova(1, test1, &res3, &res4);

    // Print de dois autovalores para matrizes 2x2
    printf("Os autovalores são: A1 = %.1lf\nA2 = %.1lf\n", res1, res2);

    // Print de um autovalor pra matrizes 1x1 (próprio valor presente na matriz)
    printf("Os autovalores são: A1 = %.1lf\n", res3);

    return 0;
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