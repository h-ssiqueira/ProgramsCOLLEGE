#include<stdio.h>
#include<stdlib.h>
#include"PILHA_FILA.h"

int pares(Fila *f);
Fila* Inverte(Fila *f);

int main(){
    Fila *f = CriaFila();
    int i = 0;
    while(i!=-1){
        printf("\n\tInsira um valor para a fila: ");
        scanf("%d",&i);
        if(i!=-1)
            InsereFila(f,i);
    }
    system("clear");
    i = pares(f);
    printf("Pares = %d",i);
    ImprimeFila(f);
    f = Inverte(f);
    ImprimeFila(f);
    LiberaFila(f);    
    return 0;
}

int pares(Fila *f){
    int par = 0,i;
    No *aux;
    for(aux = f->ini; aux->prox != NULL; aux = aux->prox){
        if((aux->info % 2) == 0){
            par++;
        }
    }
    return par;
}

Fila* Inverte(Fila *f){
    Fila *aux = CriaFila();
    Pilha *p = CriaPilha();
    while(!VaziaFila(f)){
        push(p,RetiraFila(f));        
    }
    while(!VaziaPilha(p)){
        InsereFila(aux,pop(p));
    }
    
    LiberaFila(f);
    LiberaPilha(p);
    return aux;
}
