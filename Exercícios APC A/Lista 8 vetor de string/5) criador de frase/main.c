#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[3][15]={0};
    int i;
    for(i=0;i<3;i++){
        printf("\n Insira uma palavra = ");
        scanf("%s",x[i]);
    }
    printf("\n");
    for(i=0;i<3;i++)
        printf("%s ",x[i]);
    return 0;
}
