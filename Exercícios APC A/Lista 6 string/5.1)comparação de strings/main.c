#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char X[50], Y[50];
    int i, j=0, x, y;
    printf("\n Insira a primeira string = ");
    scanf("%[^\n]", X);//gets(X);
    fflush(stdin);
    printf("\n Insira a segunda string = ");
    scanf("%[^\n]", Y);//gets(Y);

    printf("\n X = ");
    for(i=0;X[i]!='\0';i++)
        printf("%c ", X[i]);

    printf("\n Y = ");
    for(i=0;Y[i]!='\0';i++) //Y[i]!='\0'
        printf("%c ", Y[i]);

    for(i=0;X[i]!='\0';i++){
        if(X[i]==Y[i])
            j++;
    }
    if(j==x&&j==y)
        printf("\n S%co iguais!", 198);
    else
        printf("\n S%co diferentes!", 198);
    return 0;
}
