#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 3

float med(int a[], int j,float s){
    if(j<N){
        s += a[j];
        return (med(a,++j,s));
    }
    return (s/N);
}

int main()
{
    setlocale(LC_ALL,"");
    int v[N], i;
    float soma=0;


    for(i=0;i<N;i++){
        printf("Insira um valor para v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    i=0;

    printf("Média: %.3f", med(v,i,soma));

    return 0;
}
