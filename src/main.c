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
    // Teste de determinante
    double show[4][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 10},
        {11, 12, 13, 14}
    };

    printf("O determinante dessa matriz é equivalente a %lf\n",det(4, show));

    // x² - 3x + 2 = 0
    // Essa retorna duas raízes inteiras (1 e 2), para teste
    
    raizes equacao = bhaskara(1.0, -3.0, 2.0);
    printf("%lf\n", equacao.delta1);
    printf("%lf\n", equacao.delta2);

    return 0;
}