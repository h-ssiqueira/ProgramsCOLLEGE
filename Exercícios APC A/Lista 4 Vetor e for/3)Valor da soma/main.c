#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Fazer um programa que calcula e imprime o valor da soma: s=1/225-2/196...+16384/1*/

int main()
{
    int j, exp;
    float sum=0;

    for(j=15, exp=0 ; j>=1 ; j--, exp++){
        if(j%2==0)
            sum-=(float)(pow(2,exp))/(pow(j,2));
        else
            sum+=(float)(pow(2,exp))/(pow(j,2));
    }

    printf("\n O valor da soma eh = %.3f", sum);



    return 0;
}
