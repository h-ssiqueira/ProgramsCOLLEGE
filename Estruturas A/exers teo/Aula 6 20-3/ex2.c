#include<stdio.h>
#include<stdlib.h>
#include"PILHA_FILA.h"

void retira15(No *ini);

int main(){
    Fila *f = CriaFila();
    int i = 0,n = 0;
    while(i!=-1){
        printf("\n\tInsira um valor para a fila: ");
        scanf("%d",&i);
        if(i!=-1){
            InsereFila(f,i);
            n++;
        }
    }
    system("clear");
    if(n>=15){
    ImprimeFila(f);
    retira15(f->ini);
    ImprimeFila(f);
    }
    else
        printf("\n\tInfo 15 inexistente");
    LiberaFila(f);    
    return 0;
}

void retira15(No *ini){
    int n;
    No *aux,*anterior;
    for(aux = ini,n = 0; n!=15;aux = aux->prox, n++){
        if(n==14){
            if(aux->prox ==NULL)
                anterior->prox = NULL;
            else
                anterior->prox = aux->prox;
            free(aux);
        }
        anterior = aux;
    }    
}
