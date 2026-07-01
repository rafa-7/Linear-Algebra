# Verificação do sistema operacional
ifeq ($(OS),Windows_NT)
    # Comandos para Windows
    RM = del /Q /F
    # Converte barras normais para invertidas apenas se o comando 'del' exigir
	# Exigência do windows
    FIX_PATH = $(subst /,\\,$1)
    EXEC_EXT = .exe
else
    # Comandos para Linux/Sistemas UNIX em geral
    RM = rm -f
    FIX_PATH = $1
    EXEC_EXT =
endif

# Para rodar no windows utilize mingw32-make
# Para rodar o clean no windows utilize mingw32-make clean
# Para troca de compilador, utilize essa variável
CC=gcc

# Tudo que necessita de compilação se encontra nessa variável
# Apenas altere aqui caso queira adicionar ou retirar alguma função
# Para trocar para o arquivo de testes, troque a main.o pelo playground.o
OBJS=build/det.o build/autov.o build/scanm.o build/escal.o build/scansys.o build/main.o

# Todas as flags para compilação
# -Wall mostra todos os alertas
# -I procura pelos headers na pasta include
CFLAGS=-Wall -Iinclude

# Binário final
# Use bin/Playground para testar funções isoladas
# Use bin/LinearAlgebra para testar tudo junto
TARGET=bin/LinearAlgebra$(EXEC_EXT)

all: $(TARGET)

# Criação do binário final
$(TARGET): $(OBJS)
	@echo "Unificando todos os arquivos"
	@$(CC) $(OBJS) -o $(TARGET) -lm

# A flag "-c" compila o arquivo como object, esse deve ser linkado manualmente com a main para funcionar perfeitamente
# Para linkar todos os arquivos é necessário apenas escrever o arquivo C antes das flags
# Para escolher o local e nome dos arquivos objetos, usamos "-o"

# Para qualquer função nova, use esse padrão:
#	build/function.o: src/modules/function.c
#		@echo "Compiling main"
#		@$(CC) src/modules/function.c -c -o build/function.o

build/main.o: src/main.c
	@echo "Compilando a main"
	@$(CC) $(CFLAGS) src/main.c -c -o build/main.o

build/playground.o: src/playground.c
	@echo "Compilando o playground para testes"
	@$(CC) $(CFLAGS) src/playground.c -c -o build/playground.o

build/det.o: src/modules/det.c
	@echo "Compilando a função do determinante"
	@$(CC) $(CFLAGS) src/modules/det.c -c -o build/det.o

build/autov.o: src/modules/autov.c
	@echo "Compilando funções de autovalor e autovetor"
	@$(CC) $(CFLAGS) -lm src/modules/autov.c -c -o build/autov.o

build/escal.o: src/modules/escal.c
	@echo "Compilando função de escalonamento"
	@$(CC) $(CFLAGS) src/modules/escal.c -c -o build/escal.o

build/scanm.o: src/modules/scanm.c
	@echo "Compilando função para leitura de matrizes"
	@$(CC) $(CFLAGS) src/modules/scanm.c -c -o build/scanm.o

build/printm.o: src/modules/printm.c
	@echo "Compilando função para printar matrizes"
	@$(CC) $(CFLAGS) src/modules/printm.c -c -o build/printm.o

build/classificar_funcao.o: src/modules/classificar_funcao.c
	@echo "Compilando função para classificar funções"
	@$(CC) $(CFLAGS) src/modules/classificar_funcao.c -c -o build/classificar_funcao.o

build/scansys.o: src/modules/scansys.c
	@echo "Compilando função para escanear sistemas lineares"
	@$(CC) $(CFLAGS) src/modules/scansys.c -c -o build/scansys.o

clean:
	@echo "Removendo todos os arquivos executáveis"
	@$(RM) $(call FIX_PATH,$(OBJS)) $(call FIX_PATH,$(TARGET))
