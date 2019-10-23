#include <stdio.h>

struct opcode{
    unsigned int opcode:6;
    unsigned int rs:5;
    unsigned int rt:5;
};

union hilo
{
    int raw;
    struct 
    {
        unsigned short lo;
        unsigned short hi;
    };
    
};
 
struct reg
{
    int[31];
    struct hilo;
    int pc;
};


int main(){
    unsigned int a = 537395210;
    struct opcode op = {a >> 26, a >> 21, a >> 16};
    //printf("%x\n", a); 
    printf("%d %d %d\n\n", op.opcode, op.rs, op.rt);

    union hilo _hilo;

    _hilo.raw = 655410;
    //_hilo.hi = 10/2;
    //_hilo.lo = 200/2;
    printf("%d\n%d %d", _hilo.raw, _hilo.hi, _hilo.lo);
    return 0;
}