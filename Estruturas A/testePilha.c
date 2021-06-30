#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PILHA.h"

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
    int a;

    topo= CriaPilha();
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
    return 0;
}
