#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define max 5

typedef struct {
int n;
int vet = (int *)malloc(sizeof(int)*max);
}pilha;

pilha* cria(pilha *p);
void imprime(pilha *p);
int vazia(pilha *p);
int cheia(pilha *p);
void push(pilha *p,int valor);
int pop(pilha *p);
pilha* libera(pilha *p);

int main()
{
    return 0;
}

pilha* cria(pilha *p){
pilha *aux;
aux = (pilha *)malloc(sizeof(pilha));
aux -> n = 0;
return aux;
}

void imprime(pilha *p){
    vazia(p) ? printf("\n\tErro: lista vazia"):for(int i = p->n-1;i>=0;i--){printf("\n\t%d",p->vet[i]);};
}

int vazia(pilha *p){
    if(p -> n == 0)
        return 1;
    return 0;
}

int cheia(pilha *p){
    if(p->n==max)
        return 1;
    return 0;
}

void push(pilha *p,int valor){
    if(cheia(p))
        printf("\n\tErro: pilha cheia.");
    else{
        vet[p->n] = valor;
        (p->n)++;
    }
}

int pop(pilha *p){
    if(vazia(p)){
        printf("\n\tPilha vazia.");
        return -1;
    }
    else{
        (p->n)--;
        return (p->vet[p->n]);
    }
}

pilha* libera(pilha *p){
    free(p);
    return NULL;
}
