#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e imprima o valor de S:1/1+3/2+...+99/50*/

int main()
{
    int i=1, j=1;
    float S=0;
    while(i<=99 && j<=50){
        S = S + ((float)i/(float)j);
        i+=2;
        j++;
    }

    printf("\n Soma de fracoes = %.2f", S);

    return 0;
}
