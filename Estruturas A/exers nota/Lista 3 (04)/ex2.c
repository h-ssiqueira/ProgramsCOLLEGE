//Henrique Sartori Siqueira 19240472
//Rafael Silva Barbon       19243633
#include <stdio.h>
#include <stdlib.h>
/*
  Faça  um  programa  que  receba  duas  listas  de  inteiros  L1  e  L2.  A  quantidade  deelementos em L1 e L2 pode ser diferente. Seu programa deverá verificar se a lista L1 está contida nalista L2 e exibir mensagem informativa. Exemplos:A lista L1 = {2,3} está contida na lista L2 = {1,2,3,4,5} A lista L1 = {1,2,3} não está contida na lista L2 = {4,5}
 */

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* Inicializa(void){
    return NULL;
}

Lista* Insere(Lista *recebida, int valor){
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info=valor;
    novo->prox=recebida;
    return novo;
}
    
void Imprime(Lista *recebida){
    Lista *aux;
    for(aux=recebida; aux!=NULL; aux = aux->prox)
        printf("  %d", aux->info);
}

Lista* Busca(Lista *recebida,int valor)
{
    Lista *aux;
    for(aux=recebida;aux!=NULL;aux=aux->prox)
        if(aux->info==valor)
            return aux;
    return NULL;
}

Lista* Libera(Lista *L){
    Lista *aux;
    while(L!=NULL){
        aux=L->prox;
        free(L);
        L=aux;
    }
    return NULL;
}

int Vazia(Lista *recebida)
{
    if(recebida==NULL)
        return 1;
    return 0;
}

int Contida(Lista *L1, Lista *L2, int tam1)
{
    int infoaux, cont = 0;
    Lista *aux1;
    for(aux1=L1; aux1 != NULL; aux1=aux1 -> prox){
        infoaux = aux1->info;
        if(Busca(L2,infoaux)!=NULL){//Achou 
            cont++;
        }
    }
    if(cont==tam1)//existem todos os valores de L1 em L2
        return 1;
    return 0;
}
    
int main()
{
    Lista *L1=Inicializa(), *L2=Inicializa();
    int info, contL1=0;
    do{
        printf("\nInsira Valores para a lista 1(-999 p/ sair):");
        scanf("%d",&info);
        if(info!=-999){
            L1=Insere(L1, info);
            contL1++;
        }
    }while(info!=-999);
    system("clear");
    do{
        printf("\nInsira Valores para a lista 2:(-999 p/ sair)");
        scanf("%d",&info);
        if(info!=-999)
            L2=Insere(L2, info);
    }while(info!=-999);
    
    system("clear");
    printf("\nListas Inseridas:\nLista 1:\n\t{");
    Imprime(L1);
    printf(" }");
    printf("\nLista 2:\n\t{");
    Imprime(L2);
    printf(" }");
    if(Contida(L1, L2, contL1))
        printf("\n\nA lista L1 esta contida em L2\n");
    else 
        printf("\n\nA lista L1 nao esta contida em L2\n");
    
    L1=Libera(L1);
    L2=Libera(L2);
    if(Vazia(L1)&&Vazia(L2));
        printf("\nEncerrado com sucesso!!\n");
    return 0;
    
}
