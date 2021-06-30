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

void InserePos(Lista **L3,int v, int pos){
    Lista *novo = (Lista *)malloc(sizeof(Lista)), *aux = (*L3)->prox, *prev = (*L3);
    int i = 1;
    
    novo->info = v;
    while(aux != NULL){
        if(i == pos){
            novo->prox = aux;
            prev->prox = novo;
            i = -1;
            break;
        }        
        prev = aux;
        aux = aux->prox;
        i++;
    }
    if(i != -1){
        novo->prox = aux;
        prev->prox = novo;
    }
}

void ImprimeLista(Lista *recebida){
    Lista *aux = recebida;
    
    printf("\n\tLista: ");
    while(aux != NULL){
        printf("\n\t%d",aux->info);
        aux = aux->prox;
    }    
}

Lista * juntalistas(Lista *L1, Lista *L2){
    Lista *L3 = InicializaLista(), *aux = L1->prox, *aux2;
    int v = L1->info, cont;
    
    InsereLista(&L3,v); //insere um elemento na lista para poder entrar no loop
    while(aux != NULL){
        v = aux->info;
        aux2 = L3;
        cont = 0; //contador da posicao que inserira na lista
        while(aux2 != NULL){
            if(aux2->info > v)
                cont++;
            else{
                cont != 0 ? InserePos(&L3,v,cont) : InsereLista(&L3,v);// se for = 0 -> primeiro da lista, senao no meio
                cont = -1;
                break;
            }
            aux2 = aux2->prox;
        }
        if(cont != -1)//inserir no final da lista
            InserePos(&L3,v,cont);
        aux = aux->prox;
    }
    aux = L2;
    while(aux != NULL){
        v = aux->info;
        aux2 = L3;
        cont = 0; //contador da posicao que inserira na lista
        while(aux2 != NULL){
            if(aux2->info > v)
                cont++;
            else{
                cont != 0 ? InserePos(&L3,v,cont) : InsereLista(&L3,v); // se for != 0 meio da lista, senao no inicio
                cont = -1;
                break;
            }
            aux2 = aux2->prox;
        }
        if(cont != -1)//inserir no final da lista
            InserePos(&L3,v,cont);
        aux = aux->prox;
    }
    
    return L3;
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
    Lista *L1 = InicializaLista(), *L2 = InicializaLista(), *L3;
    int v;
    
    do{
        printf("\n\tInsira um valor para a lista 1 (-555 para continuar): ");
        scanf("%d",&v);
        if(v != -555)
            InsereLista(&L1,v);
    }while(v != -555);
    do{
        printf("\n\tInsira um valor para a lista 2 (-555 para continuar): ");
        scanf("%d",&v);
        if(v != -555)
            InsereLista(&L2,v);
    }while(v != -555);
    
    ImprimeLista(L1);
    ImprimeLista(L2);
    
    L3 = juntalistas(L1,L2);
    
    ImprimeLista(L3);
    
    DesalocaLista(L1);
    DesalocaLista(L2);
    DesalocaLista(L3);
    return 0;
}
