/*
Biblioteca para os quatro tipos de estruturas de dados juntamente com os 4 tipos de variaveis.

Sendo os tipos de dados: int, float, char e double.

Sendo os tipos de estruturas: pilha, fila, lista (encadeada, duplamente encadeada e circular) e arvore(int).

O sufixo apresentado em cada funçao representa o tipo de dado utilizado, sendo i para inteiro, f para float, c para char e d para double.
Para as listas o sufixo tambem inclui o tipo da lista.

*/

//Nos para fila e pilha com os 4 tipos de dados
typedef struct noi{
    int valor;
    struct noi *prox;
}Noi;

typedef struct nof{
    float valor;
    struct nof *prox;
}Nof;

typedef struct noc{
    char valor;
    struct noc *prox;
}Noc;

typedef struct nod{
    double valor;
    struct nod *prox;
}Nod;


//                               ************
//                               *  Pilhas  *
//                               ************
typedef struct pilhai{
    Noi *no;
}Pilhai;

typedef struct pilhaf{
    Nof *no;
}Pilhaf;

typedef struct pilhac{
    Noc *no;
}Pilhac;

typedef struct pilhad{
    Nod *no;
}Pilhad;

//Criar pilhas
Pilhai* CriaPi(){
    Pilhai *p = (Pilhai*)malloc(sizeof(Pilhai));
    p->no = NULL;
    return p;
}

Pilhaf* CriaPf(){
    Pilhaf *p = (Pilhaf*)malloc(sizeof(Pilhaf));
    p->no = NULL;
    return p;
}

Pilhac* CriaPc(){
    Pilhac *p = (Pilhac*)malloc(sizeof(Pilhac));
    p->no = NULL;
    return p;
}

Pilhad* CriaPd(){
    Pilhad *p = (Pilhad*)malloc(sizeof(Pilhad));
    p->no = NULL;
    return p;
}

//Verificaçao se esta vazia
int VaziaPi(Pilhai *p){
    if(p->no == NULL)
        return 1;
    return 0;
}

int VaziaPf(Pilhaf *p){
    if(p->no == NULL)
        return 1;
    return 0;
}

int VaziaPc(Pilhac *p){
    if(p->no == NULL)
        return 1;
    return 0;
}

int VaziaPd(Pilhad *p){
    if(p->no == NULL)
        return 1;
    return 0;
}

//Push para as pilhas
Noi* InsertPi(Noi *n, int v){
    Noi *novo = (Noi*)malloc(sizeof(Noi));
    novo->valor = v;
    novo->prox = n;
    return novo;
}

void Pushi(Pilhai *p, int v){
    p->no = InsertPi(p->no,v);
}

Nof* InsertPf(Nof *n, float v){
    Nof *novo = (Nof*)malloc(sizeof(Nof));
    novo->valor = v;
    novo->prox = n;
    return novo;
}

void Pushf(Pilhaf *p, float v){
    p->no = InsertPf(p->no,v);
}

Noc* InsertPc(Noc *n, char v){
    Noc *novo = (Noc*)malloc(sizeof(Noc));
    novo->valor = v;
    novo->prox = n;
    return novo;
}

void Pushc(Pilhac *p, char v){
    p->no = InsertPc(p->no,v);
}

Nod* InsertPd(Nod *n, double v){
    Nod *novo = (Nod*)malloc(sizeof(Nod));
    novo->valor = v;
    novo->prox = n;
    return novo;
}

void Pushd(Pilhad *p, double v){
    p->no = InsertPd(p->no,v);
}

//Pop para as pilhas
Noi* RemovePi(Noi *n){
    Noi *nn = n->prox;
    free(n);
    return nn;
}

int Popi(Pilhai *p){
    if(VaziaPi(p)){
        printf("\nPilha vazia.");
        exit(1);
    }
    int v = p->no->valor;
    p->no = RemovePi(p->no);    
    return v;
}

Nof* RemovePf(Nof *n){
    Nof *nn = n->prox;
    free(n);
    return nn;
}

float Popf(Pilhaf *p){
    if(VaziaPf(p)){
        printf("\nPilha vazia.");
        exit(1);
    }
    float v = p->no->valor;
    p->no = RemovePf(p->no);    
    return v;
}

Noc* RemovePc(Noc *n){
    Noc *nn = n->prox;
    free(n);
    return nn;
}

char Popc(Pilhac *p){
    if(VaziaPc(p)){
        printf("\nPilha vazia.");
        exit(1);
    }
    char v = p->no->valor;
    p->no = RemovePc(p->no);    
    return v;
}

Nod* RemovePd(Nod *n){
    Nod *nn = n->prox;
    free(n);
    return nn;
}

double Popd(Pilhad *p){
    if(VaziaPd(p)){
        printf("\nPilha vazia.");
        exit(1);
    }
    double v = p->no->valor;
    p->no = RemovePd(p->no);    
    return v;
}

//Impressao das pilhas
void ImprimePi(Pilhai *p){
    if(VaziaPi(p))
        printf("\nPilha Vazia.");
    else
        for(Noi *aux = p->no; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

void ImprimePf(Pilhaf *p){
    if(VaziaPf(p))
        printf("\nPilha Vazia.");
    else
        for(Nof *aux = p->no; aux != NULL; aux = aux->prox)
            printf("\n%f",aux->valor);
}

void ImprimePc(Pilhac *p){
    if(VaziaPc(p))
        printf("\nPilha Vazia.");
    else
        for(Noc *aux = p->no; aux != NULL; aux = aux->prox)
            printf("\n%c",aux->valor);
}

void ImprimePd(Pilhad *p){
    if(VaziaPd(p))
        printf("\nPilha Vazia.");
    else
        for(Nod *aux = p->no; aux != NULL; aux = aux->prox)
            printf("\n%lf",aux->valor);
}

//Tamanho da pilha
int TamanhoPi(Pilhai *p){
    int i = 0;
    for(Noi *aux = p->no; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoPf(Pilhaf *p){
    int i = 0;
    for(Nof *aux = p->no; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoPc(Pilhac *p){
    int i = 0;
    for(Noc *aux = p->no; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoPd(Pilhad *p){
    int i = 0;
    for(Nod *aux = p->no; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

//Inverte pilha
Pilhai* InvertePi(Pilhai *p){
    Pilhai *aux = CriaPi();
    while(!VaziaPi(p))
        Pushi(aux,Popi(p));
    return aux;
}

Pilhaf* InvertePf(Pilhaf *p){
    Pilhaf *aux = CriaPf();
    while(!VaziaPf(p))
        Pushf(aux,Popf(p));
    return aux;
}

Pilhac* InvertePc(Pilhac *p){
    Pilhac *aux = CriaPc();
    while(!VaziaPc(p))
        Pushc(aux,Popc(p));
    return aux;
}

Pilhad* InvertePd(Pilhad *p){
    Pilhad *aux = CriaPd();
    while(!VaziaPd(p))
        Pushd(aux,Popd(p));
    return aux;
} 

//Desalocamento de memoria das pilhas
void LiberaPi(Pilhai **p){
    Noi *aux = ((*p)->no), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*p);
    (*p) = NULL;
}

void LiberaPf(Pilhaf **p){
    Nof *aux = ((*p)->no), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*p);
    (*p) = NULL;
}

void LiberaPc(Pilhac **p){
    Noc *aux = ((*p)->no), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*p);
    (*p) = NULL;
}

void LiberaPd(Pilhad **p){
    Nod *aux = ((*p)->no), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*p);
    (*p) = NULL;
}


//                               ***********
//                               *  Filas  *
//                               ***********
typedef struct filai{
    Noi *ini;
    Noi *fim;
}Filai;

typedef struct filaf{
    Nof *ini;
    Nof *fim;
}Filaf;

typedef struct filac{
    Noc *ini;
    Noc *fim;
}Filac;

typedef struct filad{
    Nod *ini;
    Nod *fim;
}Filad;

//Cria as filas
Filai* CriaFi(){
    Filai *f = (Filai*)malloc(sizeof(Filai));
    f->ini = f->fim = NULL;
    return f;
}

Filaf* CriaFf(){
    Filaf *f = (Filaf*)malloc(sizeof(Filaf));
    f->ini = f->fim = NULL;
    return f;
}

Filac* CriaFc(){
    Filac *f = (Filac*)malloc(sizeof(Filac));
    f->ini = f->fim = NULL;
    return f;
}

Filad* CriaFd(){
    Filad *f = (Filad*)malloc(sizeof(Filad));
    f->ini = f->fim = NULL;
    return f;
}

//Verificaçao se esta vazia
int VaziaFi(Filai *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

int VaziaFf(Filaf *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

int VaziaFc(Filac *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

int VaziaFd(Filad *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

//Inserir na fila
Noi *InsertFi(Noi *n, int v){
    Noi *novo = (Noi*)malloc(sizeof(Noi));
    novo->valor = v;
    novo->prox = NULL;
    if(n != NULL)
        n->prox = novo;
    return novo;
}

void InsereFi(Filai *f, int v){
    f->fim = InsertFi(f->fim,v);
    if(f->ini == NULL)
        f->ini = f->fim;
}

Nof *InsertFf(Nof *n, float v){
    Nof *novo = (Nof*)malloc(sizeof(Nof));
    novo->valor = v;
    novo->prox = NULL;
    if(n != NULL)
        n->prox = novo;
    return novo;
}

void InsereFf(Filaf *f, float v){
    f->fim = InsertFf(f->fim,v);
    if(f->ini == NULL)
        f->ini = f->fim;
}

Noc *InsertFc(Noc *n, char v){
    Noc *novo = (Noc*)malloc(sizeof(Noc));
    novo->valor = v;
    novo->prox = NULL;
    if(n != NULL)
        n->prox = novo;
    return novo;
}

void InsereFc(Filac *f, char v){
    f->fim = InsertFc(f->fim,v);
    if(f->ini == NULL)
        f->ini = f->fim;
}

Nod *InsertFd(Nod *n, double v){
    Nod *novo = (Nod*)malloc(sizeof(Nod));
    novo->valor = v;
    novo->prox = NULL;
    if(n != NULL)
        n->prox = novo;
    return novo;
}

void InsereFd(Filad *f, double v){
    f->fim = InsertFd(f->fim,v);
    if(f->ini == NULL)
        f->ini = f->fim;
}

//Remover da fila
Noi* RemoveFi(Noi* n){
    Noi *aux = n->prox;
    free(n);
    return aux;
}

int RemoveFilai(Filai *f){
    if(VaziaFi(f)){
        printf("\nFila vazia");
        exit(1);
    }
    int v = f->ini->valor;
    f->ini = RemoveFi(f->ini);
    if(f->ini == NULL)
        f->fim = NULL;
    return v;
}

Nof* RemoveFf(Nof* n){
    Nof *aux = n->prox;
    free(n);
    return aux;
}

float RemoveFilaf(Filaf *f){
    if(VaziaFf(f)){
        printf("\nFila vazia");
        exit(1);
    }
    float v = f->ini->valor;
    f->ini = RemoveFf(f->ini);
    if(f->ini == NULL)
        f->fim = NULL;
    return v;
}

Noc* RemoveFc(Noc* n){
    Noc *aux = n->prox;
    free(n);
    return aux;
}

char RemoveFilac(Filac *f){
    if(VaziaFc(f)){
        printf("\nFila vazia");
        exit(1);
    }
    char v = f->ini->valor;
    f->ini = RemoveFc(f->ini);
    if(f->ini == NULL)
        f->fim = NULL;
    return v;
}

Nod* RemoveFd(Nod* n){
    Nod *aux = n->prox;
    free(n);
    return aux;
}

double RemoveFilad(Filad *f){
    if(VaziaFd(f)){
        printf("\nFila vazia");
        exit(1);
    }
    double v = f->ini->valor;
    f->ini = RemoveFd(f->ini);
    if(f->ini == NULL)
        f->fim = NULL;
    return v;
}

//Imprime filas
void ImprimeFi(Filai *f){
    if(VaziaFi(f))
        printf("\nFila vazia.");
    else
        for(Noi *aux = f->ini; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

void ImprimeFf(Filaf *f){
    if(VaziaFf(f))
        printf("\nFila vazia.");
    else
        for(Nof *aux = f->ini; aux != NULL; aux = aux->prox)
            printf("\n%f",aux->valor);
}

void ImprimeFc(Filac *f){
    if(VaziaFc(f))
        printf("\nFila vazia.");
    else
        for(Noc *aux = f->ini; aux != NULL; aux = aux->prox)
            printf("\n%c",aux->valor);
}

void ImprimeFd(Filad *f){
    if(VaziaFd(f))
        printf("\nFila vazia.");
    else
        for(Nod *aux = f->ini; aux != NULL; aux = aux->prox)
            printf("\n%lf",aux->valor);
}

//Tamanho da fila
int TamanhoFi(Filai *f){
    int i = 0;
    for(Noi *aux = f->ini; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoFf(Filaf *f){
    int i = 0;
    for(Nof *aux = f->ini; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoFc(Filac *f){
    int i = 0;
    for(Noc *aux = f->ini; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

int TamanhoFd(Filad *f){
    int i = 0;
    for(Nod *aux = f->ini; aux != NULL; aux = aux->prox)
        i++;
    return i;
}

//Libera filas
void LiberaFi(Filai **f){
    Noi *aux = ((*f)->ini), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    (*f) = NULL;
}

void LiberaFf(Filaf **f){
    Nof *aux = ((*f)->ini), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    (*f) = NULL;
}

void LiberaFc(Filac **f){
    Noc *aux = ((*f)->ini), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    (*f) = NULL;
}

void LiberaFd(Filad **f){
    Nod *aux = ((*f)->ini), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    (*f) = NULL;
}

//Inverte filas
Filai* InverteFi(Filai *f){
    Filai *aux = CriaFi();
    Pilhai *p = CriaPi();
    while(!VaziaFi(f))
        Pushi(p,RemoveFilai(f));        
    while(!VaziaPi(p))
        InsereFi(aux,Popi(p));
    LiberaFi(&f);
    LiberaPi(&p);
    return aux;
}

Filaf* InverteFf(Filaf *f){
    Filaf *aux = CriaFf();
    Pilhaf *p = CriaPf();
    while(!VaziaFf(f))
        Pushf(p,RemoveFilaf(f));        
    while(!VaziaPf(p))
        InsereFf(aux,Popf(p));
    LiberaFf(&f);
    LiberaPf(&p);
    return aux;
}

Filac* InverteFc(Filac *f){
    Filac *aux = CriaFc();
    Pilhac *p = CriaPc();
    while(!VaziaFc(f))
        Pushc(p,RemoveFilac(f));        
    while(!VaziaPc(p))
        InsereFc(aux,Popc(p));
    LiberaFc(&f);
    LiberaPc(&p);
    return aux;
}

Filad* InverteFd(Filad *f){
    Filad *aux = CriaFd();
    Pilhad *p = CriaPd();
    while(!VaziaFd(f))
        Pushd(p,RemoveFilad(f));        
    while(!VaziaPd(p))
        InsereFd(aux,Popd(p));
    LiberaFd(&f);
    LiberaPd(&p);
    return aux;
}


//                        *******************************
//                        *  Listas encadeadas simples  *
//                        *******************************
typedef struct listaei{
    int valor;
    struct listaei *prox;
}ListaEi;

typedef struct listaef{
    float valor;
    struct listaef *prox;
}ListaEf;

typedef struct listaec{
    char valor;
    struct listaec *prox;
}ListaEc;

typedef struct listaed{
    double valor;
    struct listaed *prox;
}ListaEd;

//Criar lista encadeada
ListaEi* CriaLEi(){
    return NULL;
}

ListaEf* CriaLEf(){
    return NULL;
}

ListaEc* CriaLEc(){
    return NULL;
}

ListaEd* CriaLEd(){
    return NULL;
}

//Conferencia de vazia
int VaziaLEi(ListaEi *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLEf(ListaEf *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLEc(ListaEc *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLEd(ListaEd *l){
    if(l == NULL)
        return 1;
    return 0;
}

//Inserçao de elementos no inicio das listas
void InsereLEi(ListaEi **l, int v){
    ListaEi *novo = (ListaEi*)malloc(sizeof(ListaEi));
    novo->valor = v;
    novo->prox = (*l);
    (*l) = novo;
}

void InsereLEf(ListaEf **l, float v){
    ListaEf *novo = (ListaEf*)malloc(sizeof(ListaEf));
    novo->valor = v;
    novo->prox = (*l);
    (*l) = novo;
}

void InsereLEc(ListaEc **l, char v){
    ListaEc *novo = (ListaEc*)malloc(sizeof(ListaEc));
    novo->valor = v;
    novo->prox = (*l);
    (*l) = novo;
}

void InsereLEd(ListaEd **l, double v){
    ListaEd *novo = (ListaEd*)malloc(sizeof(ListaEd));
    novo->valor = v;
    novo->prox = (*l);
    (*l) = novo;
}

//Retirar elemento da lista a partir da posiçao fornecida
void RetiraLEi(ListaEi **l,int v){
    ListaEi *aux, *aux2;
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

void RetiraLEf(ListaEf **l,int v){
    ListaEf *aux, *aux2;
    int i;
    for(i = 0, aux = (*l), aux2 = NULL; aux != NULL; aux2 = aux, aux = aux->prox, i++){
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

void RetiraLEc(ListaEc **l,int v){
    ListaEc *aux, *aux2;
    int i;
    for(i = 0, aux = (*l), aux2 = NULL; aux != NULL; aux2 = aux, aux = aux->prox, i++){
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

void RetiraLEd(ListaEd **l,int v){
    ListaEd *aux, *aux2;
    int i;
    for(i = 0, aux = (*l), aux2 = NULL; aux != NULL; aux2 = aux, aux = aux->prox, i++){
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

//Busca se o dado existe na lista e retorna a posiçao deste
int BuscaLEi(ListaEi *l, int v){
    ListaEi *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox)
        if(aux->valor == v)
            return i;
    return -1;
}

int BuscaLEf(ListaEf *l, float v){
    ListaEf *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox)
        if(aux->valor == v)
            return i;
    return -1;
}

int BuscaLEc(ListaEc *l, char v){
    ListaEc *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox)
        if(aux->valor == v)
            return i;
    return -1;
}

int BuscaLEd(ListaEd *l, double v){
    ListaEd *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox)
        if(aux->valor == v)
            return i;
    return -1;
}

//Impressao das listas
void ImprimeLEi(ListaEi *l){
    if(VaziaLEi(l))
        printf("\nLista vazia.");
    else
        for(ListaEi *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

void ImprimeLEf(ListaEf *l){
    if(VaziaLEf(l))
        printf("\nLista vazia.");
    else
        for(ListaEf *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%f",aux->valor);
}

void ImprimeLEc(ListaEc *l){
    if(VaziaLEc(l))
        printf("\nLista vazia.");
    else
        for(ListaEc *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%c",aux->valor);
}

void ImprimeLEd(ListaEd *l){
    if(VaziaLEd(l))
        printf("\nLista vazia.");
    else
        for(ListaEd *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%lf",aux->valor);
}

//Desalocamento das listas
void LiberaLEi(ListaEi **l){
    ListaEi *aux = (*l), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}

void LiberaLEf(ListaEf **l){
    ListaEf *aux = (*l), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}

void LiberaLEc(ListaEc **l){
    ListaEc *aux = (*l), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}

void LiberaLEd(ListaEd **l){
    ListaEd *aux = (*l), *aux2;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    (*l) = NULL;
}


//                       **********************************
//                       *  Listas duplamente encadeadas  *
//                       **********************************
typedef struct listadei{
    int valor;
    struct listadei *ant, *prox;
}ListaDEi;

typedef struct listadef{
    float valor;
    struct listadef *ant, *prox;
}ListaDEf;

typedef struct listadec{
    char valor;
    struct listadec *ant, *prox;
}ListaDEc;

typedef struct listaded{
    double valor;
    struct listaded *ant, *prox;
}ListaDEd;

//Criar lista duplamente encadeada
ListaDEi* CriaLDEi(){
    return NULL;
}

ListaDEf* CriaLDEf(){
    return NULL;
}

ListaDEc* CriaLDEc(){
    return NULL;
}

ListaDEd* CriaLDEd(){
    return NULL;
}

//Conferencia de vazia
int VaziaLDEi(ListaDEi *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLDEf(ListaDEf *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLDEc(ListaDEc *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLDEd(ListaDEd *l){
    if(l == NULL)
        return 1;
    return 0;
}

//Inserçao de elementos no inicio das listas
void InsereLDEi(ListaDEi **l, int v){
    ListaDEi *novo = (ListaDEi *)malloc(sizeof(ListaDEi));
    novo->valor = v;
    novo->prox = (*l);
    novo->ant = NULL;
    (*l)->ant = novo;
    (*l) = novo;
}

void InsereLDEf(ListaDEf **l, float v){
    ListaDEf *novo = (ListaDEf *)malloc(sizeof(ListaDEf));
    novo->valor = v;
    novo->prox = (*l);
    novo->ant = NULL;
    (*l)->ant = novo;
    (*l) = novo;
}

void InsereLDEc(ListaDEc **l, char v){
    ListaDEc *novo = (ListaDEc *)malloc(sizeof(ListaDEc));
    novo->valor = v;
    novo->prox = (*l);
    novo->ant = NULL;
    (*l)->ant = novo;
    (*l) = novo;
}

void InsereLDEd(ListaDEd **l, double v){
    ListaDEd *novo = (ListaDEd *)malloc(sizeof(ListaDEd));
    novo->valor = v;
    novo->prox = (*l);
    novo->ant = NULL;
    (*l)->ant = novo;
    (*l) = novo;
}

//Remoçao do elemento a partir da posiçao fornecida
void RetiraLDEi(ListaDEi **l, int v){
    ListaDEi *aux, *aux2;
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

void RetiraLDEf(ListaDEf **l, int v){
    ListaDEf *aux, *aux2;
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

void RetiraLDEc(ListaDEc **l, int v){
    ListaDEc *aux, *aux2;
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

void RetiraLDEd(ListaDEd **l, int v){
    ListaDEd *aux, *aux2;
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

//Busca se o elemento existe na lista e retorna a posiçao deste
int BuscaLDEi(ListaDEi *l, int v){
    ListaDEi *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLDEf(ListaDEf *l, float v){
    ListaDEf *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLDEc(ListaDEc *l, char v){
    ListaDEc *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLDEd(ListaDEd *l, double v){
    ListaDEd *aux;
    int i;
    for(i = 0, aux = l; aux != NULL; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

//Impressao das listas
void ImprimeLDEi(ListaDEi *l){
    if(VaziaLDEi(l))
        printf("\nLista vazia.");
    else
        for(ListaDEi *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%d",aux->valor);
}

void ImprimeLDEf(ListaDEf *l){
    if(VaziaLDEf(l))
        printf("\nLista vazia.");
    else
        for(ListaDEf *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%f",aux->valor);
}

void ImprimeLDEc(ListaDEc *l){
    if(VaziaLDEc(l))
        printf("\nLista vazia.");
    else
        for(ListaDEc *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%c",aux->valor);
}

void ImprimeLDEd(ListaDEd *l){
    if(VaziaLDEd(l))
        printf("\nLista vazia.");
    else
        for(ListaDEd *aux = l; aux != NULL; aux = aux->prox)
            printf("\n%lf",aux->valor);
}

//Desaloca listas
void LiberaLDEi(ListaDEi **l){
    ListaDEi *aux = (*l), *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }    
    (*l) = NULL;
}

void LiberaLDEf(ListaDEf **l){
    ListaDEf *aux = (*l), *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }    
    (*l) = NULL;
}

void LiberaLDEc(ListaDEc **l){
    ListaDEc *aux = (*l), *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }    
    (*l) = NULL;
}

void LiberaLDEd(ListaDEd **l){
    ListaDEd *aux = (*l), *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }    
    (*l) = NULL;
}


//                             ***********************
//                             *  Listas circulares  *
//                             ***********************
typedef struct listaci{
    int valor;
    struct listaci *prox;
}ListaCi;

typedef struct listacf{
    float valor;
    struct listacf *prox;
}ListaCf;

typedef struct listacc{
    char valor;
    struct listacc *prox;
}ListaCc;

typedef struct listacd{
    double valor;
    struct listacd *prox;
}ListaCd;

//Criar listas circulares
ListaCi* CriaLCi(){
    return NULL;
}

ListaCf* CriaLCf(){
    return NULL;
}

ListaCc* CriaLCc(){
    return NULL;
}

ListaCd* CriaLCd(){
    return NULL;
}

//Conferencia de vazia
int VaziaLCi(ListaCi *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLCf(ListaCf *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLCc(ListaCc *l){
    if(l == NULL)
        return 1;
    return 0;
}

int VaziaLCd(ListaCd *l){
    if(l == NULL)
        return 1;
    return 0;
}

//Inserçao de elementos no inicio das listas
void InsereLCi(ListaCi **l, int v){
    ListaCi *novo = (ListaCi *)malloc(sizeof(ListaCi));
    novo->valor = v;
    novo->prox = (*l);
    if((*l)->prox != (*l)){
        ListaCi *aux;
        for(aux = (*l)->prox; aux->prox != (*l); aux = aux->prox)
            continue;
        aux->prox = novo;
    }
    else if((*l)->prox == (*l))
        (*l)->prox = novo;
    (*l) = novo;
}

void InsereLCf(ListaCf **l, float v){
    ListaCf *novo = (ListaCf *)malloc(sizeof(ListaCf));
    novo->valor = v;
    novo->prox = (*l);
    if((*l)->prox != (*l)){
        ListaCf *aux;
        for(aux = (*l)->prox; aux->prox != (*l); aux = aux->prox)
            continue;
        aux->prox = novo;
    }
    else if((*l)->prox == (*l))
        (*l)->prox = novo;
    (*l) = novo;
}

void InsereLCc(ListaCc **l, char v){
    ListaCc *novo = (ListaCc *)malloc(sizeof(ListaCc));
    novo->valor = v;
    novo->prox = (*l);
    if((*l)->prox != (*l)){
        ListaCc *aux;
        for(aux = (*l)->prox; aux->prox != (*l); aux = aux->prox)
            continue;
        aux->prox = novo;
    }
    else if((*l)->prox == (*l))
        (*l)->prox = novo;
    (*l) = novo;
}

void InsereLCd(ListaCd **l, double v){
    ListaCd *novo = (ListaCd *)malloc(sizeof(ListaCd));
    novo->valor = v;
    novo->prox = (*l);
    if((*l)->prox != (*l)){
        ListaCd *aux;
        for(aux = (*l)->prox; aux->prox != (*l); aux = aux->prox)
            continue;
        aux->prox = novo;
    }
    else if((*l)->prox == (*l))
        (*l)->prox = novo;
    (*l) = novo;
}

//Retirar elemento da lista a partir da posiçao fornecida
void RetiraLCi(ListaCi **l, int v){
    ListaCi *aux, *ant;
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

void RetiraLCf(ListaCf **l, int v){
    ListaCf *aux, *ant;
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

void RetiraLCc(ListaCc **l, int v){
    ListaCc *aux, *ant;
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

void RetiraLCd(ListaCd **l, int v){
    ListaCd *aux, *ant;
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

//Busca se o dado existe na lista e retorna a posiçao do mesmo
int BuscaLCi(ListaCi *l, int v){
    if(l->valor == v)
        return 1;
    ListaCi *aux, *ant;
    int i;
    for(i = 1, aux = l->prox; aux != l; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLCf(ListaCf *l, float v){
    if(l->valor == v)
        return 1;
    ListaCf *aux, *ant;
    int i;
    for(i = 1, aux = l->prox; aux != l; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLCc(ListaCc *l, char v){
    if(l->valor == v)
        return 1;
    ListaCc *aux, *ant;
    int i;
    for(i = 1, aux = l->prox; aux != l; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

int BuscaLCd(ListaCd *l, double v){
    if(l->valor == v)
        return 1;
    ListaCd *aux, *ant;
    int i;
    for(i = 1, aux = l->prox; aux != l; i++, aux = aux->prox){
        if(aux->valor == v)
            return i;
    }
    return -1;
}

//Impressao das listas
void ImprimeLCi(ListaCi *l){
    if(VaziaLCi(l))
        printf("\nLista vazia.");
    else
        printf("\n%d",l->valor);
        for(ListaCi *aux = l->prox; aux != l; aux = aux->prox)
            printf("\n%d",aux->valor);
}

void ImprimeLCf(ListaCf *l){
    if(VaziaLCf(l))
        printf("\nLista vazia.");
    else
        printf("\n%f",l->valor);
        for(ListaCf *aux = l->prox; aux != l; aux = aux->prox)
            printf("\n%f",aux->valor);
}

void ImprimeLCc(ListaCc *l){
    if(VaziaLCc(l))
        printf("\nLista vazia.");
    else
        printf("\n%c",l->valor);
        for(ListaCc *aux = l->prox; aux != l; aux = aux->prox)
            printf("\n%c",aux->valor);
}

void ImprimeLCd(ListaCd *l){
    if(VaziaLCd(l))
        printf("\nLista vazia.");
    else
        printf("\n%lf",l->valor);
        for(ListaCd *aux = l->prox; aux != l; aux = aux->prox)
            printf("\n%lf",aux->valor);
}

//Desalocamento das listas
void LiberaLCi(ListaCi **l){
    ListaCi *aux = (*l)->prox, *aux2;
    
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

void LiberaLCf(ListaCf **l){
    ListaCf *aux = (*l)->prox, *aux2;
    
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

void LiberaLCc(ListaCc **l){
    ListaCc *aux = (*l)->prox, *aux2;
    
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

void LiberaLCd(ListaCd **l){
    ListaCd *aux = (*l)->prox, *aux2;
    
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


//                                     *************
//                                     *  Arvores  *
//                                     *************
typedef struct arvore{
	int valor;
	struct arvore *dir;
	struct arvore *esq;
}Arv;

//Criar arvore
Arv* CriaA(){
	return NULL;
}

//Verificaçao vazia
bool VaziaA(Arv *A){
	if(A == NULL)
		return true;
	return false;
}

//Inserçao
void InsereA(Arv **A, int n){
	Arv *novo = (Arv*)malloc(sizeof(Arv)); 
	novo->valor = n; 
	novo->dir = NULL; 
	novo->esq = NULL; 
	if(VaziaA(*A)) //caso seja o primeiro elemento na arvore
		(*A) = novo;
	else{
        
		Arv *pai = (*A);
		bool flag = true;
		
		while(flag){
			if(pai->valor < n){ //se o valor inserido for menor que o pai
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

//Busca se o valor existe
bool BuscaA(Arv *A, int n){
    while(A != NULL){
        if(A->valor < n) //direciona para a direita caso o número seja maior que o valor da partição da árvore
            A = A->dir;
        else if(A->valor > n) //direciona para a esquerda caso o número seja menor que o valor da partição da árvore
            A = A->esq;
        else //caso não seja nem menor e nem maior o número é igual
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

//Retorna a quantidade de nos da arvore
int Nos(Arv *A){
    if(!A)
        return 0;
    return 1 + Nos(A->esq) + Nos(A->dir);
}

//Retorna o nivel(altura) da arvore
int Nivel(Arv *A){
    int aux, aux2;
    if(A->dir == NULL && A->esq == NULL)
        return 0;
    if(A->esq != NULL)
        aux = 1 + Nivel(A->esq);
    if(A->dir != NULL)
        aux2 = 1 + Nivel(A->dir);
    return aux > aux2 ? aux : aux2;
}

//Funçao auxiliar de remoçao (maior valor da esquerda)
Arv *MaEsq(Arv **Aesq){
    if((*Aesq)->dir != NULL) //percorre a arvore ate chegar no maior valor da esquerda (ultimo valor da direita)
        return MaEsq(&(*Aesq)->dir);
    else{
        Arv *aux = (*Aesq);
        if((*Aesq)->esq != NULL) //verifica se tem valor na esquerda
            (*Aesq) = (*Aesq)->esq; //se tiver atualiza para o da esquerda
        else
            (*Aesq) = NULL;
        return aux;
    }
}

//Funçao auxiliar de remoçao (menor valor da direita)
Arv *MeDir(Arv **Adir){
    if((*Adir)->esq != NULL) //percorre a arvore ate chegar no menor valor da direita (ultimo valor da esquerda)
        return MeDir(&(*Adir)->esq);
    else{
        Arv *aux = (*Adir);
        if((*Adir)->dir != NULL) //verifica se tem valor na direita
            (*Adir) = (*Adir)->dir; //se tiver atualiza para o da direita
        else
            (*Adir) = NULL;
        return aux;
    }
}

//Funçao que remove um no
void RemoveA(Arv **A,int n){
	if(*A){
        Arv *aux;
        if(n < (*A)->valor){ //se o valor for menor ele se dirige a esquerda
            aux = (*A)->esq; 
            if((aux->dir != NULL) || (aux->esq != NULL))//verifica se o prox da esquerda possui filhos
                RemoveA(&(*A)->esq,n);
            else{ 
                if(aux->valor == n){//se nao possuir ele confere se o valor eh igual e desaloca
                    free(aux);
                    aux = NULL;
                    (*A)->esq = NULL;
                }
            }
        }
        else if(n > (*A)->valor){//se o valor for maior ele se dirige a direita
            aux = (*A)->dir;
            if((aux->dir != NULL) || (aux->esq != NULL))//verifica se o prox da direita possui filhos
                RemoveA(&(*A)->dir,n);
            else{ 
                if(aux->valor == n){//se nao possuir ele confere se o valor eh igual e desaloca
                    free(aux);
                    aux = NULL;
                    (*A)->dir = NULL;
                }
            }
        }
        else{//caso o no que sera desalocado possua filhos
            aux = (*A);
            if((*A)->dir == NULL){//se possuir filho na esquerda
                (*A) = (*A)->esq;
                free(aux);
            }
            if((*A)->esq == NULL){//se possuir filho na direita
                (*A) = (*A)->dir;
                free(aux);
            }                
            else{//possui filhos
                aux = MaEsq(&(*A)->esq); //funçao que retorna o modulo que sera trocado (maior valor da esquerda com seu filho da direita se existir)
                //aux = MeDir(&(*A)->dir); //funçao que retorna o modulo que sera trocado (menor valor da direita com seu filho da esquerda se existir)
                aux->esq = (*A)->esq; //(*A)->esq contem o maior nº da subarvore esquerda ou NULL    
                aux->dir = (*A)->dir; //anexa o da direita fazendo o ramo da arvore "cair"
                free(*A);  
                (*A) = aux;
            }
        }
    }
}

//Impressao pre order
void ImpressaoPre(Arv *A){
	printf("%d ",A->valor);
	if(A->esq != NULL)
		ImpressaoPre(A->esq);
	if(A->dir != NULL)
		ImpressaoPre(A->dir);
}

//Impressao in order
void ImpressaoIn(Arv *A){
	if(A->esq != NULL)
		ImpressaoIn(A->esq);
	printf("%d ",A->valor);
	if(A->dir != NULL)
		ImpressaoIn(A->dir);
}

//Impressao pos order
void ImpressaoPos(Arv *A){
	if(A->esq != NULL)
		ImpressaoPos(A->esq);
	if(A->dir != NULL)
		ImpressaoPos(A->dir);
	printf("%d ",A->valor);
}

//Desaloca arvore
Arv* LiberaA(Arv *A){
	if(A->dir != NULL)//verifica se há informações na direita
		LiberaA(A->dir);
	if(A->esq != NULL)//verifica se há informações na esquerda
		LiberaA(A->esq);
	free(A);//chega em uma folha e libera a informação
	return NULL;
}

