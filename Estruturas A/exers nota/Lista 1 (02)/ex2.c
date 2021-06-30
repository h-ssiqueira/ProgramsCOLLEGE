/*

Em termos computacionais de desempenho haveria menos loops, pois so haveria a necessidade de
fazer a conferencia das pilhas somente uma vez para cada valor e inverte-la ao final. Porem, em termos de codigo,
havera mais complexidade dentro da funcao, ou seja, tera condicionais de verificacao para ambas as pilhas a fim de que
os valores se atualizem, igualando-se para que haja a interseccao.

*/





#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"

Pilha* inverte(Pilha *p);
void volta(Pilha ***p,Pilha *inv);
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

void volta(Pilha ***p,Pilha *inv){
	//Pilha *aux = CriaPilha();
	int x;
	while(vazia(inv)){
		x = pop(inv);
		push(**p,x);
	}
}

Pilha* intersecao(Pilha **p1,Pilha **p2){
    Pilha *p1inv = CriaPilha(),*p2inv = CriaPilha(), *inter = CriaPilha();
    int val1,val2;
	val1 = pop(*p1);
	val2 = pop(*p2);
    while(1){
	    if(val1 == val2){
	        push(inter,val1);
            push(p2inv,val2);
	        push(p1inv,val1);
			if(vazia(*p1)&&vazia(*p2)){
				val1 = pop(*p1);
				val2 = pop(*p2);
			}
			else 		
				break;
		}else if(val1 > val2){
			push(p1inv,val1);
			if(vazia(*p1))
				val1 = pop(*p1);			
			else
				break;
		}else{
			push(p2inv,val2);
			if(vazia(*p2))
				val2 = pop(*p2);
			else 
				break;
		}
    }        
	volta(&p2,p2inv);
    volta(&p1,p1inv);
    p1inv = libera(p1inv);
    p2inv = libera(p2inv);
	inter = inverte(inter);
    return inter;
}
