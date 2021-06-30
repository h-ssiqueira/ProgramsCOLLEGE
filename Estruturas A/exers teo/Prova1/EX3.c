//1)

typedef struct listaDE{
    int valor;
    struct listaDE *ant, *prox;
}ListaDE;

//2)

void Imprime_ListaDE(ListaDE *L){
    if(L != NULL){ //conferencia de lista vazia
        ListaDE *aux;
        
        for(aux = L; aux->prox != NULL; aux=aux->prox) //encerra o loop no ultimo elemento da lista
            continue; //continua no loop ate sair do mesmo
            
        printf("\n\tLista duplamente encadeada do fim ao inicio: ");
        
        for(;aux != NULL; aux = aux->ant) //começa do ultimo e termina em null
            printf("\n%d",aux->valor);
        printf("\n");
    }
    else
        printf("\n\tLista vazia.");
}
