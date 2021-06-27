#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Ler um n�mero X (diferente de zero) e calcular a raiz quadrada, armazenando o
resultado em outra vari�vel. Testar o programa para n�meros inteiros e reais
positivos. Utilizar a fun��o: resultado = sqrt(X); Biblioteca: <math.h>.*/

int main()
{
    float X, Y;
    printf("\n Insira um valor = ");
    scanf("%f", &X);

    if(X<=0){
        printf("\n Erro 404: raiz nao encontrada");
    }
    else{
        Y=sqrt(X);
    printf("\n A raiz de %.2f = %.2f", X, Y);
    }
    return 0;
}
