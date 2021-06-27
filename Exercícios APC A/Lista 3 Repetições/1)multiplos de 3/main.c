#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e imprima o somatório dos N primeiros múltiplos de 3,
começando pelo número 3. O valor de N deverá ser lido.*/

int main()
{
    int N, i=3, S=0;
    printf("\n Insira um numero = ");
    scanf("%d", &N);

    while(i<=3*N){
        S=S+i;
        i=i+3;
    }
    printf("\n A somatoria dos %d primeiros multiplos de 3 = %d", N, S);
    return 0;
}
