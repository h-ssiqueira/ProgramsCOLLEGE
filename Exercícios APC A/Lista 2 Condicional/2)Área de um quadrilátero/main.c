#include <stdio.h>
#include <stdlib.h>

/*Construir um programa para calcular a �rea de um quadril�tero, fazendo a leitura da
base e da altura. Antes de efetuar o c�lculo da �rea, a fim de evitar erros no c�lculo
pela digita��o de n�meros negativos para base e/ou altura, testar se os valores s�o
positivos. Se algum deles ou ambos forem negativos, imprimir mensagem e encerrar
o programa. Caso contr�rio calcular a �rea e imprimir o valor da �rea calculado e se
forma um quadrado ou ret�ngulo.*/

int main()
{
    float B, H, A;
    printf("\n Digite um valor para a base = ");
    scanf("%f", &B);

    printf("\n digite um valor para a altura = ");
    scanf("%f", &H);

    if(B > 0 && H > 0){
        A = B * H;
        printf("\n O valor da area = %.2f", A);
    }
    else
        printf("\n Um dos valores menor do que 0");

    if(H==B){
        printf("\n Quadrado");
    }
    else{
        printf("\n retangulo");
    }


    return 0;
}
