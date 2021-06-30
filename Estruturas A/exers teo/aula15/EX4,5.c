#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//4)
int soma_par(Arv *A){
    int par = 0;
    if(A->valor % 2 == 0)
        par = A->valor;
    if(A->esq != NULL)
        par += soma_par(A->esq);
    if(A->dir != NULL)
        par += soma_par(A->dir);
    return par;
}

//5)
Arv * Remove(Arv *A){
    if(A->esq != NULL)
        Remove(A->esq);
    if(A->dir != NULL)
        Remove(A->dir);
    free(A);
    return NULL;    
}

int main(){
    Arv *A = CriaA();
    
    InsereA(&A,1);
    InsereA(&A,2);
    InsereA(&A,4);
    InsereA(&A,5);
    InsereA(&A,3);
    InsereA(&A,6);
    InsereA(&A,7);
    
    printf("\n\tSoma de elementos pares: %d",soma_par(A));
    
    A = Remove(A);
    if(VaziaA)
        printf("\n\tArvore desalocada\n");
    return 0;
}
