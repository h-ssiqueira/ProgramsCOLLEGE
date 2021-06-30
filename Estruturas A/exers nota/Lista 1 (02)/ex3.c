#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"

Pilha* menor_elemento(Pilha *p,int *menor);
Pilha* maior_elemento(Pilha *p,int *maior);

int main()
{
    int info,maior,menor;
    Pilha *p=CriaPilha();
    do{
        printf("\nInsira os elementos da lista(-999 para sair):");
        scanf("%d",&info);
        if(info!=-999)
            push(p,info);
    }while(info!=-999);
    p=maior_elemento(p,&maior);
    p=menor_elemento(p,&menor);
    imprime(p);
    printf("\n\n\tMaior elemento:%d\n",maior);
    printf("\n\tMenor elemento:%d\n",menor);
    p=libera(p);
    return 0;
}

Pilha* maior_elemento(Pilha *p,int *maior)
{
    int valor;
    Pilha *aux=CriaPilha();
    *maior=pop(p);
    push(aux,*maior);
    while(vazia(p))
    {
        valor=pop(p);
        if(valor>*maior)
            *maior=valor;
        push(aux,valor);
    }
    return aux;
}

Pilha* menor_elemento(Pilha *p,int *menor)
{
    int valor;
    Pilha *aux=CriaPilha();
    *menor=pop(p);
    push(aux,*menor);
    while(vazia(p))
    {
        valor=pop(p);
        if(valor<*menor)
            *menor=valor;
        push(aux,valor);
    }
    return aux;
}
///Nao foi necessario inverter a pilha nas funções, como a função inverte as pilhas
// e são chamadas duas vezes a pilha acaba voltando para a sequencia original;
