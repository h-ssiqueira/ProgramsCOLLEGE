#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Biblioteca para os quatro tipos de estruturas de dados juntamente.

Sendo os tipos de estruturas: pilha, fila, lista (encadeada, duplamente encadeada e circular) e árvore.

O sufixo apresentado para as listas inclui o tipo da lista.

*/

// Nós para fila e pilha com os 4 tipos de dados
typedef struct no{
    int valor;
    struct no *prox;
}No;


//                               ***********
//                               *  Pilha  *
//                               ***********
typedef struct pilha{
    No *no;
}Pilha;

// Criar pilha
Pilha* CriaP(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->no = NULL;
    return p;
}

// Verificação se está vazia
bool VaziaP(Pilha *p){
    if(p->no == NULL)
        return true;
    return false;
}

// Push para a pilha
No* InsertP(No *n, int v){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->prox = n;
    return novo;
}

void Push(Pilha *p, int v){
    p->no = InsertP(p->no,v);
}

// Pop para a pilha
No* RemoveP(No *n){
    No *nn = n->prox;
    free(n);
    return nn;
}

int Pop(Pilha *p){
    if(VaziaP(p)){
        printf("\nPilha vazia.");
        exit(1);
    }
    int v = p->no->valor;
    p->no = RemoveP(p->no);
    return v;
}

// Impressão da pilha
void ImprimeP(Pilha *p){
    if(VaziaP(p))
        printf("\nPilha Vazia.");
    else
        for(No *aux = p->no; aux != NULL; aux = aux->prox)
            printf("\n%d", aux->valor);
}

// Tamanho da pilha
int TamanhoP(Pilha *p){
    int i = 0;
    for(No *aux = p->no; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

// Inverte pilha
Pilha* InverteP(Pilha *p){
    Pilha *aux = CriaP();
    while(!VaziaP(p))
        Push(aux,Pop(p));
    return aux;
}

// Desalocamento de memória da pilha
void LiberaP(Pilha **p){
    No *aux = ((*p)->no), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*p);
    (*p) = NULL;
}


//                               **********
//                               *  Fila  *
//                               **********
typedef struct fila{
    No *ini;
    No *fim;
}Fila;

// Cria a fila
Fila* CriaF(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

// Verificação se está vazia
bool VaziaF(Fila *f){
    if(f->ini == NULL)
        return true;
    return false;
}

// Inserir na fila
No *InsertF(No *n, int v){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->prox = NULL;
    if(n != NULL)
        n->prox = novo;
    return novo;
}

void InsereF(Fila *f, int v){
    f->fim = InsertF(f->fim,v);
    if(f->ini == NULL)
        f->ini = f->fim;
}

// Remover da fila
No* RemoveF(No* n){
    No *aux = n->prox;
    free(n);
    return aux;
}

int RemoveFila(Fila *f){
    if(VaziaF(f)){
        printf("\nFila vazia");
        exit(1);
    }
    int v = f->ini->valor;
    f->ini = RemoveF(f->ini);
    if(f->ini == NULL)
        f->fim = NULL;
    return v;
}

// Imprime fila
void ImprimeF(Fila *f){
    if(VaziaF(f))
        printf("\nFila vazia.");
    else
        for(No *aux = f->ini; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

// Tamanho da fila
int TamanhoF(Fila *f){
    int i = 0;
    for(No *aux = f->ini; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

// Libera fila
void LiberaF(Fila **f){
    No *aux = ((*f)->ini), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    (*f) = NULL;
}

// Inverte fila
Fila* InverteF(Fila *f){
    Fila *aux = CriaF();
    Pilha *p = CriaP();
    while(!VaziaF(f))
        Push(p,RemoveFila(f));
    while(!VaziaP(p))
        InsereF(aux,Pop(p));
    LiberaF(&f);
    LiberaP(&p);
    return aux;
}


//                        *****************************
//                        *  Lista encadeada simples  *
//                        *****************************
typedef struct listae{
    int valor;
    struct listae *prox;
}ListaE;

// Criar lista encadeada
ListaE* CriaLE(){
    return NULL;
}

// Conferência de vazia
bool VaziaLE(ListaE *l){
    if(l == NULL)
        return true;
    return false;
}

// Inserção de elementos no início da lista
void InsereLE(ListaE **l, int v){
    ListaE *novo = (ListaE*)malloc(sizeof(ListaE));
    novo->valor = v;
    novo->prox = (*l);
    (*l) = novo;
}

// Retirar elemento da lista a partir da posição fornecida
void RetiraLE(ListaE **l,int v){
    ListaE *aux, *aux2;
    int i;
    for(i = 0, aux = (*l), aux2 = NULL; aux != NULL; i++, aux2 = aux, aux = aux->prox){
        if(i == v){
            if(v == 0)
                (*l) = aux->prox;
            else
                aux2->prox = aux->prox;
            free(aux);
            break;
        }
    }
}

// Busca se o dado existe na lista e retorna a posição deste
int BuscaLE(ListaE *l, int v){
    ListaE *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox)
        if(aux->valor == v)
            return i;
    return -1;
}

// Impressão da lista
void ImprimeLE(ListaE *l){
    if(VaziaLE(l))
        printf("\nLista vazia.");
    else
        for(ListaE *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

// Desalocamento da lista
void LiberaLE(ListaE **l){
    ListaE *aux = (*l), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}


//                       ********************************
//                       *  Lista duplamente encadeada  *
//                       ********************************
typedef struct listade{
    int valor;
    struct listade *ant, *prox;
}ListaDE;

// Criar lista duplamente encadeada
ListaDE* CriaLDE(){
    return NULL;
}

// Conferência de vazia
bool VaziaLDE(ListaDE *l){
    if(l == NULL)
        return true;
    return false;
}

// Inserção de elementos no início da lista
void InsereLDE(ListaDE **l, int v){
    ListaDE *novo = (ListaDE *)malloc(sizeof(ListaDE));
    novo->valor = v;
    novo->prox = (*l);
    novo->ant = NULL;
    (*l)->ant = novo;
    (*l) = novo;
}

// Remoção do elemento a partir da posição fornecida
void RetiraLDE(ListaDE **l, int v){
    ListaDE *aux, *aux2;
    int i;
    for(i = 0, aux = (*l), aux2 = NULL; aux != NULL; aux2 = aux, aux = aux->prox, i++){
        if(i == v){
            if(v == 0){
                (*l) = aux->prox;
                (*l)->ant = NULL;
            }
            else{
                aux2->prox = aux->prox;
                aux2 = aux2->prox;
                if(aux2 != NULL)
                    aux2->ant = aux->ant;
            }
            free(aux);
            break;
        }
    }
}

// Busca se o elemento existe na lista e retorna a posição deste
int BuscaLDE(ListaDE *l, int v){
    ListaDE *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

// Impressão da lista
void ImprimeLDE(ListaDE *l){
    if(VaziaLDE(l))
        printf("\nLista vazia.");
    else
        for(ListaDE *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

//Desaloca lista
void LiberaLDE(ListaDE **l){
    ListaDE *aux = (*l), *aux2;

    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}


//                             ********************
//                             *  Lista circular  *
//                             ********************
typedef struct listac{
    int valor;
    struct listac *prox;
}ListaC;

// Criar lista circular
ListaC* CriaLC(){
    return NULL;
}

// Conferência de vazia
bool VaziaLC(ListaC *l){
    if(l == NULL)
        return true;
    return false;
}

// Inserção de elementos no inicio da lista
void InsereLC(ListaC **l, int v){
    ListaC *novo = (ListaC *)malloc(sizeof(ListaC));
    novo->valor = v;
    novo->prox = (*l);
    if((*l)->prox != (*l)){
        ListaC *aux;
        for(aux = (*l)->prox; aux->prox != (*l); aux = aux->prox)
            continue;
        aux->prox = novo;
    }
    else if((*l)->prox == (*l))
        (*l)->prox = novo;
    (*l) = novo;
}

// Retirar elemento da lista a partir da posição fornecida
void RetiraLC(ListaC **l, int v){
    ListaC *aux, *ant;
    int i;
    for(i = 0, aux = (*l), ant = NULL; aux != NULL; ant = aux, aux = aux->prox, i++){
        if(i == v){
            if(v == 0){
                if((*l)->prox != (*l)){
                    for(ant = (*l)->prox; ant != (*l); ant = ant->prox)
                        continue;
                    (*l) = aux->prox;
                    ant->prox = (*l);
                }
                else
                    (*l) = NULL;
            }
            else{
                ant->prox = aux->prox;
                ant = ant->prox;
            }
            free(aux);
            break;
        }
    }
}

// Busca se o dado existe na lista e retorna a posição do mesmo
int BuscaLC(ListaC *l, int v){
    if(l->valor == v)
        return 1;
    ListaC *aux, *ant;
    int i;
    for(i = 1, aux = l->prox; aux != l; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}


// Impressão da lista
void ImprimeLC(ListaC *l){
    if(VaziaLC(l))
        printf("\nLista vazia.");
    else
        printf("\n%d",l->valor);
        for(ListaC *aux = l->prox; aux != l; aux = aux->prox)
            printf("\n%d",aux->valor);
}

// Desalocamento da lista
void LiberaLC(ListaC **l){
    ListaC *aux = (*l)->prox, *aux2;

    if(aux != (*l)){
        free(*l);
        (*l) = NULL;
        while(aux != NULL){
            aux2 = aux->prox;
            free(aux);
            aux = aux2;
        }
    }
    else{
        free(*l);
        (*l) = NULL;
    }
}


//                                     ********************
//                                     *  Árvore Binária  *
//                                     ********************
typedef struct arvore{
	int valor;
	struct arvore *dir, *esq;
}Arv;

// Criar árvore
Arv* CriaA(){
	return NULL;
}

// Verificação vazia
bool VaziaA(Arv *A){
	A ? return false : return true;
}

// Inserção
void InsereA(Arv **A, int n){
	Arv *novo = (Arv*)malloc(sizeof(Arv));
	novo->valor = n;
	novo->dir = novo->esq = NULL;
	if(VaziaA(*A)) // Caso seja o primeiro elemento na árvore
		(*A) = novo;
	else{

		Arv *pai = (*A);
		bool flag = true;

		while(flag){
			if(pai->valor < n){ // se o valor inserido for menor que o pai
				if(pai->dir == NULL){ // caso não haja folha na direita
					pai->dir = novo; // novo nó se situa na direita
					flag = false;
				}
				else // atualiza o valor do pai para chegar em uma folha
					pai = pai->dir;
			}
			else{ // senão o valor inserido é maior que o pai
				if(pai->esq == NULL){ // caso não haja folha na esquerda
					pai->esq = novo; // novo nó se situa na esquerda
					flag = false;
				}
				else // atualiza o valor do pai para chegar em uma folha
					pai = pai->esq;
			}
		}
    }
    /*
    if(VaziaA(*A)){
        (*A) = (Arv*)malloc(sizeof(Arv));
        if(VaziaA(*A)) return;
        (*A)->valor = n;
        (*A)->esq = (*A)->dir = NULL;
    }
    else{
        if(n < (*A)->valor)
            InsereA(&(*A)->esq,n);
        else// if(n > (*A)->valor)
            InsereA(&(*A)->dir,n);
    }
    */
}

// Busca se o valor existe
bool BuscaA(Arv *A, int n){
    while(A != NULL){
        if(A->valor < n) // direciona para a direita caso o número seja maior que o valor da partição da árvore
            A = A->dir;
        else if(A->valor > n) // direciona para a esquerda caso o número seja menor que o valor da partição da árvore
            A = A->esq;
        else // caso não seja nem menor e nem maior o número é igual
            return true;
    }
    return false;
    /*
    if(!A) return false;
    if(n == A->valor) return true;
    if(n < A->valor)
        return (BuscaA(A->esq,n));
    return (BuscaA(A->dir,n));
    */
}

// Retorna a quantidade de nos da árvore
int Nos(Arv *A){
    if(!A)
        return 0;
    return 1 + Nos(A->esq) + Nos(A->dir);
}

// Retorna a soma de todos os elementos da árvore
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

// Retorna o nível(altura) da árvore
int Nivel(Arv *A){
    int aux, aux2;
    if(VaziaA(A))
        return 0;
    aux = Nivel(A->esq);
    aux2 = Nivel(A->dir);
    return aux > aux2 ? aux+1 : aux2+1;
}

// Função auxiliar de remoção (maior valor da esquerda)
Arv *MaEsq(Arv **Aesq){
    if((*Aesq)->dir != NULL) // percorre a árvore ate chegar no maior valor da esquerda (último valor da direita)
        return MaEsq(&(*Aesq)->dir);
    else{
        Arv *aux = (*Aesq);
        if((*Aesq)->esq != NULL) // verifica se tem valor na esquerda
            (*Aesq) = (*Aesq)->esq; // se tiver atualiza para o da esquerda
        else
            (*Aesq) = NULL;
        return aux;
    }
}

// Função auxiliar de remoção (menor valor da direita)
Arv *MeDir(Arv **Adir){
    if((*Adir)->esq != NULL) // percorre a árvore ate chegar no menor valor da direita (último valor da esquerda)
        return MeDir(&(*Adir)->esq);
    else{
        Arv *aux = (*Adir);
        if((*Adir)->dir != NULL) // verifica se tem valor na direita
            (*Adir) = (*Adir)->dir; // se tiver atualiza para o da direita
        else
            (*Adir) = NULL;
        return aux;
    }
}

// Função que remove um nó
void RemoveA(Arv **A,int n){
	if(*A){
        Arv *aux;
        if(n < (*A)->valor){ // se o valor for menor ele se dirige a esquerda
            aux = (*A)->esq;
            if((aux->dir != NULL) || (aux->esq != NULL)) // verifica se o próximo da esquerda possui filhos
                RemoveA(&(*A)->esq,n);
            else{
                if(aux->valor == n){ // se não possuir ele confere se o valor é igual e desaloca
                    free(aux);
                    aux = NULL;
                    (*A)->esq = NULL;
                }
            }
        }
        else if(n > (*A)->valor){ // se o valor for maior ele se dirige a direita
            aux = (*A)->dir;
            if((aux->dir != NULL) || (aux->esq != NULL)) // verifica se o prox da direita possui filhos
                RemoveA(&(*A)->dir,n);
            else{
                if(aux->valor == n){ // se não possuir ele confere se o valor é igual e desaloca
                    free(aux);
                    aux = NULL;
                    (*A)->dir = NULL;
                }
            }
        }
        else{ // caso o nó que sera desalocado possua filhos
            aux = (*A);
            if((*A)->dir == NULL){ // se possuir filho na esquerda
                (*A) = (*A)->esq;
                free(aux);
            }
            if((*A)->esq == NULL){ // se possuir filho na direita
                (*A) = (*A)->dir;
                free(aux);
            }
            else{ // possui filhos
                aux = MaEsq(&(*A)->esq); // função que retorna o modulo que sera trocado (maior valor da esquerda com seu filho da direita se existir)
                //aux = MeDir(&(*A)->dir); //função que retorna o modulo que sera trocado (menor valor da direita com seu filho da esquerda se existir)
                aux->esq = (*A)->esq; //(*A)->esq contem o maior nº da subárvore esquerda ou NULL
                aux->dir = (*A)->dir; // anexa o da direita fazendo o ramo da arvore "cair"
                free(*A);
                (*A) = aux;
            }
        }
    }
}

// Impressão pre order
void ImpressaoPre(Arv *A){
	printf("%d ",A->valor);
	if(A->esq != NULL)
		ImpressaoPre(A->esq);
	if(A->dir != NULL)
		ImpressaoPre(A->dir);
}

// Impressão in order
void ImpressaoIn(Arv *A){
	if(A->esq != NULL)
		ImpressaoIn(A->esq);
	printf("%d ",A->valor);
	if(A->dir != NULL)
		ImpressaoIn(A->dir);
}

// Impressão pos order
void ImpressaoPos(Arv *A){
	if(A->esq != NULL)
		ImpressaoPos(A->esq);
	if(A->dir != NULL)
		ImpressaoPos(A->dir);
	printf("%d ",A->valor);
}

// Desaloca árvore
Arv* LiberaA(Arv *A){
	if(A->dir != NULL) // verifica se há informações na direita
		LiberaA(A->dir);
	if(A->esq != NULL) // verifica se há informações na esquerda
		LiberaA(A->esq);
	free(A); // chega em uma folha e libera a informação
	return NULL;
}

