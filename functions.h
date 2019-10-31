#define $opcode   insf->opcode
#define $rd       registers->rts[insf->rd]
#define $rs       registers->rts[insf->rs]
#define $rt       registers->rts[insf->rt]
#define $imm      insf->immediate
#define $shamt    insf->shamt
#define $funct    insf->funct
#define $reg_hilo registers->hilo
#define $pc       registers->pc

/*-----------------------------Type R-----------------------------------*/

void add(){
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
    $pc = $rs / 4;
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