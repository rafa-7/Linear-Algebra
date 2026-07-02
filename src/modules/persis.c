#include <stdio.h>

void salvar_em_arquivo(const char *titulo, const char *conteudo) {
    FILE *arquivo = fopen("resultados_algebra.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    fprintf(arquivo, "=========================================================\n");
    fprintf(arquivo, "OPERAÇÃO: %s\n", titulo);
    fprintf(arquivo, "=========================================================\n");
    fprintf(arquivo, "%s", conteudo);
    fprintf(arquivo, "\n\n");
    fclose(arquivo);
    printf("-> Resultado salvo com sucesso em 'resultados_algebra.txt'!\n");
}

// ============================================================================
// 📖 NOVA FUNÇÃO: CONSULTAR O ARQUIVO DE HISTÓRICO
// ============================================================================
void exibir_historico() {
    FILE *arquivo = fopen("resultados_algebra.txt", "r");
    
    // Se o arquivo não existir, significa que nada foi salvo ainda
    if (arquivo == NULL) {
        printf("\n[Aviso]: Nenhum historico encontrado ou o arquivo ainda nao foi criado.\n");
        return;
    }

    printf("\n=========================================================\n");
    printf("             HISTORICO DE OPERACOES SALVAS               \n");
    printf("=========================================================\n");

    char caractere;
    // Lê o arquivo caractere por caractere até chegar ao Fim do Arquivo (EOF)
    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere);
    }
    
    printf("=========================================================\n");
    fclose(arquivo);
}