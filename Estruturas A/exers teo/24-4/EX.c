#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arvore{
	int valor;
	struct arvore *dir;
	struct arvore *esq;
}Arv;

Arv* CriaA(){
	return NULL;
}

bool VaziaA(Arv *A){
	if(A == NULL)
		return true;
	return false;
}

void InsereA(Arv **A, int v){
	Arv *novo = (Arv*)malloc(sizeof(Arv));
	novo->valor = v;
	novo->dir = NULL;
	novo->esq = NULL;
	if(VaziaA(*A)) //caso seja o primeiro elemento na árvore
		(*A) = novo;
	else{
		Arv *pai = (*A);
		bool flag = true;
		while(flag){
			if(pai->valor < v){ //se o valor inserido for menor que o pai
				if(pai->dir == NULL){ //caso não haja folha na direita
					pai->dir = novo; //novo nó se situa na direita
					flag = false;
				}
				else //atualiza o valor do pai para chegar em uma folha
					pai = pai->dir;
			}
			else{ //senão o valor inserido é maior que o pai
				if(pai->esq == NULL){ //caso não haja folha na esquerda
					pai->esq = novo; //novo nó se situa na esquerda
					flag = false;
				}
				else //atualiza o valor do pai para chegar em uma folha
					pai = pai->esq;
			}
		}
	}
}

bool BuscaA(Arv *A, int n){
    Arv *aux = A;
    while(aux != NULL){
        if(aux->valor < n) //direciona para a direita caso o número seja maior que o valor da partição da árvore
            aux = aux->dir;
        else if(aux->valor > n) //direciona para a esquerda caso o número seja menor que o valor da partição da árvore
            aux = aux->esq;
        else //caso não seja nem menor e nem maior o número é igual
            return true;
    }
    return false;
}

void ImpressaoPre(Arv *A){
	printf("%d ",A->valor);
	if(A->dir != NULL)
		ImpressaoPre(A->dir);
	if(A->esq != NULL)
		ImpressaoPre(A->esq);
}

void ImpressaoIn(Arv *A){
	if(A->dir != NULL)
		ImpressaoIn(A->dir);
	printf("%d ",A->valor);
	if(A->esq != NULL)
		ImpressaoIn(A->esq);
}

void ImpressaoPos(Arv *A){
	if(A->dir != NULL)
		ImpressaoPos(A->dir);
	if(A->esq != NULL)
		ImpressaoPos(A->esq);
	printf("%d ",A->valor);
}

Arv* LiberaA(Arv *A){
	if(A->dir != NULL)//verifica se há informações na direita
		LiberaA(A->dir);
	if(A->esq != NULL)//verifica se há informações na esquerda
		LiberaA(A->esq);
	free(A);//chega em uma folha e libera a informação
	return NULL;
}

int main(){
	Arv *A = CriaA();
	int x = 0;
	while(x != -999){
		printf("\nInsira um valor para a arvore (-999 p/ continuar): ");
		scanf("%d",&x);
		if(x!=-999)
			InsereA(&A,x);
	}
	if(VaziaA(A))
		exit(0);

	printf("\nInsira o elemento a ser buscado: ");
	scanf("%d",&x);
	if(BuscaA(A,x))
		printf("\nElemento existente");
	else
		printf("\nElemento nao existente");

	printf("\nImpressao pre-order:\n");
	ImpressaoPre(A);
	printf("\nImpressao in-order:\n");
	ImpressaoIn(A);
	printf("\nImpressao pos-order:\n");
	ImpressaoPos(A);

	A = LiberaA(A);
	return 0;
}
