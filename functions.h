#define $opcode   insf->opcode
#define $rd       registers->rts[insf->rd]
#define $rs       registers->rts[insf->rs]
#define $rt       registers->rts[insf->rt]
#define $imm      insf->immediate
#define $shamt    insf->shamt
#define $funct    insf->funct
#define $reg_hilo registers->hilo
#define $pc       registers->pc
void end();

/*-----------------------------Type R-----------------------------------*/

void add(){
    $rd = $rs + $rt;
}

void addu(){
    $rd = $rs + $rt;
}

void and(){
    $rd = $rs & $rt;
}

void _div(){
    $reg_hilo.lo = $rs / $rt;
    $reg_hilo.hi = $rs % $rt;
}

void jr(){
    $pc = $rs;
}

void mfhi(){
    $rd = $reg_hilo.hi;
}

void mflo(){
    $rd = $reg_hilo.lo;
}

void mult(){
    $reg_hilo.raw = $rs * $rt;
}

void or(){
    $rd = $rs | $rt;
}

void sll(){
    $rd = $rt << $shamt;
}

void slt(){
    $rd = ($rs < $rt)? 1 : 0;
}

void sra(){
    
}

void srl(){
    $rd = $rt >> $shamt;
}

void sub(){
    $rd = $rs - $rt;
}
/* Funções do syscall */
void _4(){
    int position = registers->rts[4] / 4;
    int byte = registers->rts[4] % 4;
    char aux = 1;
    while(aux != 0){
        switch (byte){
            /* eu incremento + 1 no byte dentro de cada caso, para que no caso 3 o meu byte volte a ser zero sem ser incrementado */
            case 0:
                aux = memory[position].byte_1;
                byte++;
                break;
            case 1:
                aux = memory[position].byte_2;
                byte++;
                break;
            case 2:
                aux = memory[position].byte_3;
                byte++;
                break;
            case 3:
                aux = memory[position].byte_4;
                position++;
                byte = 0;
                break;
            default:
                break;
        }
        if(aux != '\0'){
            printf("%c", aux);
        }
    }
}

void _8(){
    int position = registers->rts[4] / 4;
    scanf("%*c");
    fgets(&memory[position].byte_1, registers->rts[5], stdin);
}

void _35(){
    int copy = registers->rts[4];
    int i;
    for(i =0 ; copy > 0 && i < 32; i++){
        printf("%d ", copy%2);
        copy = copy/2;
    }
}

void syscall(){
    //printf("SYSCALL %d\n", registers->rts[2]);
    switch(registers->rts[2]){
        case 1:
            printf("%d", registers->rts[4]);
            break;
        case 2:
            printf("%.2f", comproc[12]);
            break;
        case 4:
            _4();
            break;
        case 5:
            scanf("%d", &registers->rts[2]);
            break;
        case 6:
            scanf("%f", &comproc[0]);
            printf("%f\n", comproc[0]);
            printf("%f\n", comproc[1]);
            printf("%f\n", comproc[2]);
            break;
        case 8:
            _8();
            break;
        case 10:
            end();
            break;
        case 11:
            printf("%c", registers->rts[4]);
            break;
        case 12:
            scanf("%d", &registers->rts[2]); /* funcao que deveria ler um char, mas o emulador le como inteiro, o que nao interfere no resultado */
            break;
        case 34:
            printf("%x", registers->rts[4]);
            break;
        case 35:
            _35();
            break;
        case 36:
            printf("%u", registers->rts[4]);
            break;
    }
}

/*-----------------------------Type I-----------------------------------*/

void addi(){
    $rt = $rs + $imm; 
}

void addiu(){
    $rt = $rs + $imm;
}

void andi(){
    $rd = $rs & $imm;
}

void beq(){
    if($rs == $rt){
        $pc = $pc + $imm;
    }
}

void blez(){
    if ($rs <= 0){
        $pc = $pc + $imm;
    }
}

void bne(){
    if($rs != $rt){
        $pc = $pc + $imm;
    }
}

void lui(){
    $rd = $imm << 16;
}

void lbu(){
    int aux = ($rs + $imm) / 4;
    if(aux > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    int byte = ($rs + $imm) % 4;
    switch (byte){
        case 0:
            $rt = abs(memory[aux].byte_1);
            break;
        case 1:
            $rt = abs(memory[aux].byte_2);
            break;
        case 2:
            $rt = abs(memory[aux].byte_3);
            break;
        case 3:
            $rt = abs(memory[aux].byte_4);
            break;
        default:
            break;
    }   
}

void lw(){
    /* Caso eu aceese uma posição fora do vetor */
    if(($rs + $imm) / 4 > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    $rt = memory[(($rs + $imm) / 4)].raw;
}

void lwcl(){
    /* Caso eu aceese uma posição fora do vetor */
    if(($rs + $imm) / 4 > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    comproc[insf->rt] = (float)memory[((insf->rs + insf->immediate) / 4)].raw;
}

void ori(){
    $rd = $rs | $imm;
}

void add_s(){
    comproc[$shamt] = comproc[insf->rd] + comproc[insf->rt];
}

void float_s(){
    switch ($funct){
        case 0:
            add_s();
            break;
        default:
            break;
    }
}

void slti(){
    $rt = ($rs < $imm)? 1 : 0;
}

void sb(){
    int aux = ($rs + $imm) / 4;
    if(aux > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    int byte = ($rs + $imm) % 4;

    switch (byte){
        case 0:
            memory[aux].byte_1 = $rt;
            break;
        case 1:
            memory[aux].byte_2 = $rt;
            break;
        case 2:
            memory[aux].byte_3 = $rt;
            break;
        case 3:
            memory[aux].byte_4 = $rt;
            break;
        default:
            break;
    }
    
}

void sw(){
    /* Caso eu aceese uma posição fora do vetor */
    if(($rs + $imm) / 4 > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    memory[(($rs + $imm) / 4)].raw = $rt;
}

void swcl(){
    if(($rs + $imm) / 4 > 4095){
        printf("Error: stack overflow\n");
        end();
    }
    memory[((insf->rs + insf->immediate) / 4)].raw = comproc[insf->rt];
}
/*-----------------------------Type J-----------------------------------*/

void j(){
    /* meu pc irá receber o jump_target - 1, o "-1" é necessário pois quando eu voltar no 
    for la no arquivo emulador.c eu irei incrementar o pc, isso vale o mesmo para a função jal*/
    $pc = insf->jump_target - 1;
}

void jal(){
    registers->rts[31] = $pc;
    $pc = insf->jump_target - 1;
}