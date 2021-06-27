#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que faz a leitura de duas letras (caracteres – usar char para
declarar as variáveis e %c para ler e para imprimir). Imprimir se elas são iguais ou
diferentes. Se diferentes, imprimir qual delas vem primeiro na ordem alfabética.*/

int main()
{
    char A, B;

    printf("\n Digite um caractere = ");
    scanf("%c", &A);

fflush(stdin);

    printf("\n Digite outro caractere = ");
    scanf("%c", &B);

    if(toupper(A) == toupper(B)){
        printf("\n Caracteres iguais!");
    }
    if(toupper(A) > toupper(B)){
        printf("\n O caractere '%c' procede '%c'", A, B);
    }
    else{
        printf("\n O caractere '%c' procede '%c'", B, A);
    }
    return 0;
}
