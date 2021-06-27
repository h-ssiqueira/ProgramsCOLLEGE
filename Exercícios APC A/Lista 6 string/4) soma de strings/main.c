#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{

    char X[50], Y[50], Z[100];
    printf("\n Insira a primeira string = ");
    gets(X);
    fflush(stdin);
    printf("\n Insira a segunda string = ");
    gets(Y);


    printf("\n %s", X);
    printf("\n %s", Y);
    printf("\n %s", strcat(X,Y));
    return 0;
}
