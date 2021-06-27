#include <stdio.h>
#include <stdlib.h>

int leitura(int p1,int p2,int p3){
    printf("Primeiro numero: ");
    scanf("%d",&p1);
    printf("Segundo numero: ");
    scanf("%d",&p2);
    printf("Terceiro numero: ");
    scanf("%d",&p3);
    return p2;
    return p3;
    return p1;

}

int main()
{
    int n1=0,n2=0,n3=0;

    leitura(n1,n2,n3);
    printf("%d\t%d\t%d",n1,n2,n3);
    return 0;
}
