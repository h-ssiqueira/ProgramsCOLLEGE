#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void retiraneg(Pilha *p);

int main()
{
    Pilha *p = cria();
    int i,x;
    for(i = 0;i<MAX;i++){
        printf("Insira um valor para a pilha: ");
        scanf("%d",&x);
        push(p,x);
    }
    retiraneg(p);
    imprime(p);

    libera(p);
    return 0;
}

void retiraneg(Pilha *p){
    Pilha *x = cria();
    int i,z;
    for(i = p->n;i>0;i--){
        if(pop(p,&z))
            if(z>0)
                push(x,z);
    }
    for(i = x->n;i>0;i--){
        if(pop(x,&z))
            push(p,z);
    }
    libera(x);
}
