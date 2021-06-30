#define MAX 10

typedef struct pilha{
    int n;
    int vet[MAX];
}Pilha;

Pilha* cria (void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha)); 
    p->n = 0;
    return p;
}

int cheia (Pilha* p) {
    if(p->n == MAX)
        return 1; 
    else
        return 0;
}

int vazia (Pilha* p) {
    if(p->n == 0)
        return 1;
    else
        return 0; 
}

int push (Pilha* p, int v) {
    if (cheia(p)) 
        return 0;

    /* insere elemento na próxima posição livre */ 
    p->vet[p->n] = v;
    p->n++;
    return 1;
}

int pop (Pilha* p, int *v) {
    if (vazia(p)) 
        return 0; 

    /* retira elemento do topo */ 
    p->n--;
    *v = p->vet[p->n];
    return 1;
}

void libera (Pilha* p){
    free(p); 
}

/* imprime: versão com VETOR*/
void imprime (Pilha* p) {
    int i;
    for (i=p->n-1; i>=0; i--)
        printf("%i\n",p->vet[i]); 
}