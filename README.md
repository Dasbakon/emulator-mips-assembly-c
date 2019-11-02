<h1>EMULADOR MIPS</h1>

Programa executável: emulator.exe </br>
    obs: na hora de executar devo passar dois arquivos no parametro ex: ./main text.bin data.bin </br>

O arquivo text.bin deve conter as instruções mips em binário e o data.bin deve conter os endereços de memória </br>

Comando para compilar no terminal:</br>
    gcc emulator.c -o emulator -Wall -ansi -pedantic -std=c11</br>
    ou</br>
    make</br>

Memoria: endereçada por palavra 4 bytes, mas divida por byte</br>

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