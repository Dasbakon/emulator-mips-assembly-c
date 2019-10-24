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

    printf("rs = %d\t rt = %d\t rd = %d\t shamt = %d\t funct = %d\n", _insf->rs, _insf->rt, _insf->rd, _insf->shamt, _insf->funct);
}

void instruction_i(int instruction){
    printf("instruction i\n");
    $rs = instruction >> 21;
    $rt = instruction >> 16;
    $imm = instruction;

    switch ($opcode){
        case 0:
            break;
        case 8:
            addi();
            break;
        default:
            break;
    }

    printf("rs = %d\t rt = %d\t immediate = %d\n", _insf->rs, _insf->rt, _insf->immediate);
}

void instruction_j(int instruction){
    printf("instruction j\n");
    _insf->jump_target = instruction;

    printf("jump_target = %d\n", _insf->jump_target);
}