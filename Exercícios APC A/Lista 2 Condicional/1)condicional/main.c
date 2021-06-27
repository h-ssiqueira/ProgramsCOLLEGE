#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que faz a leitura de um número inteiro qualquer e imprime
de ele é múltiplo de 5 ou não.*/

int main()
{
    int N, R;

    printf("\n Insira um valor = ");
    scanf("%d", &N);

    R = N % 5;

    if(R == 0){
        printf("\n O valor eh multiplo de 5");
        }
    else{
        printf("\n O valor nao eh multiplo de 5");
        }

    return 0;
}
