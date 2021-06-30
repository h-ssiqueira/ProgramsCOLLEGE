#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba uma lista de inteiros e remova todos os valores
repetidos desta lista.
*/

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista * InicializaLista(){
    return NULL;
}

void InsereLista(Lista **recebida, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    
    novo->info = valor;
    novo->prox = (*recebida);
    (*recebida) = novo;    
}

void ImprimeLista(Lista *recebida){
    Lista *aux = recebida;
    
    printf("\n\tLista: ");
    while(aux != NULL){
        printf("\n\t%d",aux->info);
        aux = aux->prox;
    }    
}

void Repetidos(Lista *recebida){
    Lista *aux = recebida, *aux2act, *aux2prev;
    int var;
    
    for(; aux != NULL; aux = aux->prox){
        var = aux->info;
        aux2act = aux->prox;
        aux2prev = aux;
        while(aux2act != NULL){
            if(aux2act->info == var){
                aux2prev->prox = aux2act->prox;
                free(aux2act);
                aux2act = aux2prev->prox;
            }else{
                aux2prev = aux2act;
                aux2act = aux2prev->prox;
            }
        }
    }
}

void DesalocaLista(Lista *recebida){
    Lista *aux = recebida, *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
}

int main(){
    Lista *l = InicializaLista();
    int v;
    
    do{
        printf("\n\tInsira um valor para a lista (-555 para continuar): ");
        scanf("%d",&v);
        if(v != -555)
            InsereLista(&l,v);
    }while(v != -555);
    ImprimeLista(l);
    
    Repetidos(l);
    
    ImprimeLista(l);
    
    DesalocaLista(l);
    return 0;
}
