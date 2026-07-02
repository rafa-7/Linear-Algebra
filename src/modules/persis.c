#include <stdio.h>

void salvar_em_arquivo(const char *titulo, const char *conteudo) {
    FILE *arquivo = fopen("resultados_algebra.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    fprintf(arquivo, "OPERAÇÃO: %s\n", titulo);
    fprintf(arquivo, "%s", conteudo);
    fprintf(arquivo, "\n\n");
    fclose(arquivo);
    printf("-> Resultado salvo com sucesso em 'resultados_algebra.txt'!\n");
}

void exibir_historico() {
    FILE *arquivo = fopen("resultados_algebra.txt", "r");
    
    // Se o arquivo não existir, significa que nada foi salvo ainda
    if (arquivo == NULL) {
        printf("\n[Aviso]: Nenhum historico encontrado ou o arquivo ainda nao foi criado.\n");
        return;
    }

    printf("HISTORICO DE OPERACOES SALVAS\n");

    char caractere;
    // Lê o arquivo caractere por caractere até chegar ao Fim do Arquivo (EOF)
    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere);
    }
    
    fclose(arquivo);
}