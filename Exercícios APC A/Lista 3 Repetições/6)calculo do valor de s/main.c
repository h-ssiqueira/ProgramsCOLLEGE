#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que calcule e escreva o valor de S: 1/1-2/4+3/9-...-10/100*/

int main()
{
    int i=1;
    float S=0;

    while(i<=10){
        if((i%2)!=0){
        S+=(float)i/(i*i);
        i++;
        }
        else{ if((i%2)==0){
            S-=(float)i/(i*i);
            i++;
            }
        }
    }
    printf("\n Valor da serie = %.3f", S);

    return 0;
}
