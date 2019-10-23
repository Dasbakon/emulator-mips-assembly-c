void print_registers(){
    int i;
    for (i = 0; i < 32; i++){
        if (i == 0){
            printf("$zero\t %d\t %d\n", i, _registers->rts[i]);   
        }else if(i == 1){
            printf("$at\t %d\t %d\n", i, _registers->rts[i]);   
        }else if(i >= 2 && i <= 3){
            printf("$v%d\t %d\t %d\n", i-2, i, _registers->rts[i]);   
        }else if(i >= 4 && i <= 7){
            printf("$a%d\t %d\t %d\n", i-4, i, _registers->rts[i]);   
        }else if(i >=8 && i <= 15){
            printf("$t%d\t %d\t %d\n", i-8, i, _registers->rts[i]);   
        }else if(i >= 16 && i <= 23){
            printf("$s%d\t %d\t %d\n", i-16, i, _registers->rts[i]);   
        }else if (i >= 24 && i <= 25){
            printf("$t%d\t %d\t %d\n", i-16, i, _registers->rts[i]);
        }else if (i >= 26 && i <= 27){
            printf("$k%d\t %d\t %d\n", i-26, i, _registers->rts[i]);
        }else if(i == 28){
            printf("$gp\t %d\t %d\n", i, _registers->rts[i]);
        }else if(i == 29){
            printf("$sp\t %d\t %d\n", i, _registers->rts[i]);
        }else if(i == 30){
            printf("$fp\t %d\t %d\n", i, _registers->rts[i]);
        }else if(i == 31){
            printf("$ra\t %d\t %d\n", i, _registers->rts[i]);
        }
    }
    printf("pc\t\t %d\n", _registers->pc);
    printf("hi\t\t %d\n", _registers->hilo.hi);
    printf("lo\t\t %d\n", _registers->hilo.lo);
}