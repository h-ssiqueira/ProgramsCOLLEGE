#include <stdio.h>
#include <stdlib.h>
#define x 3

int max(int n[],int m, int c){
    if(c!=x){
        if(m<n[c]){
            m=n[c];
            return max(n,m,++c);
        }
        else
            return max(n,m,++c);
    }
    else return m;
}


int main()
{
    int v[x],maior,cont=0;

    for(int i=0;i<x;i++){
    printf("Insira um valor positivo para v[%d]: ",i);
    scanf("%d",&v[i]);
    }

    maior=v[0];

    printf("Maior valor: %d",max(v,maior,cont));
    return 0;
}
