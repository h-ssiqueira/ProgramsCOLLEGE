#include <stdio.h>
#include <stdlib.h>

int fat(int n){
if(n==1)return 1;
return (n*fat(n-2));
}

int main()
{
    int n;

    do{
    printf("\nInsira numero impar: ");
    scanf("%d",&n);
    system("cls");
    }while(n%2==0);

    printf("Fatorial duplo de %d = %d",n,fat(n));

    return 0;
}
