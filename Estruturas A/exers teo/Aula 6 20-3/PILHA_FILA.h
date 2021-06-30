#ifndef PILHA_FILA_H_INCLUDED
#define PILHA_FILA_H_INCLUDED

/* FUNÇÕES DE MANIPULAÇÃO DE PILHA E FILA

Pilha* CriaPilha (void)     CRIA A PILHA

No* ins_ini (No* t, int a)  AUXILIAR DA INSERÇÃO
void push (Pilha* p, int v) INSERÇÃO

No* ret_ini (No* l)         AUXILIAR DA REMOÇÃO
int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

void LiberaPilha (Pilha* p)      LIBERA A PILHA

void ImprimePilha (Pilha* p)     IMPRIMA A PILHA

int VaziaPilha(Pilha *p)	    VERIFICA SE A PILHA ESTÁ VAZIA

Fila* CriaFila ()
void InsereFila (Fila* f, int v)
int RetiraFila (Fila* f)
Fila* LiberaFila (Fila* f)
void ImprimeFila (Fila* f)
*/

typedef struct nos
{
    int info;
    struct nos *prox;
}No;

typedef struct fila
{
    No * ini;
    No * fim;
} Fila;


typedef struct pilha
{
   No *prim;
}Pilha;

Pilha* CriaPilha (void)
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->prim = NULL;
   return p;
};

No* ins_ini (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
};

void push (Pilha* p, int v)
{
    p->prim = ins_ini(p->prim,v);
};

No* ret_ini (No* l)
{
    No* p = l->prox;
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

Pilha * LiberaPilha (Pilha* p)
{
    No* q = p->prim;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return(NULL);
};

void ImprimePilha (Pilha* p)
{
    No* q;
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

int VaziaPilha(Pilha *p)
{
    if (!p->prim)
    {
        return 1; //pilha vazia
    }
    return 0;
}


int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}



Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim (No* fim, int A)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int v)
{
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

No* retira_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

int RetiraFila (Fila* f)
{
    int v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void ImprimeFila (Fila* f)
{
    No* q;
    printf("\n");
    for (q=f->ini; q!=NULL; q=q->prox)
    printf("%d - ",q->info);
}


Fila* LiberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

#endif // PILHA_FILA_H_INCLUDED
