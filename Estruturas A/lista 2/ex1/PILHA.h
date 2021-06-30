#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/*

Pilha* CriaPilha (void)     CRIA A PILHA

no* ins_ini (no* t, int a)  AUXILIAR DA INSERÇÃO
void push (Pilha* p, int v) INSERÇÃO

no* ret_ini (no* l)         AUXILIAR DA REMOÇÃO
int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

void libera (Pilha* p)      LIBERA A PILHA

void imprime (Pilha* p)     IMPRIMA A PILHA

int vazia(Pilha *p)	    VERIFICA SE A PILHA ESTÁ VAZIA



*/

typedef struct nos
{
    int info;
    struct nos *prox;
}no;

typedef struct pilha
{
   no *prim;
}Pilha;

Pilha* CriaPilha (void)
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->prim = NULL;
   return p;
};

no* ins_ini (no* t, int a)
{
    no* aux = (no*) malloc(sizeof(no));
    aux->info = a;
    aux->prox = t;
    return aux;
};

void push (Pilha* p, int v)
{
    p->prim = ins_ini(p->prim,v);
};

no* ret_ini (no* l)
{
    no* p = l->prox;
    free(l);
    return p;
};

int pop (Pilha* p)
{
    int v;
    if (p==NULL)
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
};

Pilha * libera (Pilha* p)
{
    no* q = p->prim;
    while (q!=NULL)
    {
        no* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return(NULL);
};

void imprime (Pilha* p)
{
    no* q;
    if(!p)
    {
        printf("\n\n\tPILHA VAZIA!!!!");
    }
    else
    {
        printf("\n\n\tPILHA: ");
        for (q=p->prim; q!=NULL; q=q->prox)
        {
            printf("% 2d",q->info);
        }
    }


};

int vazia(Pilha *p)
{
    if (!p->prim)
    {
        return 0; //pilha nao vazia
    }
    return 1;
}

#endif // PILHA_H_INCLUDED
