#include <stdio.h>
#include <stdlib.h>

int mult(int n1,int n2);

int main()
{
    int n1,n2;
    printf("\tInsira o primeiro valor: ");
    scanf("%d",&n1);
    printf("\tInsira o segundo valor: ");
    scanf("%d",&n2);
    printf("%d * %d = %d",n1,n2,mult(n1,n2));
    return 0;
}

int mult(int n1, int n2){
    if(n2==1)
        return n1;

    return n1+mult(n1,(n2-1));
}
