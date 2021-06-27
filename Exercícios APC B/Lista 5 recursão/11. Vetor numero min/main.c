#include <stdio.h>
#include <stdlib.h>
#define x 3

int min(int n[],int m, int c){
    if(c!=x){
        if(m>n[c]){
            m=n[c];
            return min(n,m,++c);
        }
        else
            return min(n,m,++c);
    }
    else return m;
}


int main()
{
    int v[x],menor,cont=0;

    for(int i=0;i<x;i++){
    printf("Insira um valor positivo para v[%d]: ",i);
    scanf("%d",&v[i]);
    }

    menor=v[0];
    printf("Menor valor: %d",min(v,menor,cont));
    return 0;
}
