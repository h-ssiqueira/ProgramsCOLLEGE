#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que faz a leitura consecutiva de N n�meros inteiros x. Construir um
programa que identifica e imprime o MAIOR e o MENOR n�mero entre os n�meros
digitados. O valor de N tamb�m deve ser digitado e deve ser maior ou igual a 10. (N�o
utilizar vetor, apenas vari�veis simples)*/


int main()
{
    int MAIOR=0, MENOR=11, x;

    do{


    printf("\n Insira um numero de 1 a 10 = ");
    scanf("%d", &x);


    if(x>MAIOR && x!=0)
    MAIOR=x;
    else if(x<MENOR && x!=0)
        MENOR=x;


    }while(x!=0);

    printf("\n Menor numero = %d \n Maior numero = %d", MENOR, MAIOR);

    return 0;
}
