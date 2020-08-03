#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arvore.h"


//EX1
int folhas(Arv *a){
    if(!a) return 0;
    if(a->dir != NULL || a->esq != NULL)
        return folhas(a->dir) + folhas(a->esq);
    /*else if(a->dir != NULL)
        return folhas(a->dir);
    else if(a->esq != NULL)
        return folhas(a->esq);*/
    return 1;
}

//EX2
int ancestrais(Arv *a, int x){
    Arv *aux = a;
    bool flag = true;
    int ancestrais = 0;

    if(a->valor == x)
        return 0;
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
                if(aux->valor == x)
                    count++;
                aux = aux->dir; // na funçao insere, se for igual sempre vai para a direita
            }
        }
    }
    return count;
}

//4)
int soma_par(Arv *A){
    /*int par = 0;
    if(A->valor % 2 == 0)
        par = A->valor;
    if(A->esq != NULL)
        par += soma_par(A->esq);
    if(A->dir != NULL)
        par += soma_par(A->dir);
    return par;*/
    if(!A) return 0;
    if(A->valor % 2 == 0) return A->valor + soma_par(A->esq) + soma_par(A->dir);
    return soma_par(A->esq) + soma_par(A->dir);
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

int lv(Arv *A){
    int aux,aux2;
    if(A->dir == NULL && A->esq == NULL)
        return 0;
    if(A->esq != NULL)
        aux = 1 + lv(A->esq);
    if(A->dir != NULL)
        aux2 = 1 + lv(A->dir);
    return aux > aux2 ? aux : aux2;
    /*if(aux > aux2)
        return aux;
    else
        return aux2;*/
}

int TotalEle(Arv *A){
    /*int x;
    x = A->valor;
    if(A->esq != NULL)
        x += TotalEle(A->esq);
    if(A->dir != NULL)
        x += TotalEle(A->dir);
    return x;*/
    if(!A) return 0;
    return A->valor + TotalEle(A->dir) + TotalEle(A->esq);
}

int totalNo(Arv *A){
    /*int sum = 1;
    if(A->esq == NULL && A->dir == NULL)
        return 1;*/
    /*if(A->esq != NULL)
        sum += totalNo(A->esq);
    if(A->dir != NULL)
        sum += totalNo(A->dir);
    return sum;*/
    if(!A) return 0;
    return 1 + totalNo(A->esq) + totalNo(A->dir);
}

int Filhos(Arv *Pai){
    if(!Pai) return 0;
    if(Pai->esq != NULL && Pai->dir == NULL)
        return 1 + Filhos(Pai->esq);
    if(Pai->esq == NULL && Pai->dir != NULL)
        return 1 + Filhos(Pai->dir);
    return Filhos(Pai->esq) + Filhos(Pai->dir);
}

int menor(Arv *Pai){
    //Arv *aux = Pai;
    while(Pai->esq != NULL)
        Pai = Pai->esq;
    return Pai->valor;
}

int main(){
    Arv *A = CriaA();
    int x;
    
    InsereA(&A,22);
    InsereA(&A,29);
    InsereA(&A,26);
    InsereA(&A,27);
    InsereA(&A,15);
    InsereA(&A,20);
    InsereA(&A,10);
    InsereA(&A,18);
    InsereA(&A,14);
    InsereA(&A,12);
    /*InsereA(&A,100);
    InsereA(&A,110);
    */
    
    /*if(BuscaA(A,2))
        printf("ERRO");
    else
        printf("CERTO");
    
    printf("\n\tSoma dos elementos = %d",TotalEle(A));
    printf("\n\tNivel da arvore = %d",lv(A));
    printf("\n\tNos da arvore = %d",totalNo(A));
    printf("\n\tTotal de folhas = %d",folhas(A));
    
    printf("\n\tTotal de ancestrais de 20 = %d",ancestrais(A,10));
    printf("\n\tTotal de ocorrencias de 25 = %d",ocorrencias(A,25));
    printf("\n\tSoma de elementos pares: %d",soma_par(A));
    */
    RemoveA(&A,15);
    //RemoveA(&A,22);
    
    //printf("\n\tmenor = %d",menor(A));
    //printf("\n%d",A->valor);
    
    printf("\n\n");
    ImpressaoPre(A);
    
    printf("\n\n");
    ImpressaoIn(A);
    
    printf("\n\n");
    ImpressaoPos(A);
  
    A = Remove(A);
    if(VaziaA)
        printf("\n\tArvore desalocada\n");
    return 0;
}
