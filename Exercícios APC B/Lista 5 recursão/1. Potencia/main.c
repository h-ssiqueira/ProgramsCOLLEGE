#include <stdio.h>
#include <stdlib.h>

int pot(float x, int n){
    if(n==1)
        return x;
return x * pot(x,--n);
}

int main()
{
    float base, result; int exp;

    printf("Insira a base: ");
    scanf("%f",&base);

    do{
    printf("\nInsira o expoente: ");
    scanf("%d", &exp);
    }while(exp<0);

    result = pot(base,exp);

    printf("\nResultado: %.3f", result);

    return 0;
}
