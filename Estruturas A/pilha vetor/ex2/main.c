#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void ordena(Pilha *p);

int main()
{
    Pilha *p = cria();
    int i,x;
    for(i = 0;i<MAX;i++){
        printf("Insira um valor para a pilha: ");
        scanf("%d",&x);
        push(p,x);
    }
    ordena(p);
    imprime(p);

    libera(p);
    return 0;
}

void ordena(Pilha *p){
    Pilha *impar = cria(),*par = cria();
    int i,value;
    for(i = p->n;i > 0;i--){
        if(pop(p,&value)){
            if(value % 2 == 0)
                push(par,value);
            else
                push(impar,value);
        }
    }
    for(i = par->n;i>0;i--){
        if(pop(par,&value))
            push(p,value);
    }
    for(i = impar->n;i>0;i--){
        if(pop(impar,&value))
            push(p,value);
    }
}
