#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* inverte(Pilha *p);

int main()
{
    Pilha *p = cria();
    int v;
    for(int i = 0;i<MAX;i++){
        printf("\tInsira um numero: ");
        scanf("%d",&v);
        push(p,v);
    }

    p = inverte(p);

    imprime(p);
    libera(p);
    return 0;
}

Pilha* inverte(Pilha *p){
    Pilha *aux = cria();int x;
    while(pop(p,&x)){
        ///if(pop(p,&x))
            push(aux,x);
    }
    return aux;
}
