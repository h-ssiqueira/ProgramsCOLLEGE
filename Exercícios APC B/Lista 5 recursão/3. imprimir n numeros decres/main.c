#include <stdio.h>
#include <stdlib.h>

int valor(int a){
    if(a!=0){
        printf("\n%d",a);
        return valor(--a);
    }
}

int main()
{
    int n;

    do{
    printf("Insira um valor positivo: ");
    scanf("%d",&n);
    system ("cls");
    }while(n<0);

    printf("\n%d",valor(n));

    return 0;
}
