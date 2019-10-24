#define $opcode   _insf->opcode
#define $rd       _registers->rts[_insf->rd]
#define $rs       _registers->rts[_insf->rs]
#define $rt       _registers->rts[_insf->rt]
#define $imm      _insf->immediate
#define $shamt    _insf->shamt
#define $funct    _insf->funct
#define $reg_hilo _registers->hilo

/*-----------------------------Type R-----------------------------------*/
void add(){
    $rd = $rs + $rt;
}

void and(){
    $rd = $rs & $rt;
}

void div(){
    $reg_hilo.lo = $rs / $rt;
    $reg_hilo.hi = $rs % $rt;
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

void lui(){
    $rd = $imm << 16;
}

void lw(){
    $rt = memory[];
}

void ori(){
    $rd = $rs | $imm;
}

void slti(){
    $rd = ($rs < $imm)? 1 : 0;
}