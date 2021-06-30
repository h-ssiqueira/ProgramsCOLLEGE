//Henrique Sartori Siqueira    RA:19240472
//Rafael Silva Barbon          RA:19243633
#include<stdio.h>
#include<stdlib.h>
#include"PILHA_FILA.h"
/*Construir um programa que receba uma fila Q, contendo números inteiros. Em seguida,
construir uma função que remova desta fila todos os elementos repetidos. No final imprimir
a fila sem os elementos repetidos. 
*/


int main(){
	Fila *Q = CriaFila();
	int x = 0,z = 0;


	while(x != -999){
		printf("\n\tInsira um valor para a fila (-999 para sair): ");
		scanf("%d",&x);
		if(x!=-999){
			InsereFila(Q,x);
			z++;
		}
	}

	imprimeFila(Q);

	Q = repetidos(Q,z);

	imprimeFila(Q);

	liberaFila(Q);

	return 0;
}

Fila * repetidos(Fila *Q, int z){
	Fila *aux = CriaFila();
	No *n;
	int valor,conf,boole = 1,y;
	
	while(!VaziaFila(Q)){
		y = z;
		valor = RetiraFila(Q);
		n = aux->ini;
		while(y!=-1){
			conf = RetiraFila(aux);
			if(valor == conf){
				boole = 0;
				break;
			}	
			n = n->prox;
			Insirefila(aux,conf);
			y--;
		}
		if(boole != 0)
			InsireFila(aux,valor);
	}
	liberaFila(Q);
	return aux;
}