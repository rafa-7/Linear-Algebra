#include <stdio.h>

// !------------------------------------------------------------------
// TODO : Método do Escalonamento para resolução de sistemas lineares.
// !------------------------------------------------------------------
// TODO : Tamanhos aceitos: 2x2, 3x3, 3x2, 2x3.
// !------------------------------------------------------------------

void identificar_pivos(int linhas, int colunas, int matri[linhas][colunas]);

// ---------------------
int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
};
// ---------------------
int main(){


identificar_pivos(3, 3, matriz);

    return 0;
}

int escal(){ // Método de resolução de sistemas lineares (Eliminação de Gauss);


// --------------------Chamadas de Funções-----------------------------------------------
// --------------------Sequência de Passos-----------------------------------------------
/*1°*/    identificar_pivos(linha, coluna, matriz); // Identifica o próximo pivô que sera utilizado na matriz.
/*2°*/    encontrar_fator_multi_pivo(); // Encontra o fator do pivô para igualá-lo a 1, PELA DIVISÃO [ PIVO = número que eu quero zerar / número acima ]
/*3°*/    zera_elementos_abaixo_pivo(); // Zera os elementos embaixo do pivô atual
// -------Realizar os passos acima para deixar a matriz escalonada--------
/*4°*/    substituicao_retroativa(); // exemplo, sobrou 3z = 9; você deve fazer z = 9/3; RESUMINDO, descobrir o valor das incognitas por de cima para baixo, agora que descobriu o Z, consegue descobrir o Y
// --------------------------------------------------------------------------------------


    return 0;
}

void identificar_pivos(int linhas, int colunas, matri[linhas][colunas]){ // função com responsabilidade de identificar o maior número em valor absoluto para ser pivô.
   
    int maior_indice = matri[0][0]; // essa váriavel vai segurar o primeiro indice da matriz e vai comparar ele com os outos valores

    for(int i = 0; i < linhas; i++){ // for para percorrer as linhas
        for(int j = 0; j < colunas; i++){ // for para percorrer as colunas

            if(matri[i][j] == 0){
                trocar_linha(); // TODO : Terminar de escrever essa função para validar a condicional.
            }

            if(matri[i][j] < 0 && (matri[i][j] * -1) >= maior_indice){  // condicional que verifica o valor do número absoluto e confere se ele é maior que o número contido na variavel "maior número", caso ele seja maior o valor da variavel sera substituido.
                maior_indice = matri[i][j];

            }
        }
   }
}


void zera_elementos_abaixo_pivo(){



}
