void instruction_r(int instruction){
    insf->rs = instruction >> 21;
    insf->rt = instruction >> 16;
    insf->rd = instruction >> 11;
    insf->shamt = instruction >> 6;
    insf->funct = instruction;

    switch ($funct){
        case 0:
            sll();
            break;
        case 2:
            srl();
            break;
        case 3:
            sra();
            break;
        case 8:
            jr();
            break;
        case 16:
            mfhi();
            break;
        case 18:
            mflo();
            break;
        case 24:
            mult();
            break;
        case 26:
            _div();
            break;
        case 32:
            add();
            break;
        case 34:
            sub();
            break;
        case 36:
            and();
            break;
        case 37:
            or();
            break;
        case 42:
            slt();
            break;
        default:
            printf("Funct nao encontrado %d\n", instruction);
            break;
    }    
}

void instruction_i(int instruction){
    insf->rs = instruction >> 21;
    insf->rt = instruction >> 16;
    insf->immediate = instruction;

    switch ($opcode){
        case 4:
            beq();
            break;
        case 5:
            bne();
            break;
        case 8:
            addi();
            break;
        case 9:
            addiu();
            break;
        case 10:
            slti();
            break;
        case 12:
            andi();
            break;
        case 13:
            ori();
            break;
        case 35:
            lw();
            break;
        case 43:
            sw();
            break;
        default:
            printf("opcode nao encontrado %d\n", instruction);
            break;
    }
}

void instruction_j(int instruction){
    printf("instruction j\n");
    insf->jump_target = instruction;
}