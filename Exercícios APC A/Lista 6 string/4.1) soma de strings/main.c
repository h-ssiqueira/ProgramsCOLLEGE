#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char X[50], Y[50], Z[100];
    printf("\n Insira a primeira string = ");
    gets(X);
    fflush(stdin);
    printf("\n Insira a segunda string = ");
    gets(Y);

    printf("\n %s", X);
    printf("\n %s", Y);
    for(i=0;X[i]!='\0';i++)
        Z[i]=X[i];
    for(j=0;Y[j]!='\0';i++, j++)
        Z[i]=Y[j];
    Z[i]='\0'; // Z[100]={0}
    printf("\n %s", Z);
    return 0;
}
