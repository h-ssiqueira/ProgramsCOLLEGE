#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* ordena(Pilha *p);

int main()
{
    Pilha *p = cria();
    int i,x;
    for(i = 0;i<MAX;i++){
        printf("Insira um valor para a pilha: ");
        scanf("%d",&x);
        push(p,x);
    }
    p = ordena(p);
    imprime(p);

    libera(p);
    return 0;
}

Pilha* ordena(Pilha *p){
    Pilha *a=cria(),*b=cria();
    int val,i;
    if(pop(p,&val))
        push(b,val);
    for(i = 2;i < MAX;i++){
        if(pop(p,&val))
            push(a,val);
    }
    for(i = 2;i < MAX;i++){
        if(pop(a,&val))
            push(b,val);
    }
    if(pop(p,&val))
        push(b,val);
    libera(a);
    return b;


}
