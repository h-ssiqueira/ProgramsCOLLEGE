//Henrique Sartori Siqueira    RA:19240472
//Rafael Silva Barbon          RA:19243633
#include <stdio.h>
#include <stdlib.h>
#include "PILHA_FILA.h"
/*Construir um programa que receba uma fila Q, contendo números inteiros. Em
seguida, solicitar ao usuário um valor e: se o valor for par, colocar todos os elementos pares no
início da fila e os elementos ímpares no final; se o valor for ímpar, colocar todos os elementos
ímpares no início da fila e os elementos pares no final. Imprimir a fila original e depois a fila
ajustada de acordo com a opção do usuário.*/
void separa_par_impar(Fila **Q, int op)
{
    Fila *auxI=CriaFila(),*auxP=CriaFila(); 
    int info;
    while(!VaziaFila(*Q))
    {
        info=RetiraFila(*Q);
            if(info%2==0)
                InsereFila(auxP,info);
            else
                InsereFila(auxI,info);
    }
    if(op%2==0)
    {
        while(!VaziaFila(auxP))
        {
            info=RetiraFila(auxP);
            InsereFila(*Q,info);
        }
        while(!VaziaFila(auxI))
        {
            info=RetiraFila(auxI);
            InsereFila(*Q,info);
        }
    }
    else
    {
        while(!VaziaFila(auxI))
        {
            info=RetiraFila(auxI);
            InsereFila(*Q,info);
        }
        while(!VaziaFila(auxP))
        {
            info=RetiraFila(auxP);
            InsereFila(*Q,info);
        }
    }
    liberaFila(auxI);
    liberaFila(auxP);
}

int main()
{
    Fila *Q=CriaFila();
    int info;
    do{
        printf("\nInsira elementos na Fila Q (-999 para sair):");
        scanf("%d",&info);
        if(info!=-999)
            InsereFila(Q,info);
    }while(info!=-999);
    printf("\nDigite um valor:");
    scanf("%d",&info);
    system("clear");
    printf("Fila Lida:");
    imprimeFila(Q);
    printf("\n\nNumero Lido: %d",info);
    separa_par_impar(&Q,info);
    printf("\n\nFila apos a separacao:");
    imprimeFila(Q);
    printf("\n");
    liberaFila(Q);
    return 0;
}
