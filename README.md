<div   allign="center">
    <img src="docs/images/IFG-2015-Completa.jpg" height="250" width="auto">
</div>

# Linear Algebra 

<!-- Para o(s) professor(es):
Tentei fazer tudo em inglês para praticar e deixar o repositório mais "público"
Para instruções ou prints na main, utilizarei somente português -->

```ASCII art
.____    .__                                      
|    |   |__| ____   ____ _____ _______           
|    |   |  |/    \_/ __ \\__  \\_  __ \          
|    |___|  |   |  \  ___/ / __ \|  | \/          
|_______ \__|___|  /\___  >____  /__|             
        \/       \/     \/     \/                 
   _____  .__                ___.                 
  /  _  \ |  |    ____   ____\_ |______________   
 /  /_\  \|  |   / ___\_/ __ \| __ \_  __ \__  \  
/    |    \  |__/ /_/  >  ___/| \_\ \  | \// __ \_
\____|__  /____/\___  / \___  >___  /__|  (____  /
        \/     /_____/      \/    \/           \/ 
```

## General

- This repository aims for a college work

<!-- Padrão americano de data -->
<!-- 24/06/2026  -->
- Since it is due to **06/24/2026**, i'm probably not working here anymore after that 

### The grade is being rated like this (10.0 at total)

- Organization, code structure, and general operation. **(2.0)**

- Use of modularization functions and principles **(2.0)**

- Use of the data structures seen **(2.0)**

- Use of file and record manipulation **(2.0)**

- Meeting customer requirements (linear algebra), this follows to objectives **(2.0)**

## Objectives

### As in Linear Algebra, the main objectives are

- Solving Linear Systems

- Checking for injectivity, surjectivity, and bijectivity.

- Determination of Bases

- Eigenvalue and Eigenvector Calculation

- Matrix Diagonalization

## Tasks
<!-- No máximo 7 Tasks aqui -->

- [x] Header and function for Matrix determinant (using it all over the code, so it's really necessary)

<!-- Apenas usar uname -->
- [x] Adaptation of the Makefile for Linux 

- [ ] Adaptation of the Makefile for Windows

- [ ] GUI or TUI initials 

- [ ] Structure in main.c 

## Compiling and running

### Make

- In this project, we are using a [Makefile](Makefile), by all means the compiling will be an easy process

- Run `make` to compile everything into the bin folder

```Makefile
make
```

- After that, run the binary by using:

```Running
bin/./LinearAlgebra
```
- After testing all you want, run this command to remove all binaries and object files

```Makefile clean
make clean
```
## Structure

```Structure
├── bin             -> Final binary
├── build           -> Intermediary binaries
├── docs            -> All documentation
│   └── images      -> Images used
├── include         -> Headers
└── src             -> Main
    └── modules     -> Functions

```

by [Rafael](https://github.com/rafa-7) and [Yuri](https://github.com/YURI-gomes062)
