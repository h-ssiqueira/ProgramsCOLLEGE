#include <stdio.h>
#include <stdlib.h>

void somadiv(int x,int *y){
for(int i=1;i<=x;i++){
    if(x%i==0)
        *y+=i;
    }
}

int main()
{
    int n,soma=0;

    do{
    printf("Insira um numero positivo: ");
    scanf("%d", &n);
    }while(n<0);

    somadiv(n,&soma);

    printf("Soma: %d", soma);

    return 0;
}
