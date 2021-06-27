#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Ler X e Y e calcular X elevado à potência Y. Utilizar a função: resultado = pow (x,
y); sendo que X deve ser maior do que zero e Y deve ser do tipo inteiro e maior do
que zero. Biblioteca: <math.h>*/

int main()
{
    int Y;
    float X, Z;

    printf("\n Digite um valor para X = ");
    scanf("%f", &X);

    printf("\n Digite um valor para a potencia = ");
    scanf("%d", &Y);

    if(X<=0 || Y<=0){
        printf("\n Erro 404: numero(s) invalido(s)");
    }
    else{
        Z = pow(X,Y);
        printf("\n %.2f ^ %d = %.2f", X, Y, Z);
    }

    return 0;
}
