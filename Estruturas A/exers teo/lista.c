///1

Pilha* CRIA(void);
void push(Pilha* p, float v)
float pop(Pilha* p)

int main(){
    Pilha *um, *dois;float a;
    um=CRIA();dois=CRIA();
    
    push(um,1) //1
    push(dois,3) //3
    push(um,4) //4 1
    push(dois,5) // 5 3
    push(um,6) // 6 4 1
    push(dois,7) // 7 5 3
    a=pop(dois) //7
    push(dois,pop(um))// 6 5 3
    a=pop(dois)// 6
    push(dois,pop(dois)) //5 3
    push(dois,pop(um)) //4 5 3
    push(dois,pop(dois)) //4 5 3
    push(um,pop(um))//1
    push(um,pop(dois))//4 1
}

///2

int main(){
    Pilha *um,*dois;int a;
    Fila *F1,F2
    um = CriaPilha();dois=CriaPilha();
    F1=CriaFila();F2=CriaFila();

    push(um,1) //1
    push(dois,3) //3
    push(um,4) //4 1
    push(dois,5) //5 3
    push(um,6) // 6 4 1
    push(dois,7)// 7 5 3
    insereFila(F1,4) // 4
    insereFila(F1,6) // 4 6
    insereFila(F1,9) // 4 6 9
    insereFila(F1,14) // 4 6 9 14
    insereFila(F2,16) //16
    insereFila(F2,19) //16 19
    insereFila(F2,41) // 16 19 41
    insereFila(F2,12) // 16 19 41 12
    insereFila(F2,pop(um)) //16 19 41 12 6
    insereFila(F1,retiraFila(F2)) //4 6 9 14 16
    push(dois,retiraFila(F2)) //19 7 5 3
    push(dois,retiraFila(F1)) //4 19 7 5 3
    push(um,pop(dois)) //4 4 1
    insereFila(F1,retiraFila(F2)); //6 9 14 16 19
}

///3

void apaga15(Pilha *p){
    Pilha *aux = CRIA();
    int i = 1, v;
    
    while(!Vazia(p)){
        v = pop(p);
        if(i != 15)
            push(aux,v)
        i++;
    }
    
    while(!Vazia(aux))
        push(p,pop(aux));
    
    Imprime(p);
    
    aux = Libera(aux);
}

///4

void elem_iguais(Pilha *p1, Pilha *p2){
    Pilha *aux1 = CRIA(), *aux2 = CRIA();
    int a,b,i = 0;

    a = pop(p1);
    b = pop(p2);
    if(Vazia(p1)||Vazia(p2))
        printf("\n\tPilha com apenas 1 elemento");
    while(!Vazia(p1)&&!Vazia(p2)){
        if(a == b){
            i++;
            push(aux1,a);
            push(aux2,b);
            a = pop(p1);
            b = pop(p2);
        }
        else if(a < b){
            push(aux1,a);
            a = pop(p1);
        }
        else{
            push(aux2,b);
            b = pop(p2);
        }
    }
    if(!Vazia(p1))
        push(aux1,pop(p1));
    else if(!Vazia(p2))
        push(aux2,pop(p2));
    while(!Vazia(aux1))
        push(p1,pop(aux1));
    while(!Vazia(aux2))
        push(p2,pop(aux2));
    printf("\n\tExistem %d elementos diferentes entre as pilhas",i);
    Imprime(p1);
    Imprime(p2);
    
    aux1 = Libera(aux1);
    aux2 = Libera(aux2);
}

///5

Fila* sem_repetir(Fila *F1, Fila *F2){
	Fila *F3 = Cria(),*aux = Cria();
	int v1,v2,conf = 0;
	
	if(Vazia(F1)&&Vazia(F2)){
		printf("Filas vazias");
	else if(Vazia(F1)){
		while(!Vazia(F2))
			Insere(F3,Retira(F2));
	}
	else if(Vazia(F2)){
		while(!Vazia(F1))
			Insere(F3,Retira(F1));
	}else{
		while(!Vazia(F1)){
			v1 = Retira(F1);
			while(!Vazia(F2)){
				v2 = Retira(F2);
				if(v1 == v2)
					conf++;
				Insere(aux,v2);
			}
			while(!Vazia(aux))
				Insere(F2,Retira(aux));
			if(conf == 0)
				Insere(F3,v1);
			else 
				conf = 0;
		}
		while(!Vazia(F2))
			Insere(F3,Retira(F2));
	}
	
	Imprime(F3);
	
	aux = Libera(aux);
	return F3;
}

///6

Fila* inverte(Fila *F1){
	Pilha *p = Cria();
	
	while(!Vaziaf(F1))
		push(p,Retira(F1));
	while(!Vaziap(p))
		Insere(F1,pop(p));
	
	p = Libera(p);
	return F1;
}

///7 ERROR 404

///8

Lista* duplicar(Lista *L){
	Lista *copia = Cria(),*aux;
	for(aux = L; aux != NULL ; aux = aux->prox){
		Insere(&copia,aux->valor);
	}
	return copia;
}

///9

void concatenar(Lista *L1, Lista *L2){
	Lista *aux = L1;
	for(;aux->prox != NULL; aux = aux->prox)
		continue;
	aux->prox = L2;
}

///10
void Insere_final(Lista *L, int v){
	Lista *aux, *novo = (Lista*)malloc(sizeof(Lista));
	novo->valor = v;
	novo->prox = NULL;
	for(aux = L; aux->prox != NULL; aux = aux->prox) continue;
	aux->prox = novo;
}