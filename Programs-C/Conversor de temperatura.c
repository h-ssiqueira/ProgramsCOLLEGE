#include <stdio.h>
#include <stdlib.h>

int main(){
    float C, F, K;
    int x;

    do{
        do{
            printf("\n Insira:\n 0 para fechar o programa.\n 1 para converter Celsius para Fahrenheit e Kelvin.\n 2 para converter Kelvin para Celsius e Fahrenheit.\n 3 para converter Fahrenheit para Celsius e Kelvin.\n -> ");
            scanf("%d", &x);
            system("cls");
        }while(x>3 || x<0);
        switch(x){
            case 0:break;
            case 1:
                printf("\n Insira a temperatura em Celsius = ");
                scanf("%f", &C);
                K=273+C;
                F=(1.8*C)+32;
                system("cls");
                printf("\n %.2f C = %.2f F e %.2f K",C,F,K);
                printf("\n________________________________________\n");
                break;
            case 2:
                printf("\n Insira a temperatura em Kelvin = ");
                scanf("%f", &K);
                C=K-273;
                F=(1.8*C)+32;
                system("cls");
                printf("\n %.2f K = %.2f F e %.2f C",K,F,C);
                printf("\n________________________________________\n");
                break;
            case 3:
                printf("\n Insira a temperatura em Fahrenheit = ");
                scanf("%f", &F);
                C=(F-32)*5/9;
                K=C+273;
                system("cls");
                printf("\n %.2f F = %.2f C e %.2f K",F,C,K);
                printf("\n________________________________________\n");
                break;
        }
    }while(x!=0);
    return 0;
}
