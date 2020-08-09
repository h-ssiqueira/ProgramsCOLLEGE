#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int x;
    double M, E, c=9*pow(10,16);
    printf("\n Criado por Henrique Sartori Siqueira. Copyright � 2019 Henrique Sartori Siqueira. Todos os direitos reservados. \n \n");
    do{
        do{
        printf("\n Insira: \n 0 para finalizar o programa. \n 1 para calcular a energia. \n 2 para calcular a massa. \n -> ");
        scanf("%d", &x);
        system("cls");
        }while(x<0 && x>2);
        if(x==1){
            printf("\n Insira o valor da massa: ");
            scanf("%lf", &M);
            E = M * c;
            printf("\n Energia = %.5lf \n", E);
            printf("____________________________________________\n");
            }else if(x==2){
            printf("\n Insira o valor da energia: ");
            scanf("%lf", &E);
            M = E/c;
            printf("\n Massa = %.5lf \n", M);
            printf("____________________________________________\n");
            }else if(x==0)
            break;
    }while (x!=0);
    return 0;
}
