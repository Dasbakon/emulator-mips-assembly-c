#include <stdio.h>
#include <stdlib.h>
#include "struct_statement.h"

insf* _insf = NULL;
registers* _registers = NULL;
_memory* memory_teste = NULL;

#include "functions.h"
#include "instructions.h"
#include "print_registers.h"

/* Funcao que inicializa variaveis com valores definidos entre outras coisas*/
void init(){
    _insf = malloc(sizeof(insf));
    _registers = malloc(sizeof(registers));
    memory_teste = malloc(1024 * sizeof(_memory));
    int i;
    for (i = 0; i < 32; i++){
        _registers->rts[i] = 0;
    }
    _registers->rts[28] = 0x1800; /* registrador gp eh inicializado com 0x1800 */
    _registers->rts[29] = 0x3ffc; /* regitrador sp eh inicializado com 0x3ffc */

    for (i = 0; i < 1024; i++){
        memory_teste[i].raw = 0;
    }
}

/* Funcao que finaliza variaveis alocadas dinamicamente entre outras coisas */
void end(){
    print_registers();
    free(_insf);
    free(_registers);
    free(memory_teste);
}

void binary_read(const char* aux){
    FILE* file = fopen(aux, "rb");
    int instruction, index = 0;
    if(!file){
        printf("Erro ao tentar abrir o arquivo text.bin");
        exit(1);
    }
    while(fread(&instruction, sizeof(int), 1, file)){
        memory_teste[index].raw = instruction;
        index++;
    }
    for ( ; $pc < index; $pc++){
        switch ($opcode  = memory_teste[$pc].raw >> 26){
            case 0:
                instruction_r(memory_teste[$pc].raw);
                break;
            case 2:
            case 3:
                instruction_j(memory_teste[$pc].raw);
                break;
            default:
                instruction_i(memory_teste[$pc].raw);
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    if(argc != 3){
        /*
            Caso a entrada seja diferente da qual foi estabelecida,
            o programa nao eh executado.
        */
        printf("Entrada incorreta\n");
        exit(1);
    }
    init();

    binary_read(argv[1]);

    end();
    return 0;
}