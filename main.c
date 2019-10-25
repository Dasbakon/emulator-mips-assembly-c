#include <stdio.h>
#include <stdlib.h>
#include "struct_statement.h"

insf* _insf = NULL;
registers* _registers = NULL;
char memory[4096 * 4];

#include "functions.h"
#include "instructions.h"
#include "print_registers.h"

void init(){
    _insf = malloc(sizeof(insf));
    _registers = malloc(sizeof(registers));
    int i;
    for (i = 0; i < 32; i++){
        _registers->rts[i] = 0;
    }
    
}

void end(){
    print_registers();
    free(_insf);
    free(_registers);
}

void binary_read(const char* aux){
    FILE* file = fopen(aux, "rb");
    int instruction;
    if(!file){
        printf("Erro ao tentar abrir o arquivo text.bin");
        exit(1);
    }
    while(fread(&instruction, sizeof(int), 1, file)){
        switch (_insf->opcode = instruction >> 26)
        {
            case 0:
                instruction_r(instruction);
                break;
            case 2:
            case 3:
                instruction_j(instruction);
                break;
            default:
                instruction_i(instruction);
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
