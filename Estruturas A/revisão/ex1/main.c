#include <stdio.h>

int rec(int base,int exp);

int main()
{
    int base, exp;
    do{
        printf("\n\tInsira o valor da base: ");
        scanf("%i",&base);
    }while(base<=0);
    do{
        printf("\n\tInsira o valor do expoente: ");
        scanf("%i",&exp);
    }while(exp<0);

    printf("\n\tresultado: %d",rec(base,exp));
    return 0;
}


int rec(int base,int exp){
    if(exp==0)
        return 1;
    return base*rec(base,(exp-1));
}
