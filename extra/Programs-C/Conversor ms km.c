#include <stdio.h>
#include <stdlib.h>

int main(){
    float ms, km;
    int x;
    
    do{
        printf("\n Insira 0 para finalizar o programa.\n Insira 1 para converter m/s para km/h.\n Insira 2 para converter km/h para m/s.\n -> ");
        scanf("%d", &x);
        system("cls");
        if(x==1){
            printf("\n Insira o valor em m/s = ");
            scanf("%f", &ms);
            printf("\n %.3f m/s = %.3f km/h\n\n", ms, ms*3.6);
        }
        else if(x==2){
            printf("\n Insira o valor em km/h = ");
            scanf("%f", &km);
            printf("\n %.3f km/h = %.3f m/s\n\n", km, km/3.6);
        }
    }while(x==1||x==2);
    return 0;
}
