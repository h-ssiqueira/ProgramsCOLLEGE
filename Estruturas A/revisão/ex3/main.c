#include <stdio.h>
#include <stdlib.h>

int fat(int n);

int main()
{
    int n;
    do{
    printf("\tInsira um valor: ");
    scanf("%d",&n);
    }while(n<0);
    printf("%d! = %d",n,fat(n));
    return 0;
}

int fat(int n){
    if(n==1 || n==0)
        return 1;

    return n*fat(n-1);
}
