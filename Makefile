# To switch compilators, just retype this part
CC=gcc

# Flag used to search for headers
CFLAGS=-Iinclude

# Final binary
all: bin/LinearAlgebra

# Binary
bin/LinearAlgebra: build/main.o build/det.o
	@echo "Unifying all files"
	@$(CC) $(CFLAGS) build/main.o build/det.o -o bin/LinearAlgebra

# The flag "-c" compiles the file as a part of the main (object file) not linking it directly
# To link all the files, just type the binaries before the flag
# To compile everything together use "-o" with the binaries linked before

# For any new function, just copy this pattern:
#	build/function.o: src/modules/function.c
#		@echo "Compiling main"
#		@$(CC) src/modules/function.c -c -o build/function.o

build/main.o: src/main.c
	@echo "Compiling main"
	@$(CC) src/main.c -c -o build/main.o

build/det.o: src/modules/det.c
	@echo "Compiling determinant function"
	@$(CC) $(CFLAGS) src/modules/det.c -c -o build/det.o

build/scanm.o: src/modules/scanm.c
	@echo "Compiling main"
	@$(CC) src/modules/scanm.c -c -o build/scanm.o

clean:
	@echo "Removing executable files"
	@rm -f build/main.o build/det.o build/scanm.o bin/LinearAlgebra
