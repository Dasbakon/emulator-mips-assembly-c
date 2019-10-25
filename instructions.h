void instruction_r(int instruction){
    printf("instruction r\n");
    _insf->rs = instruction >> 21;
    _insf->rt = instruction >> 16;
    _insf->rd = instruction >> 11;
    _insf->shamt = instruction >>6;
    _insf->funct = instruction;

    switch ($funct){
        case 32:
            add();
            break;
        case 34:
            sub();
            break;
        case 36:
            and();
        default:
            break;
    }    
}

void instruction_i(int instruction){
    printf("instruction i\n");
    _insf->rs = instruction >> 21;
    _insf->rt = instruction >> 16;
    _insf->immediate = instruction;

    switch ($opcode){
        case 0:
            break;
        case 8:
            addi();
            break;
        default:
            break;
    }
}

void instruction_j(int instruction){
    printf("instruction j\n");
    _insf->jump_target = instruction;
}