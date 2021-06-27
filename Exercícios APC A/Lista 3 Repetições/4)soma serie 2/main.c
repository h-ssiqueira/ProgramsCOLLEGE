#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e imprima o somatório dos N primeiros termos da série
descrita abaixo, onde N deve ser lido: 480/10-475/11+470/12-...*/

int main()
{
    int N, i=480, j=10;
    float S=0;

    do{
        printf("\n insira um valor para N = ");
        scanf("%d", &N);
    }while(N<=0);

    while(j<=N+9){
            if((j%2)==0){
            S +=(float)i/(float)j;
            i -= 5;
            j++;
            }else{ if((N%2)!=0){
             S -=(float)i/(float)j;
            i -= 5;
            j++;
            }
            }
    }


    printf("\n A somatoria dos %d primeiros numeros da serie eh %.3f", N, S);
    return 0;
}
