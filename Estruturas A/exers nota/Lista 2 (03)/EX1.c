//Henrique Sartori Siqueira    RA:19240472
//Rafael Silva Barbon          RA:19243633
#include <stdio.h>
#include <stdlib.h>
#include "PILHA_FILA.h"
/*Construir um programa que receba duas filas: Q1 e Q2, contendo números inteiros.
Em seguida, construir uma função que gere uma terceira fila Q3 juntando as filas Q1 e Q2 (não
é necessário validar valores repetidos). No final imprimir as filas Q1, Q2 e Q3.
*/
void junta(Fila *Q1,Fila *Q2,Fila **Q3)
{
    int info;
    No *aux=Q1->ini;  
    while(aux!=NULL)
    {
        InsereFila(*Q3,aux->info);
        aux=aux->prox;
    }
    aux=Q2->ini;
    while(aux!=NULL)
    {
        InsereFila(*Q3,aux->info);
        aux=aux->prox;
    }
}
    
int main()
{
    Fila *Q1=CriaFila(),*Q2=CriaFila(),*Q3=CriaFila();
    int info;
    do{
        printf("\nInsira elementos na Fila Q1 (-999 para sair):");
        scanf("%d",&info);
        if(info!=-999)
            InsereFila(Q1,info);
    }while(info!=-999);
    system("clear");
    do{
        printf("\nInsira elementos na Fila Q2 (-999 para sair):");
        scanf("%d",&info);
        if(info!=-999)
            InsereFila(Q2,info);
    }while(info!=-999);
    
    junta(Q1,Q2,&Q3);
    
    system("clear");
    printf("Fila Q1:");
    imprimeFila(Q1);
    printf("\n\nFila Q2:");
    imprimeFila(Q2);
    printf("\n\nFila Q3:");
    imprimeFila(Q3);
    printf("\n");
    return 0;
}
