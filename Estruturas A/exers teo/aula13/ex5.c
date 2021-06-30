#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore.h"

int soma(Arv *arvore, int count){
    if(arvore->esq != NULL)
		count = soma(arvore->esq,count);
	if(arvore->dir != NULL)
		count = soma(arvore->dir,count);
    return count + arvore->valor;
}

int Elementos(Arv *arvore, int count){
    if(arvore->esq != NULL)
		count = Elementos(arvore->esq,count);
	if(arvore->dir != NULL)
		count = Elementos(arvore->dir,count);
    return count + 1;
}

int Descendentes(Arv *arvore, int v){
    Arv *aux = arvore;
    bool flag = true;

    if(arvore->valor == v)
        return 0;
    while(flag){
        if(aux->valor == v)
            return Elementos(aux,-1);
        else if(aux->valor > v){
            if(aux->esq == NULL)
                flag = false;
            else
                aux = aux->esq;
        }
        else{
            if(aux->dir == NULL)
                flag = false;
            else
                aux = aux->dir;
        }
    }
}

int Pai_no(Arv *arvore, int v){
    Arv *aux = arvore;
    bool flag = true;

    if(arvore->valor == v)
        return -1;
    while(flag){
        if(aux->valor > v){
            if(aux->esq == NULL)
                flag = false;
            else if(aux->esq->valor == v || aux->dir->valor == v)
                return aux->valor;
            else
                aux = aux->esq;
        }
        else if(aux->valor < v){
            if(aux->dir == NULL)
                flag = false;
            else if(aux->esq->valor == v || aux->dir->valor == v)
                return aux->valor;
            else
                aux = aux->dir;
        }
    }
}

int main(){
    Arv *arvore = CriaA();
    int v, count = 0;
    
    do{
        printf("\n\tInsira um valor para a arvore (-999 p/ continuar): ");
        scanf("%d",&v);
        if(v != -999)
            InsereA(&arvore,v);
    }while(v != -999);
    
    count = soma(arvore,count);
    printf("\n\tsoma de elementos: %d",count);
    printf("\n\tInsira o elemento a ser buscado: ");
    scanf("%d",&v);
    
    printf("\n\tO elemento %d ",v);
    count = Descendentes(arvore,v);
    printf("\n\t  possui %d descendentes",count);
    count = Pai_no(arvore,v);
    if(count != -1)
        printf("\n\t  possui %d como pai",count);
    else
        printf("\n\t  nao possui pai\n");
    
    
    
    LiberaA(arvore);
    return 0;
}
