#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e imprima o somatório dos N primeiros termos da série
descrita abaixo, onde N deve ser lido: 1000/1-997/2+994/3-991/4*/

int main()
{
    int N, i=1000, j=1;
    float S=0;
do{
    printf("\n Insira um valor para N = ");
    scanf("%d", &N);
}while(N<=0);

    while(j<=N){
        if ((j%2)==0){
        S = S -((float)i/j);
        j++;
        i=i-3;
        }
        else{if(j%2!=0){
            S = S +((float)i/j);
            j++;
            i=i-3;}
        }

    }
    printf("\n o somatorio dos %d primeiros numeros da serie eh = %.3f", N, S);

    return 0;
}
