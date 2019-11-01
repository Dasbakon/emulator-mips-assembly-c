#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

_insf* insf = NULL;
_registers* registers = NULL;
_memory* memory = NULL;

#include "functions.h"
#include "instructions.h"
#include "output.h"

/* Funcao que inicializa variaveis com valores definidos entre outras coisas*/
void init(){
    insf = malloc(sizeof(_insf));
    registers = malloc(sizeof(_registers));
    memory = malloc(4096 * sizeof(_memory));
    int i;
    for (i = 0; i < 32; i++){
        registers->rts[i] = 0;
    }
    registers->rts[28] = 0x1800 / 4; /* registrador gp eh inicializado com 0x1800 */
    registers->rts[29] = 0x3ffc / 4; /* regitrador sp eh inicializado com 0x3ffc */

    for (i = 0; i < 1024; i++){
        memory[i].raw = 0;
    }
}

/* Funcao que finaliza variaveis alocadas dinamicamente entre outras coisas */
void end(){
    printf("\n");
    output();
    free(insf);
    free(registers);
    free(memory);
    exit(1);
}

void emulator(const char* files[]){
    FILE* text = fopen(files[1], "rb");
    FILE* data = fopen(files[2], "rb");
    int aux, index;

    /* ----------------- Data -----------------*/
    if(data){
        index = 2048;
        while(fread(&aux, sizeof(int), 1, data) && index < 3072){
            memory[index].raw = aux;
            index++;
        }

        if(index > 3072){
            /*
                Ocorre quando a demo (text.bin) tenta acessar (para leitura ou escrita)
                um endereço na memória que está reservado para outro programa. 
            */
            printf("segmentation fault data\n");
            end();
        }
    }else{
        printf("Arquivo data nao foi aberto\n");
    }

    /* ----------------- Text -----------------*/
    if(text){
        index = 0;
        while(fread(&aux, sizeof(int), 1, text) && index < 1024){
            memory[index].raw = aux;
            index++;
        }
        if(index >= 1024){
            /*
                Ocorre quando a demo (text.bin) tenta acessar (para leitura ou escrita)
                um endereço na memória que está reservado para outro programa. 
            */
            printf("segmentation fault text\n");
            end();
        }
    }else{
        printf("Erro ao tentar abrir o arquivo text.bin");
        exit(1);
    }
    for ( ; $pc < index; $pc++){
        switch ($opcode  = memory[$pc].raw >> 26){
            case 0:
                instruction_r(memory[$pc].raw);
                break;
            case 2:
            case 3:
                instruction_j(memory[$pc].raw);
                break;
            default:
                instruction_i(memory[$pc].raw);
                break;
        }
    }

    fclose(text);
    fclose(data);
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
    emulator(argv);
    end();
}