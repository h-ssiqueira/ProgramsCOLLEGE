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

void RetiraLista(Lista ***recebida,int v){
    Lista *prev = CriaLista(), *aux = (**recebida);
    
    if((**recebida)->valor == v){
        aux = (**recebida)->prox;
        free(**recebida);
        (**recebida) = aux;
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

int VaziaLista(Lista *L){
    if(L==NULL)
        return 1;
    return 0;
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

Lista * impar(Lista **recebida){
    Lista *aux = (*recebida),*imp = CriaLista();
    int v;
    
    while(!VaziaLista(aux)){
        v = aux->valor;
        if(v % 2 != 0){
            aux = aux->prox;
            RetiraLista(&recebida,v);
            imp = InsereLista(imp,v);
            continue;
        }
        aux = aux->prox;
    }
    return imp;
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
    Lista *Par = CriaLista(),*Impar = CriaLista();
    int x = 0;
    
    while(x != -111){
        printf("\n\tInsira um valor para a lista (-111 p/ sair): ");
        scanf("%d",&x);
        if(x != -111)
            Par = InsereLista(Par,x);
    }
    
    ImprimeLista(Par);
    
    Impar = impar(&Par);
    
    ImprimeLista(Par);
    ImprimeLista(Impar);
    
    LiberaLista(Par);
    LiberaLista(Impar);
    return 0;
}
