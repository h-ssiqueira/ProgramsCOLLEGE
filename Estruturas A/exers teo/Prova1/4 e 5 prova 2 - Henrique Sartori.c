//4
int menor(Avr *Pai){
    while(Pai->esq != NULL); //atualiza ate chegar no menor valor da arvore situado na extrema esquerda
        Pai = Pai->esq;
    return Pai->info;
}


//5
int filhos(Avr *Pai){
    if(!Pai) return 0; //caso NULL
    if(Pai->esq != NULL && Pai->dir == NULL) //caso tenha so na esquerda
        return 1 + filhos(Pai->esq);
    if(Pai->esq == NULL && Pai->dir != NULL) //caso tenha so na direita
        return 1 + filhos(Pai->dir);
    return filhos(Pai->esq) + filhos(Pai->dir); //caso tenha ambos os filhos ou nenhum filho
}
