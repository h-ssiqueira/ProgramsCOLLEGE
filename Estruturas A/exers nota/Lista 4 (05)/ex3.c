#include <stdio.h>
#include <stdlib.h>

struct lista 
{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* CriaLista(void)
{
    return NULL;
}

Lista* Insere(Lista *recebida, int valor)
{
    Lista *novo=(Lista*)malloc(sizeof(Lista));
    novo->info=valor;
    novo->prox=recebida;
    return novo;
}

int VaziaLista(Lista *recebida)
{
    if(recebida == NULL)
        return 1;
    return 0;
}

void Imprime(Lista *recebida)
{
    Lista *aux;
    if(VaziaLista(recebida))
        printf("\nLista Vazia!");
    for(aux = recebida; aux!= NULL; aux = aux->prox)
        printf("\nInfo: %d", aux->info);
}

Lista* busca_e_move(Lista *recebida, int valor)
{
    Lista *aux=recebida, *anterior=NULL;
    int flag=0;
    while(!VaziaLista(aux))
    {
        if(aux->info==valor)
        {
            printf("\nElemento encontrado");
            flag=1;
            if(anterior==NULL)//Já é o primeiro elemento
                break;
            else
            {
                anterior->prox=aux->prox;
                aux->prox=recebida;
                return aux;
            }
        }
        anterior = aux;
        aux = aux->prox;
    }
    if(!flag)
        printf("\nElemento nao encontrado");
    return recebida;
}
  
Lista* libera(Lista *recebida)
{
    Lista *aux;
    while(!VaziaLista(recebida))
    {
        aux=recebida->prox;
        free(recebida);
        recebida=aux;
    }
    return NULL;
}

int main()
{
    Lista *L=CriaLista();
    int info;
    do{
        printf("\nInsira elementos na Lista(-999 p/ sair):");
        scanf("%d",&info);
        if(info != -999)
            L=Insere(L,info);
    }while(info != -999);
        system("clear");
   
    do{
        printf("\nLista Lida:");
        Imprime(L);
        printf("\nDigite o elemento que deseja buscar na lista(-999 p/ sair):");
        scanf("%d", &info);
        if(info != -999)
            L=busca_e_move(L, info);
    }while(info != -999);
    L=libera(L);
    if(VaziaLista(L))
        printf("\nEncerrado com sucesso!");
    return 0;
}
    
