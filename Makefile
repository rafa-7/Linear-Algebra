# To switch compilators, just retype this part
CC=gcc

# Everything that needs compiling
OBJS=build/det.o build/autov.o build/main.o

# Flags used for compiling
# -Wall shows every alert
# -I uses headers
CFLAGS=-Wall -I include


# Final binary
all: bin/LinearAlgebra

# Binary
bin/LinearAlgebra: build/main.o build/det.o
	@echo "Unifying all files"
	@$(CC) $(OBJS) -o bin/LinearAlgebra

# The flag "-c" compiles the file as a part of the main (object file) not linking it directly
# To link all the files, just type the binaries before the flag
# To compile everything together use "-o" with the binaries linked before

# For any new function, just copy this pattern:
#	build/function.o: src/modules/function.c
#		@echo "Compiling main"
#		@$(CC) src/modules/function.c -c -o build/function.o

build/main.o: src/main.c
	@echo "Compiling main"
	@$(CC) $(CFLAGS) src/main.c -c -o build/main.o

build/det.o: src/modules/det.c
	@echo "Compiling determinant function"
	@$(CC) $(CFLAGS) src/modules/det.c -c -o build/det.o

build/autov.o: src/modules/autov.c
	@echo "Compiling Eigenvalue and Eigenvector function"
	@$(CC) $(CFLAGS) src/modules/autov.c -c -o build/autov.o

clean:
	@echo "Removing executable files"
	@rm $(OBJS) bin/LinearAlgebra
