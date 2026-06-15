#include <stdio.h>
#include <string.h>
#include "../include/det.h"
#include "../include/scanm.h"
#include "../include/autov.h"

/**
 *    .____    .__                                             
 *    |    |   |__| ____   ____ _____ _______                  
 *    |    |   |  |/    \_/ __ \\__  \\_  __ \                 
 *    |    |___|  |   |  \  ___/ / __ \|  | \/                 
 *    |_______ \__|___|  /\___  >____  /__|                    
 *            \/       \/     \/     \/                        
 *       _____  .__                       ___.                 
 *      /  _  \ |  |    ___________   ____\_ |______________   
 *     /  /_\  \|  |   / ___\_  __ \_/ __ \| __ \_  __ \__  \  
 *    /    |    \  |__/ /_/  >  | \/\  ___/| \_\ \  | \// __ \_
 *    \____|__  /____/\___  /|__|    \___  >___  /__|  (____  /
 *            \/     /_____/             \/    \/           \/ 
*/

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
        {1, 2},
        {3, 4}
    };

    // Matriz pra teste 1x1
    double test1[1][1] = {
        {1}
    };

    printf("O determinante dessa matriz é equivalente a %lf\n",det(2, test2));


    double res1;
    double res2;
    autova(2, test2, &res1, &res2);

    printf("Os autovalores são: A1 = %lf\nA = 2 %lf", res1, res2);

    return 0;
}