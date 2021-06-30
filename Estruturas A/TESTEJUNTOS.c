#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PILHA_FILA.h"

/*NÃO É NECESSARIO CRIAR AS ESTRUTURAS PORQUE JÁ ESTÃO NA BIBLIOTE*/
Pilha* inverte(Pilha *original)
{
    Pilha *aux;
    aux=CriaPilha();
    while(original->prim!=NULL)
    {
        push(aux,(pop(original)));
    }

    return aux;

}

int main()
{
    setlocale(LC_ALL,"portuguese");
    Pilha *topo;
    Fila *F;
    int a;

    topo= CriaPilha();
    F = CriaFila();
    a=vazia(topo);
    if(a==0)
    {
        printf("\n\t\t PILHA VAZIA!!!!\n\n");
    }
    else
    {
        printf("\n\t\t PILHA COM ELEMENTOS!!!!\n\n");
    }
    imprime (topo);
    push(topo,23);
    push(topo,16);
    push(topo,44);
    push(topo,18);
    imprime (topo);
    topo = inverte(topo);
    imprime(topo);
    InsereFila(F,5);
    InsereFila(F,7);
    InsereFila(F,9);
    InsereFila(F,11);
    imprimeFila(F);
    InsereFila(F,pop(topo));
    imprime(topo);
    imprimeFila(F);


   /* a=pop(topo);
    printf("\n\t a = %d",a);
    imprime (topo);*/
    topo = libera(topo);
    if(!topo)
    {
        printf("\n\n\t\t PILHA VAZIA!!!! Não existe nem mais a estrutura\n\n");
    }
    else
    {
        printf("\n\t\t PILHA COM ELEMENTOS!!!!\n\n");

    }
    F = liberaFila(F);
    if(!F)
    {
        printf("\n\n\t\t FILA VAZIA!!!! Não existe nem mais a estrutura\n\n");
    }
    else
    {
        printf("\n\t\t FILA COM ELEMENTOS!!!!\n\n");

    }
}
