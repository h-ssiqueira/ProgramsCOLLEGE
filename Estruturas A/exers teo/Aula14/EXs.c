#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arvore.h"

//EX1
int folhas(Arv *a){
    if(a->dir != NULL && a->esq != NULL)
        return folhas(a->dir) + folhas(a->esq);
    else if(a->dir != NULL)
        return folhas(a->dir);
    else if(a->esq != NULL)
        return folhas(a->esq);
    else
        return 1;
}

//EX2
int ancestrais(Arv *a, int x){
    Arv *aux = a;
    bool flag = true;
    int ancestrais = 0;

    if(a->valor == x)
        return -1;
    while(flag){
        if(aux->valor > x){
            if(aux->esq == NULL)
                flag = false;
            else if(aux->esq->valor == x || aux->dir->valor == x)
                return ++ancestrais;
            else
                aux = aux->esq;
        }
        else if(aux->valor < x){
            if(aux->dir == NULL)
                flag = false;
            else if(aux->esq->valor == x || aux->dir->valor == x)
                return ++ancestrais;
            else
                aux = aux->dir;
        }
        ancestrais++;
    }
    return 0;
}

//EX3
int ocorrencias(Arv *a, int x){
    Arv *aux = a;
    int count = 0;
    bool flag = true;
    while(flag){
        if(aux->valor > x){
            if(aux->esq == NULL)
                flag = false;
            else
                aux = aux->esq;
        }
        else if(aux->valor < x){
            if(aux->dir == NULL)
                flag = false;
            else
                aux = aux->dir;
        }
        else{  // se for ==
            flag = false;
            while(aux != NULL){
                if(aux->valor == x){
                    count++;
                    aux = aux->dir; // na funçao insere, se for igual sempre vai para a direita
                }
            }
        }
    }
    return count;
}

int main(){
    Arv *A = CriaA();
    int x;
    
    InsereA(&A,50);
    InsereA(&A,70);
    InsereA(&A,90);
    InsereA(&A,40);
    InsereA(&A,20);
    InsereA(&A,25);
    InsereA(&A,25);
    InsereA(&A,15);
    InsereA(&A,2);
    
    
    x = folhas(A);
    printf("\n\tTotal de folhas = %d",x);
    
    x = ancestrais(A,20);
    printf("\n\tTotal de ancestrais de 20 = %d",x);
    
    x = ocorrencias(A,25);
    printf("\n\tTotal de ocorrencias de 25 = %d",x);
    
    A = LiberaA(A);
    return 0;
}
