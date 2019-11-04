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

void _4(){
    int position = registers->rts[4] / 4;
    int byte = registers->rts[4] % 4;
    char aux = 1;
    while(aux != 0){
        switch (byte)
        {
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
        if(aux != '\0'){ printf("%c", aux); }
    }
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
    switch(registers->rts[2]){
        case 1:
            printf("%d", registers->rts[4]);
            break;
        case 4:
            _4();
            break;
        case 5:
            scanf("%d", &registers->rts[2]);
            break;
        case 8:
            break;
        case 10:
            end();
            break;
        case 11:
            printf("%c", registers->rts[4]);
            break;
        case 12:
            scanf("%d", &registers->rts[2]);
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
    $rt = $rs + abs($imm);
}

void andi(){
    $rd = $rs & $imm;
}

void beq(){
    if($rs == $rt){
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

void lw(){
   $rt = memory[(($rs + $imm) / 4)].raw;
}

void ori(){
    $rd = $rs | $imm;
}

void slti(){
    $rd = ($rs < $imm)? 1 : 0;
}

void sw(){
    memory[(($rs + $imm) / 4)].raw = $rt;
}

/*-----------------------------Type J-----------------------------------*/

void j(){
    $pc = insf->jump_target - 1;
}

void jal(){
    registers->rts[31] = $pc;
    $pc = insf->jump_target - 1;
}