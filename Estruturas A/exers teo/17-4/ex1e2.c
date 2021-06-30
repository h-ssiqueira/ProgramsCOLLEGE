#include <stdio.h>
#include <stdlib.h>

typedef struct listad{
    int valor;
    struct listad *prox;
    struct listad *ant;
}ListaD;

ListaD* Inicializa(){
    return NULL;
}

int VaziaListaD(ListaD *recebida){
    if(recebida == NULL)
        return 1;
    return 0;
}

void InsereListaD(ListaD **recebida,int info){
    ListaD *novo = (ListaD*)malloc(sizeof(ListaD));

    novo->valor = info;
    novo->prox = (*recebida);
    if(!VaziaListaD(*recebida))
        (*recebida)->ant = novo;
    novo->ant = NULL;
    (*recebida) = novo;
}

ListaD* Busca(ListaD *recebida,int v){
    ListaD *aux = recebida;

    for(; !VaziaListaD(aux); aux = aux->prox){
        if(aux->valor == v)
            return aux;
    }
    return NULL;
}

void ImprimeListaD(ListaD *recebida){
    ListaD *aux = recebida,*aux2 = Inicializa();

    printf("\n\tLista pelo ponteiro prox: ");
    for(; !VaziaListaD(aux); aux2 = aux, aux = aux->prox){
        printf("\n\t%d",aux->valor);
    }
    printf("\n\tLista pelo ponteiro ant: ");
    for(; !VaziaListaD(aux2); aux2 = aux2->ant){
        printf("\n\t%d",aux2->valor);
    }
}

void DesalocaListaD(ListaD *recebida){
    ListaD *aux = recebida, *aux2 = recebida;

    while(aux!=NULL){
        aux2 = aux2->prox;
        free(aux);
        aux = aux2;
    }
}

int main(){
    ListaD *L = Inicializa();
    int v;

    do{
        printf("\n\tInsira um valor para a lista (-159 p/ sair) -> ");
        scanf("%d",&v);
        if(v != -159)
            InsereListaD(&L,v);
    }while(v != -159);

    ImprimeListaD(L);
    DesalocaListaD(L);
    return 0;
}

