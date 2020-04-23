#include <stdio.h>
#include <stdlib.h>

int sumd(int a){
//int sum=0;
    if(a>0)
        return (a%10)+sumd((a/=10));
}

int main()
{
    int boo, n, soma=0;

    do{
    printf("\nInsira um valor inteiro positivo: ");
    scanf("%d", &n);
    }while(n<0);

    do{
    printf("\nInsira: \n0 para calcular de forma iterativa.\n1 para calcular de forma recursiva.\n-> ");
    scanf("%d",&boo);
    }while(boo!=0 && boo!=1);

    system("cls");

switch(boo){
    case 0:
        while(n>0){
            soma+=n%10;
            n/=10;
        }
        break;

    case 1:
        soma=sumd(n);
        break;
    }

    printf("Soma = %d", soma);

    return 0;
}
