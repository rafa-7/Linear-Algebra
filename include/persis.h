#pragma once

char buffer_salvamento[2048] = {0}; 
char temp[512] = {0}; // Buffer auxiliar para concatenações

void salvar_em_arquivo(const char *titulo, const char *conteudo);

void exibir_historico();