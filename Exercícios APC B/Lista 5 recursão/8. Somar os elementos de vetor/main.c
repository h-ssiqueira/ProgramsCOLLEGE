#include <stdio.h>
#include <stdlib.h>
#define x 3

int somar(int a[], int j){
    if(j<x){
        return (a[j]+somar(a,++j));
    }
    return 0;
}

int main()
{
    int v[x], soma, i;

    for(i=0;i<x;i++){
    printf("Insira um valor para v[%d]: ", i);
    scanf("%d", &v[i]);
    }
    i=0;
    soma=somar(v,i);

    printf("Soma: %d", soma);
    return 0;
}
