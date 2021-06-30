#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"

Pilha* ordena(Pilha *p,int tam);
Pilha* tira_maior_pilha(Pilha *p,int maior);

int main()
{
    Pilha *p = CriaPilha();
    int info,cont=0;
    do{
        printf("\n\tInsira um valor para a pilha (-111 para sair): ");
        scanf("%d",&info);
        if(info != -111)
        {
            push(p,info);
            cont++;
        }
    }while(info != -111);
    printf("\n\tPilha Original:");
    imprime(p);
    p = ordena(p,cont);
    printf("\n\n\tPilha Ordenada:");
    imprime(p);
    printf("\n");    
    p = libera(p);

    return 0;
}

Pilha* ordena(Pilha *p,int tam)
{
    Pilha *aux,*ordenada=CriaPilha();
    int i,maior,valor;
    for(i=0;i<tam;i++)
    {
        Pilha *aux = CriaPilha();
        maior=pop(p);///tira da pilha
        push(p,maior);///devolve para pilha
        while(vazia(p))
        {
            valor=pop(p);
            if(valor>maior)
                maior=valor;
            push(aux,valor);
        }
        push(ordenada,maior);
        p=tira_maior_pilha(aux,maior);///vai tirar o elemento maior elemento da pilha que foi adicionado na ordenada, para continuar a comparação com os menores.
        libera(aux);
    }
    return ordenada;
}

Pilha* tira_maior_pilha(Pilha *p,int maior)
{
    Pilha *aux=CriaPilha();
    int valor;
    while(vazia(p))
    {
        valor=pop(p);
        if(valor!=maior)
            push(aux,valor);
    }
    return aux;
}    
    
