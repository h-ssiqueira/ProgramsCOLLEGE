#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia um n�mero indeterminado de n�meros inteiros
representando a idade de uma pessoa. A repeti��o da entrada de dados deve ser
interrompida quando for digitado ZERO para a idade. Calcular e imprimir a idade m�dia do
conjunto de idades lidos. (N�o utilizar vetor, apenas vari�veis simples)*/

int main()
{
    int X, N=0, Y=0;
    float Media;

    do{
    printf("\n Insira uma idade: ");
    scanf("%d", &X);

    Y += X;
    N++;
    } while (X>0);

    if(X==0 && N != 0){
        Media = (float)Y / (N-1);
    }

    printf("\n media das idades = %.3f", Media);

    return 0;
}
