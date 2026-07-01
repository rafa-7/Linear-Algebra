<div   allign="center">
    <img src="docs/images/IFG-2015-Completa.jpg" height="250" width="auto">
</div>

# Álgebra Linear

```ASCII art
   ___   __         __           
  / _ | / /__ ____ / /  _______ _
 / __ |/ / _ `/ -_) _ \/ __/ _ `/
/_/ |_/_/\_, /\__/_.__/_/  \_,_/ 
   __   /___/                    
  / /  (_)__  ___ ___ _____      
 / /__/ / _ \/ -_) _ `/ __/      
/____/_/_//_/\__/\_,_/_/         
                                 
```
## Geral

- Este repositório é voltado para um trabalho acadêmico.
- Como o prazo de entrega é até **01/07/2026**, provavelmente não estarei mais mexendo aqui após essa data.

### A nota será avaliada da seguinte forma (10.0 no total):

- Organização, estrutura do código e funcionamento geral. **(2.0)**
- Uso de funções e princípios de modularização. **(2.0)**
- Uso das estruturas de dados estudadas. **(2.0)**
- Uso de manipulação de arquivos e registros. **(2.0)**
- Atendimento aos requisitos do cliente (álgebra linear), conforme os objetivos. **(2.0)**

## Objetivos

### No escopo de Álgebra Linear, os principais objetivos são:

- Resolução de Sistemas Lineares
- Verificação de injetividade, sobrejetividade e bijetividade.
- Determinação de Bases
- Cálculo de Autovalores e Autovetores
- Diagonalização de Matrizes

## Tarefas

- [x] Finalizar `diag.c`
- [ ] Finalizar adaptação do código na main
- [ ] Finalizar programa

## Compilação e Execução

### Make

- Neste projeto, estamos utilizando um [Makefile](https://www.google.com/search?q=Makefile). Sendo assim, o processo de compilação será bem simples.
- Execute `make` para compilar tudo dentro da pasta `bin`:

```Makefile
make

```

- Depois disso, execute o binário utilizando:

```Running
bin/./LinearAlgebra

```

- Após fazer todos os testes que desejar, execute este comando para remover todos os binários e arquivos de objeto:

```Makefile clean
make clean

```

## Estrutura

```Estrutura
├── bin             -> Binário final
├── build           -> Binários intermediários (objetos)
├── docs            -> Toda a documentação
│   └── images      -> Imagens utilizadas
├── include         -> Headers (.h)
└── src             -> Código principal
    └── modules     -> Funções usadas

```
por [Rafael](https://github.com/rafa-7) e [Yuri](https://github.com/YURI-gomes062)
