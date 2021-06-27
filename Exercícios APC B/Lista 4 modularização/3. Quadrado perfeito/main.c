#include <stdio.h>
#include <stdlib.h>

int QP(int a){
    int x;
x=sqrt(a);
if(x*x==a)
    return 1;
else
    return 0;
}

int main()
{
    int n;
    do{
    printf("Insira um numero: ");
    scanf("%d", &n);
    }while(n<0);
    printf("\n%d",QP(n));

    return 0;
}
