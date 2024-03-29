typedef struct instruction_fields{
    unsigned int opcode:6;
    unsigned int rs:5;
    unsigned int rt:5;
    unsigned int rd:5;
    unsigned int shamt:5;
    unsigned int funct:6;
    unsigned short immediate; //short 16 bits
    unsigned int jump_target:26;
}insf;

typedef union hilo{
    long long int raw;
    struct{
        unsigned int lo;
        unsigned int hi;
    };
}hilo;
 
typedef struct registers{
    int rts[31];
    hilo hilo;
    int pc;
}registers;