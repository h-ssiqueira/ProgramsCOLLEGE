#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore.h"

int Ancestrais(Arv *arvore, int v){
    int count = 0;
    Arv *aux = arvore;
    bool flag = true;

    while(flag){
        if(aux->valor == v)
            return count;
        else if(aux->valor > v){
            if(aux->esq == NULL)
                flag = false;
            else{
                aux = aux->esq;
                count++;
            }
        }
        else{
            if(aux->dir == NULL)
                flag = false;
            else{
                aux = aux->dir;
                count++;
            }
        }
    }
    return 0;
}

int main(){
    Arv *arvore = CriaA();
    int v;
    
    do{
        printf("\n\tInsira um valor para a arvore (-999 p/ continuar): ");
        scanf("%d",&v);
        if(v != -999)
            InsereA(&arvore,v);
    }while(v != -999);
    
    printf("\n\tInsira o elemento: ");
    scanf("%d",&v);
    
    printf("\n\tO elemento %d possui %d ancestrais", v, Ancestrais(arvore,v));
    
    
    LiberaA(arvore);
    return 0;
}
