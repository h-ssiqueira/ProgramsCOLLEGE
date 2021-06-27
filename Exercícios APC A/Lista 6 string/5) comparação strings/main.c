#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char X[50], Y[50];
    printf("\n Insira a primeira string = ");
    scanf("%[^\n]", X);
    fflush(stdin);
    printf("\n Insira a segunda string = ");
    gets(Y);
    printf("\n %s \n %s", X, Y);
    if(strcmp(X,Y)==0)
        printf("\n Strings iguais!");
    else if(strcmp(X,Y)!=0)
        printf("\n Strings diferentes!");
    return 0;
}
