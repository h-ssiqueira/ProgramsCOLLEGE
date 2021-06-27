#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que faz a leitura de 3 números inteiros quaisquer e imprime
qual deles é o Maior e qual o Menor. Se forem os três iguais imprimir mensagem
informando que os três são iguais.*/

int main()
{
    int A, B, C;
    printf("\n Insira um valor para A = ");
    scanf("%d", &A);

     printf("\n Insira um valor para B = ");
    scanf("%d", &B);

     printf("\n Insira um valor para C = ");
    scanf("%d", &C);

    if(A == B && B == C){
        printf("\n Os tres valores sao iguais");
    }

    if(A>B && B>C){
        printf("\n %d eh o maior valor", A);
        printf("\n %d eh o menor valor", C);
    }


    if(B>A && A>C){
        printf("\n %d eh o maior valor", B);
        printf("\n %d eh o menor valor", C);
    }

    if(C>B && B>A){
        printf("\n %d eh o maior valor", C);
        printf("\n %d eh o menor valor", A);
    }

    if(B>C && C>A){
        printf("\n %d eh o maior valor", B);
        printf("\n %d eh o menor valor", A);
    }

    if(A>C && C>B){
        printf("\n %d eh o maior valor", A);
        printf("\n %d eh o menor valor", B);
    }

    if(C>A && A>B){
        printf("\n %d eh o maior valor", C);
        printf("\n %d eh o menor valor", B);
    }
    return 0;
}
