# To switch compilators, just retype this part
CC=gcc

# Everything that needs compiling
# Just alter here for any new functions (or older)
# For playground, just put playground at the end here:
OBJS=build/det.o build/autov.o build/scanm.o build/escal.o build/main.o

# Flags used for compiling
# -Wall shows every alert
# -I searches for headers
CFLAGS=-Wall -Iinclude

# Final binary
# bin/Playground for testing isolated functions
# bin/LinearAlgebra for testing everything together
TARGET=bin/LinearAlgebra

all: $(TARGET)

# Binary
$(TARGET): $(OBJS)
	@echo "Unifying all files"
	@$(CC) $(OBJS) -o $(TARGET) -lm

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

build/playground.o: src/playground.c
	@echo "Compiling playground for testing"
	@$(CC) $(CFLAGS) src/playground.c -c -o build/playground.o

build/det.o: src/modules/det.c
	@echo "Compiling determinant function"
	@$(CC) $(CFLAGS) src/modules/det.c -c -o build/det.o

build/autov.o: src/modules/autov.c
	@echo "Compiling Eigenvalue and Eigenvector function"
	@$(CC) $(CFLAGS) -lm src/modules/autov.c -c -o build/autov.o

build/escal.o: src/modules/escal.c
	@echo "Compiling escal function"
	@$(CC) $(CFLAGS) src/modules/escal.c -c -o build/escal.o

build/scanm.o: src/modules/scanm.c
	@echo "Compiling scan matrices function"
	@$(CC) $(CFLAGS) src/modules/scanm.c -c -o build/scanm.o

build/printm.o: src/modules/printm.c
	@echo "Compiling print matrices function"
	@$(CC) $(CFLAGS) src/modules/printm.c -c -o build/printm.o

clean:
	@echo "Removing executable files"
	@rm $(OBJS) $(TARGET)
