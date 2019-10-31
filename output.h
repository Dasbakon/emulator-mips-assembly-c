void output(){
    int i;
    for (i = 0; i < 32; i++){
        printf("$%d\t 0x%08x\n", i, registers->rts[i]);
    }
    printf("pc\t 0x%08x\n", registers->pc * 4);
    printf("hi\t 0x%08x\n", registers->hilo.hi);
    printf("lo\t 0x%08x\n", registers->hilo.lo);

    for (i = 0; i < 4096; i+=4){
        printf("Mem[0x%08x] 0x%08x\t 0x%08x\t 0x%08x\t 0x%08x\n", i*4, memory[i].raw, memory[i+1].raw, 
        memory[i+2].raw, memory[i+3].raw);
    }
}