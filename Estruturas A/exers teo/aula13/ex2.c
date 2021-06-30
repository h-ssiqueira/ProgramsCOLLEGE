#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore.h"

int Busca_ITER(Arv *arvore, int b){
    if(arvore->valor == b)
        return 1;
    else{
        Arv *aux = arvore;
		bool flag = true;
		
		while(flag){
            if(aux->valor == b)
                return 1;
			else if(aux->valor < b){ 
				if(aux->dir == NULL)
					flag = false;
				else
					aux = aux->dir;
			}
			else{
				if(aux->esq == NULL)
					flag = false;
				else 
					aux = aux->esq;
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
    
    printf("\n\tInsira o elemento a ser buscado: ");
    scanf("%d",&v);
    
    printf("\n\tElemento ");
    Busca_ITER(arvore,v) ? printf("existente\n") : printf("inexistente\n");
    
    LiberaA(arvore);
    return 0;
}
