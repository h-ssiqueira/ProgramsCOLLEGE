#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista * inicializa(){
    return NULL;
}

Lista * insere(Lista *recebida,int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = recebida;
    return novo;
}

void retira(Lista **recebida, Lista *retirar){
    Lista *aux2 = inicializa();
    for(Lista *aux = (*recebida); aux!=NULL; aux2 = aux, aux=aux->prox){
        if(aux == retirar){
            if(aux2 == NULL){
                (*recebida) = aux->prox;
            }
            else{
                aux2->prox = aux->prox;
            }
            free(aux);
            break;
        }
    }
}

void imprime(Lista *recebida){
    for(Lista *p = recebida; p!=NULL; p=p->prox){
        printf("Info = %d\n",p->info);
    }
}

int vazia(Lista *recebida){
    if(recebida!=NULL)
        return 0;
    else 
        return 1;
}

Lista * busca(Lista *recebida,int v){
    for(Lista *p = recebida; p!=NULL; p = p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;
}

void libera(Lista *recebida){
    Lista *aux = recebida, *aux2;
    while(aux!=NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;        
    }
}

int main(){
    Lista *l = inicializa(), *conf = inicializa();
    int v = 0;
    
    while(v != -1){
        printf("\n\tInsira um valor para a lista (-1 para sair): ");
        scanf("%d",&v);
        if(v != -1)
            l = insere(l,v);
    }
    v = 0;
    while(!vazia(l) && v != -1){
        imprime(l);
        printf("\n\tInsira o valor a ser retirado (-1 para sair): ");
        scanf("%d",&v);
        if(v != -1){
            conf = busca(l,v);
            if(conf != NULL)    
                retira(&l,conf);
            else
                printf("\n\tValor inexistente no sistema.\n");    
        }
    }
    
    
    
    libera(l);
    return 0;    
}
