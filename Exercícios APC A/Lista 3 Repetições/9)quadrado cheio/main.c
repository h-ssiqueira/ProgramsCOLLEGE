#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X, i, j;

    do{
    printf("\n insira o lado do quadrado = ");
    scanf("%d", &X);
    }while(X<0 && X>21);

    for(i=1;i<=X;i++){
        printf("\n");
        for(j=1;j<=X;j++){
            printf("*");
    }
    }

    return 0;
}
