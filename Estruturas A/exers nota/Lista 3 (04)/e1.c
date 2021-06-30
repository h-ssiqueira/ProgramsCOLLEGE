//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon       19243633
#include<stdio.h>
#include<stdlib.h>
/*
 Faça um programa que receba uma lista de valores inteiros e um valor inteiro n. Seu
programa deverá dividir a lista em duas, de tal forma que a segunda lista comece no primeiro
nó logo após a primeira ocorrência de n na lista original. Exibir os itens das duas listas após a
divisão. Caso n não exista na lista, exibir mensagem informativa.
 */
typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista * Inicializa(){
    return NULL;
}

Lista * Insere(Lista *recebida,int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = recebida;
    return novo;
}

void Imprime(Lista *recebida){
    for(Lista *p = recebida; p!=NULL; p=p->prox){
        printf("Info = %d\n",p->info);
    }
}

int Vazia(Lista *recebida){
    if(recebida!=NULL)
        return 0;
    else 
        return 1;
}

Lista * Busca(Lista *recebida,int v){
    for(Lista *p = recebida; p!=NULL; p = p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;
}

void Libera(Lista *recebida){
    Lista *aux = recebida, *aux2;
    while(aux!=NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;        
    }
}

Lista * divide(Lista *l,int n){
    Lista *aux = l, *l2 = Inicializa();
    int x = 1;
    while(aux != NULL){
        if(aux->info == n){
            l2 = aux->prox;
            aux->prox = NULL;
            x = 0;
            break;
        }
        aux = aux->prox;
    }
    if(x==1)
        printf("\n\tLista 2 nao pode ser criada.");
    return l2;
}

int main(){
    Lista *l = Inicializa(),*l2 = Inicializa();
    int n;
    
    do{
        printf("\n\tInsira um valor para a lista (-111 para sair): ");
        scanf("%d",&n);
        if(n != -111)
            l = Insere(l,n);
    }while(n != -111);
    
    printf("\n\tInsira um valor para dividir a lista em duas: ");
    scanf("%d",&n);
    
    printf("\n\tLista original:\n");
    Imprime(l);
    
    l2 = divide(l,n);
    printf("\n\n\tLista 1:\n");
    Imprime(l);
    printf("\n\n\tLista 2:\n");
    Imprime(l2);
    
    Libera(l);
    Libera(l2);
    return 0;
}
