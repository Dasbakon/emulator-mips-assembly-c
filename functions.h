/*-----------------------------Type R-----------------------------------*/
void add(){
    _registers->rts[_insf->rd] = _registers->rts[_insf->rs] + _registers->rts[_insf->rt];
}

void sub(){
    _registers->rts[_insf->rd] = _registers->rts[_insf->rs] - _registers->rts[_insf->rt];
}

/*-----------------------------Type I-----------------------------------*/
void addi(){
    _registers->rts[_insf->rt] = _registers->rts[_insf->rs] + _insf->immediate;
}