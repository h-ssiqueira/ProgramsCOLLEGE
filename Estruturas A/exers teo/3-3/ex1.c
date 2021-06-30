#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
}Lista;

Lista * CriaLista(){
    return NULL;
}

Lista * InsereLista(Lista *recebida,int v){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    
    novo->valor = v;
    novo->prox = recebida;
    return novo;    
}

void RetiraLista(Lista **recebida,int v){
    Lista *prev = CriaLista(), *aux = (*recebida);
    
    if((*recebida)->valor == v){
        aux = (*recebida)->prox;
        free(*recebida);
        (*recebida) = aux;
    }
    else{
        while(aux != NULL){
            if(aux->valor == v){
                prev->prox = aux->prox;
                free(aux);
                break;   
            }
            prev = aux;
            aux = aux->prox;  
        }
    }
}

void ImprimeLista(Lista *L){
    Lista *aux = L;
    
    printf("\n\tLista:");
    while(aux != NULL){
        printf("\n\t%d",aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void LiberaLista(Lista *recebida){
    Lista *aux = recebida,*aux2 = CriaLista();
    
    while(aux!=NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
}


int main(){
    Lista *L = CriaLista();
    int x = 0;
    
    while(x != -111){
        printf("\n\tInsira um valor para a lista (-111 p/ sair): ");
        scanf("%d",&x);
        if(x != -111)
            L = InsereLista(L,x);
    }
    
    ImprimeLista(L);
    
    printf("\n\tInsira um valor para ser retirado: ");
    scanf("%d",&x);
    RetiraLista(&L,x);
    
    ImprimeLista(L);
    
    LiberaLista(L);
    return 0;
}
