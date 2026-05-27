# To switch compilators, just retype this part
CC=gcc

# Flag used to search for headers
CFLAGS=-Iinclude

# Final binary
all: bin/LinearAlgebra

# Binary
bin/LinearAlgebra: build/main.o build/determinant.o
	@echo "Unifying all files"
	@$(CC) $(CFLAGS) build/main.o build/determinant.o -o bin/LinearAlgebra

# The flag "-c" compiles the file as a part of the main (object file) not linking it directly
# To link all the files, just type the binaries before the flag
# To compile everything together use "-o" with the binaries linked before
build/main.o: src/main.c
	@echo "Compiling main"
	@$(CC) src/main.c -c -o build/main.o

build/determinant.o: src/modules/determinant.c
	@echo "Compiling determinant function"
	@$(CC) $(CFLAGS) src/modules/determinant.c -c -o build/determinant.o

clean:
	@echo "Removing executable files"
	@rm -f build/main.o build/determinant.o bin/LinearAlgebra
