#include <stdio.h>
#include "../include/classificar_funcao.h"

void classificar_transformacao(int posto, int linhas, int colunas) {
    // Teorema do Núcleo e da Imagem: dim(V) = dim(Nucleo) + dim(Imagem)
    // Onde dim(V) é o número de colunas (incógnitas) e dim(Imagem) é o Posto.
    int dim_nucleo = colunas - posto;
    int dim_imagem = posto;

    printf("\n=============================================\n");
    printf("     ANALISE DA TRANSFORMACAO LINEAR\n");
    printf("        T: R^%d -------> R^%d\n", colunas, linhas);
    printf("=============================================\n");
    printf("-> Dimensao do Espaco de Partida (Dominio): %d\n", colunas);
    printf("-> Dimensao do Espaco de Chegada (Codominio): %d\n", linhas);
    printf("-> Dimensao da Imagem (Posto da Matriz): %d\n", dim_imagem);
    printf("-> Dimensao do Nucleo (Nulidade): %d\n", dim_nucleo);
    printf("---------------------------------------------\n");

    // 1. Verificação de Injetividade
    // Uma transformação é injetora se, e somente se, o Núcleo possui apenas o vetor nulo (dim = 0)
    int injetora = (dim_nucleo == 0);

    // 2. Verificação de Sobrejetividade
    // Uma transformação é sobrejetora se a Imagem for igual ao próprio espaço de chegada (dim_imagem == linhas)
    int sobrejetora = (dim_imagem == linhas);

    // Exibição dos Vereditos
    if (injetora) {
        printf("-> A funcao e INJETORA.\n");
        printf("   [Justificativa: dim(Nucleo) = 0. Apenas o vetor nulo vai para a origem].\n");
    } else {
        printf("-> A funcao NAO e Injetora.\n");
        printf("   [Justificativa: dim(Nucleo) > 0. Existem vetores nao-nulos mapeados no zero].\n");
    }

    if (sobrejetora) {
        printf("-> A funcao e SOBREJETORA.\n");
        printf("   [Justificativa: dim(Imagem) = %d, cobrindo todo o espaco R^%d].\n", dim_imagem, linhas);
    } else {
        printf("-> A funcao NAO e Sobrejetora.\n");
        printf("   [Justificativa: dim(Imagem) < %d. A imagem e um subespaco menor do que o destino].\n", linhas);
    }

    // 3. Verificação de Bijetividade (Isomorfismo)
    if (injetora && sobrejetora) {
        printf("\nRESULTADO FINAL: A transformacao e BIJETORA (Isomorfismo Linear).\n");
    } else {
        printf("\nRESULTADO FINAL: A transformacao NAO e Bijetora.\n");
    }
    printf("=============================================\n");
}