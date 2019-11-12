void instruction_r(int instruction){
    //printf("instruction r %d\n", $pc * 4);
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
        case 12:
            syscall();
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
        case 33:
            addu();
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
            printf("Funct nao encontrado %d\t %d\n", instruction, $funct);
            break;
    }    
}

void instruction_i(int instruction){
    //printf("instruction i %d\n", $pc * 4);
    insf->rs = instruction >> 21;
    insf->rt = instruction >> 16;
    insf->immediate = instruction;

    switch ($opcode){
        case 4:
            beq();
            break;
        case 5:
            registers->rts[0] = 0;
            bne();
            break;
        case 6:
            registers->rts[0] = 0;
            blez();
        case 8:
            addi();
            break;
        case 9:
            registers->rts[0] = 0;
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
        case 17:
            insf->rd = instruction >> 11;
            insf->shamt = instruction >> 6;
            insf->funct = instruction;
            float_s();
            break;
        case 35:
            lw();
            break;
        case 36:
            lbu();
            break;
        case 40:
            sb();
            break;
        case 43:
            sw();
            break;
        case 49:
            lwcl();
            break;
        case 57:
            swcl();
            break;
        default:
            printf("opcode nao encontrado %d %u\n", instruction, $opcode);
            break;
    }
}

void instruction_j(int instruction){
    //printf("instruction j %d\n", $pc * 4);
    insf->jump_target = instruction;

    if($opcode == 2){
        j();
    }else if($opcode == 3){
        jal();
    }else{
        printf("Intrucao n encontrada tipo j\n");
    }
}