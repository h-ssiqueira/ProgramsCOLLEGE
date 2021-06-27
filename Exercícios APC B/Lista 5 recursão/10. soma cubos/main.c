#include <stdio.h>
#include <stdlib.h>

int cubo(int a, int i){
    if(i<=a) return ((i*i*i)+cubo(a,++i));
    return 0;
}

int main()
{
    int n, soma, i=0;

    printf("Insira um valor: ");
    scanf("%d",&n);

    soma = cubo(n,i);

    printf("Soma = %d",soma);

    return 0;
}
