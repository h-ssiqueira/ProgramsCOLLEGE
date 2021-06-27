#include <stdio.h>
#include <stdlib.h>

int main(){
    float compra, pago, troco;
    int n1, n10, n100;
    do{
        printf("Insira o valor da compra: ");
        scanf("%f", &compra);
        printf("\n Insira o valor pago: ");
        scanf("%f", &pago);
    }while((compra&&pago)<0);

    troco = pago - compra;

    printf("\n Valor da compra: %.2f\n Valor pago: %.2f\n Valor do troco: %.2f", compra, pago, troco);

    if(troco>100){
        n100 = (int)troco/100; troco -= n100*100; 
        printf("\n %d notas de 100", n100);
    }
    if(troco>10){
        n10 = (int)troco/10; troco -= n10*10; 
        printf("\n %d notas de 10", n10);
    }
    if(troco>1){
        n1 = (int)troco; troco -= n1; 
        printf("\n %d notas de 1", n1);
    }


    return 0;
}
