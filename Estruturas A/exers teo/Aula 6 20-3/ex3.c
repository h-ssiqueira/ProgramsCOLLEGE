#include<stdio.h>
#include<stdlib.h>
#include"PILHA_FILA.h"

void separa(Fila *f);

int main(){
    Fila *f = CriaFila();
    int i = 0;
    while(i!=-1){
        printf("\n\tInsira um valor para a fila: ");
        scanf("%d",&i);
        if(i!=-1)
            InsereFila(f,i);
    }
    system("clear");
    separa(f);
    LiberaFila(f);    
    return 0;
}

void separa(Fila *f){
    Fila *par = CriaFila(),*impar = CriaFila();
    int n;
    while(!VaziaFila(f)){
        n = RetiraFila(f);
        n%2 == 0 ? InsereFila(par,n) : InsereFila(impar,n);        
    }    
    ImprimeFila(par);
    ImprimeFila(impar);
    LiberaFila(impar);    
    LiberaFila(par);    
}
