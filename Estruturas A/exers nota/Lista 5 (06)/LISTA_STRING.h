#ifndef LISTA_STRING_h_INCLUDED
#define LISTA_STRING_h_INCLUDED

/*
    Insere_LS - Insere no inicio da lista
    Vazia_LS - Retorna 1 caso a lista esteja vazia, caso contrario, 0
    Imprime_LS - Imprime todas as strinfs contidas na lista
    Retira_LS - Retira parte da lista a partir da posiçao fornecida pelo usuario
    Desaloca_LS - Libera a memoria dos elementos previamente alocados na lista
 */

typedef struct listast{
    char string[50];
    struct listast *prox;
}Lista_String;

Lista_String* Cria_LS(){
    return NULL;
}

void Insere_LS(Lista_String **recebida, char string[]){
    Lista_String *novo = (Lista_String *)malloc(sizeof(Lista_String));
    strcpy(novo->string,string);
    novo->prox = *recebida;
    *recebida = novo;
}
int Vazia_LS(Lista_String *recebida){
    if(recebida == NULL)
        return 1;
    return 0;
}

void Imprime_LS(Lista_String *recebida){
    printf("\n\tLista:");
    for(Lista_String *aux = recebida; aux != NULL; aux = aux->prox){
        printf("\n\t%s",aux->string);
    }
}

 Lista_String * Busca_LS(Lista_String *recebida,char alvo[]){
    Lista_String *aux = recebida;
    int conf;
    
    while(aux != NULL){
        conf = strcmp(aux->string,alvo);
        if(conf == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

void Retira_LS(Lista_String **recebida, int pos){
    Lista_String *aux = (*recebida), *aux2 = Cria_LS();
    
    for(int count = 1; aux != NULL; aux2 = aux, aux = aux->prox, count++){
        if(count == pos){
            if(count == 1) 
                (*recebida) = (*recebida)->prox;
            else
                aux2->prox = aux->prox;
            free(aux);
            break;
        }
    }
}

void Desaloca_LS(Lista_String *Recebida){
    Lista_String *aux = Recebida, *aux2;
    
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
}

#endif
