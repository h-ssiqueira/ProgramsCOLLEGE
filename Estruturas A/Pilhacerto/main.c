typedef struct no{
    int valor;
    struct no *prox;
}No;

typedef struct pilha{
    No *prim;
}Pilha;


Pilha* Cria(){
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux -> prim = (NULL);
    return aux;
}

int vazia(Pilha *p){ ///esta vazia?
    if(!p -> prim)
        return 0; /// 0 = pilha c/ elementos
    return 1; /// 1 = pilha vazia
}

No* ret_ini(No *n){
    No *p = n -> prox;
    free(n);
    return p;
}

No* ins_ini(No *n,int a){
    No *aux = (No*)malloc(sizeof(No));
    aux -> valor = a;
    aux -> prox = n;
    return aux;
}

void push(Pilha *p,int x){
    p -> prim = ins_ini(p->prim,x);
}

int pop(Pilha *p,int *x){
    if(vazia(p))
        return 0;
    x = p -> prim -> valor;
    p->prim = ret_ini(p->prim);
    return 1;

}

void imprime(Pilha *p){
    No *q;
    if(vazia(p))
        printf("\n\tPilha vazia");

    else{
        printf("\n\tPilha:");
        for(q = p-> prim;q != NULL;q -> prox)
            printf("%d",q->info);
    }
}

No* libera(Pilha *p){
    No *q = p->prim;
    while(q!=(NULL)){
        No *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return NULL;
}

