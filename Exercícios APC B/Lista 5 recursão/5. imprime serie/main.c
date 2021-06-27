#include <stdio.h>
#include <stdlib.h>

int imprimeserie(int a, int b, int c){
    if(a<b){
        printf("\n%d",a);
        a+=c;
        return imprimeserie(a,b,c);
    }
}

int main()
{
    int i,j,k;

    do{
    printf("Insira um numero positivo: ");
    scanf("%d",&i);
    system("cls");
    }while(i<0);

    do{
    printf("Insira um numero maior que o anterior: ");
    scanf("%d",&j);
    system("cls");
    }while(j<i);

    do{
    printf("Insira o incremento: ");
    scanf("%d",&k);
    system("cls");
    }while(k==0);

    printf("\n%d",imprimeserie(i,j,k));

    return 0;
}
