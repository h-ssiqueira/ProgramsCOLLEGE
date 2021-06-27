#include <stdio.h>
#include <stdlib.h>

/*Fazer um programa que calcula e imprime, com 5 casas decimais, o valor da soma:
    𝜋 = 4-4/3+4/5-4/7
    Testar seu programa para: 1000, 10000 e 100000 termos. Repare que quanto
maior o número de termos, melhor será a precisão.*/


int main(){

    int j;
    float sum=0, i;

    for(i=1, j=1;j<=100000;i+=2, j++){
        if(j%2==0)
        sum-=4.0/i;
        else
            sum+=4.0/i;
        }

    printf("\n pi = %.5f", sum);

return 0;
}
