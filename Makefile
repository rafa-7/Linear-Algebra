# To switch compilators, just retype this part
CC=gcc

# CFLAGS= -Wno-implicit-function-declaration
all: main

# Bin
LinearAlgebra: main.o determinant.o
	$(CC) main.o determinant.o -o bin/LinearAlgebra

# 
main.o: main.c
	echo "Compiling main"
	@$(CC) main.c -c build/main.o

determinant.o: determinant.c
	echo "Compiling determinant function"
	@$(CC) determinant.c -c build/determinant.o

clean:
	echo "Removing executable files"
	@rm main LinearAlgebra.o
