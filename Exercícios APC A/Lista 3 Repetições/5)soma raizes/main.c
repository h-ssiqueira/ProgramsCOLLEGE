#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e imprima o somatório descrito abaixo, onde N deverá ser
lido: raiz quadrada de 1 + raiz quadrada de 2...*/
int main()
{
    int N, i=1;
    float S=0;
    do{
        printf("\n Insira um valor para N = ");
        scanf("%d", &N);
    }while(N<=0);

    while(i<=N){
        S += sqrt(i);
        i++;
    }
    printf("\n A somatoria das raizes dos %d primeiros numeros eh = %.3f", N, S);

    return 0;
}
