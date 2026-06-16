#include <stdio.h>

int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }

int escal(){ // Método de resolução de sistemas lineares (Eliminação de Gauss);


// --------------------Chamadas de Funções-----------------------------------------------
// --------------------Sequência de Passos-----------------------------------------------
/*1°*/    identificar_pivos(matriz, 3); // Identifica o próximo pivô que sera utilizado na matriz.
/*2°*/    encontrar_fator_multi_pivo(); // Encontra o fator do pivô para igualá-lo a 1, PELA DIVISÃO [ PIVO = número que eu quero zerar / número acima ]
/*3°*/    zera_elementos_abaixo_pivo(); // Zera os elementos embaixo do pivô atual
// -------Realizar os passos acima para deixar a matriz escalonada--------
/*4°*/    substituicao_retroativa(); // exemplo, sobrou 3z = 9; você deve fazer z = 9/3; RESUMINDO, descobrir o valor das incognitas por de cima para baixo, agora que descobriu o Z, consegue descobrir o Y
// --------------------------------------------------------------------------------------


    return 0;
}



void identificar_pivos(int linhas, int colunas, matri[linhas][colunas]){ // função com responsabilidade de identificar o pivo mais simples das equações do sistema linear
    for(int i = 0; i < linhas; i++){ // Repetição para as linhas
        for(int j = 0; j < 3; j++){ // Repetição para as colunas
            if(matri[linhas][colunas] == 0){

            }
        }
    }

}


void zera_elementos_abaixo_pivo(){



}
