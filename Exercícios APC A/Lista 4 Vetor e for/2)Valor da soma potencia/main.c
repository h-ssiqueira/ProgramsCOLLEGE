#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Fazer um programa que calcula e imprime o valor da soma: s = x^25/1-x^24/2... x/25
O valor de X deve ser lido e positivo.*/

int main()
{
    int x, i, exp;
    float sum=0;

    do{
        printf("\n Insira um valor positivo para x = ");
        scanf("%d", &x);
    }while(x < 0);

    for(i = 1, exp = 3;i <= 3;exp--, i++){
        if(i %2 != 0)
        sum+=(float)pow(x,exp)/i;
        else
            sum-=(float)pow(x,exp)/i;

    }

    printf("\n O valor da soma eh = %.3f", sum);


    return 0;
}
