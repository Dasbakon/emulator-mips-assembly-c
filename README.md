# EMULADOR MIPS

Programa executável: emulator.exe </br>
    obs: na hora de executar devo passar dois arquivos no parametro ex: ./main text.bin data.bin </br>

Comando para compilar no terminal:</br>
    gcc emulator.c -o emulator -Wall -ansi -pedantic -std=c11</br>
    ou</br>
    make</br>



## Processo:
1. Recebe dois arquivos na hora de escutar, o text e o data, caso falte algum dos arquivos o emulador é encerrado, obs: caso não use o arquivo data, é necessario passar um arquivo em branco.
2. executa a função init, onde eu inicializo minha memória, registradores e uma estrutura para decodificar as instruções chamada instruction_field onde eu utilizo o bit field.
    
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

3. abre os dois arquivos, caso o text não exista, o emulador encerra. O data nem sempre é usado.
4. o emulador lê os arquivos e guarda suas informações na memória, caso um dos arquivo contenha informações que utrapassam seu espaço reservado na memória, o emulador é encerrado exibindo a mensagem 'Error: segmentation fault text'.

        Divisâo da memória:
            0 até 1023: instruções mips do arquivo text
            1024 até 2047: heap
            2048 até 3071: informações do data
            3072 até 4096: pilha
    


 5. o emulador começa a executar as instruções dentro de um for com o registrador pc como índice.
 6. dentro do for o emulador pega a instrução na memória, e dada a instução o progama obtém o opcode. Com o opcode o emulador executa o tipos de instruções.
 7. os tipos de intruções são r, i e j. Elas são executadas no arquivo instructions.h. A estrutura instruction_field é formatada para cada tipo.
    - Para o tipo r, o emulador vai executar determinada função a partir do funct.
    - Para o tipo i e j, o emulador vai executar determinada função a partir do opcode.
 8. as função que serão executadas estão no arquvio funtions.h

## Funções implementadas:
        Tipo R:
           - add
           - addu
           - and
           - div
           - jr
           - mfhi
           - mflo
           - mult
           - or
           - sll
           - slt
           - srl
           - syscall:
               - 1 imprime inteiro
               - 4 imprime string
               - 5 le inteiro
               - 10 exit
               - 11 imprima char
               - 12 le char
               - 34 imprime hexadecimal
               - 35 imprime binário
               - 36 imprime unsigned
  
        Tipo I:
            - addi
            - addiu
            - add.s
            - andi
            - beq
            - bne
            - lui
            - lbu
            - lw
            - lwcl
            - ori
            - slti
            - sb
            - sw
            - swcl
  
        Tipo J:
            - j
            - jal