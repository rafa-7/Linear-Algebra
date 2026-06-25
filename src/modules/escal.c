#include <stdio.h>

// !------------------------------------------------------------------
// TODO : Método do Escalonamento para resolução de sistemas lineares.
// !------------------------------------------------------------------
// TODO : Tamanhos aceitos: 2x2, 3x3, 3x2, 2x3.
// !------------------------------------------------------------------

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

// TODO :--------------------Chamadas de Funções-----------------------------------------------
// Todo :--------------------Sequência de Passos-----------------------------------------------
//    copiar_matriz_temporaria();
//    identificar_pivo(); // Identifica o próximo pivô que sera utilizado na matriz.
//    encontrar_fator_multi_pivo(); // Encontra o fator do pivô para igualá-lo a 1, PELA DIVISÃO [ PIVO = número que eu quero zerar / número acima ]
//    zera_elementos_abaixo_pivo(); // Zera os elementos embaixo do pivô atual
// Todo :---------Realizar os passos acima para deixar a matriz escalonada---------------------
//    substituicao_retroativa(); // exemplo, sobrou 3z = 9; você deve fazer z = 9/3; RESUMINDO, descobrir o valor das incognitas por de cima para baixo, agora que descobriu o Z, consegue descobrir o Y
// --------------------------------------------------------------------------------------

//! ------------Variaveis-------------

int matriz_alteravel[][]; // matriz que deverá compor os valores da matriz que será escalonada.
int pivo;

int copia_matriz(int linha, int coluna, int matriz[linha][coluna]){// ? Função para copiar os valores da matriz que será escalonada e inserir em uma matriz alteravel.
    for(int i = 0; i< linha; i++){ 
        for(int j = 0; j< coluna; j++){
            matriz_alteravel[i][j] = matriz[linha][coluna];
        }
    }
    return 0;
}
int identificar_pivo(int linha, int coluna, int matriz[linha][coluna]){

    for(int i = 0; i< linha; i++){ //for para colunas.
        for(int j = 0; j< coluna; j++){ // for para linhas.
            
            if(matriz[linha][coluna] == 0 && matriz[linha + 1][coluna] !0 ){
                trocar_linhas(matriz[linha][coluna],matriz[linha][coluna]);
            }
            // ! OBS: Criar uma função que verifica se os valores abaixo do pivô estão zerados para poder definir o próximo pivô.
        }
    }

    return 0;
}
int trocar_linhas(int linha, int coluna, int matriz[linha][coluna]){

}