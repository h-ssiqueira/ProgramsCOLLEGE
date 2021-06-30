#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/* FUNÇÕES DE MANIPULAÇÃO DE FILA

Fila* CriaFila ()
void InsereFila (Fila* f, int v)
int RetiraFila (Fila* f)
Fila* liberaFila (Fila* f)
void imprimeFila (Fila* f)
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

No* ret_ini (No* ini)
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
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void imprimeFila (Fila* f)
{
    No* q;
    printf("\n");
    for (q=f->ini; q!=NULL; q=q->prox)
    printf("%d - ",q->info);
}


Fila* liberaFila (Fila* f)
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

#endif // FILA_H_INCLUDED
