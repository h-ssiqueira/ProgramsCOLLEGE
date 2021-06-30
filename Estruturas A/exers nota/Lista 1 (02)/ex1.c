#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"

Pilha* inverte(Pilha *p);
Pilha* intersecao(Pilha **p1,Pilha **p2);

int main()
{
    Pilha *p1 = CriaPilha(), *p2 = CriaPilha(),*p3;
    int info;
    do{

        printf("\n\tInsira um valor para a pilha 1 (-999 para sair): ");
        scanf("%d",&info);
        if(info != -999)
            push(p1,info);
    }while(info != -999);
    do{

        printf("\n\tInsira um valor para a pilha 2 (-999 para sair): ");
        scanf("%d",&info);
        if(info != -999)
            push(p2,info);
    }while(info != -999);

    p3 = intersecao(&p1,&p2);

    printf("\n\n\n");
    imprime(p1);
    printf("\n\n\n");
    imprime(p2);
    printf("\n\n\n");
    imprime(p3);

    p1 = libera(p1);
    p2 = libera(p2);
    p3 = libera(p3);
    return 0;
}

Pilha* inverte(Pilha *p){
	Pilha *aux = CriaPilha();
	int x;
	while(vazia(p)){
		x = pop(p);
		push(aux,x);
	}
	return aux;
}

Pilha* intersecao(Pilha **p1,Pilha **p2){
    Pilha *p1inv = CriaPilha(),*p2inv = CriaPilha(), *inter = CriaPilha();
    int val,conf;

    while(vazia(*p1)){
        val = pop(*p1);
        while(vazia(*p2)){
            conf = pop(*p2);
            if(val == conf)
                push(inter,val);
            push(p2inv,conf);
        }
        push(p1inv,val);
        *p2 = inverte(p2inv);
    }
    *p1 = inverte(p1inv);
    p1inv = libera(p1inv);
    p2inv = libera(p2inv);
	inter = inverte(inter);
    return inter;
}
