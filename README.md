<h1>EMULADOR MIPS</h1>

Programa executável: emulator.exe
    obs: na hora de executar devo passar dois arquivos no parametro ex: ./main text.bin data.bin

O arquivo text.bin deve conter as instruções mips em binário e o data.bin deve conter os endereços de memória

Comando para compilar no terminal:
    gcc emulator.c -o emulator -Wall -ansi -pedantic -std=c11
    ou
    make

Memoria: endereçada por palavra 4 bytes, mas divida por byte

    typedef union _memory{
        int raw;
        struct{
            char byte_1;
            char byte_2;
            char byte_3;
            char byte_4;
        };
    }_memory;

    declaração: _memory* memory = malloc(4096 * sizeof(_memory));
        0 - 1023:       text.bin
        1024 - 2047:    espaço para lixo
        2048 - 3071:    data.bin
        3072 - 4097:    pilha