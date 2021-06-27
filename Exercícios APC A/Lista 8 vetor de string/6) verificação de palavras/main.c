#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char x[3][15]={0},y[10]={0};
    int i,j=0;
    for(i=0;i<3;i++){
        printf("\n Insira uma palavra = ");
        scanf("%s",x[i]);
        fflush(stdin);
    }
    printf("\n Insira mais uma = ");
    scanf("%s", y);

for(i=0;i<3;i++){
        if(strcmp(y,x[i])!=0)

        printf("\n Sem palavras iguais");
    else
        printf("\n Existe palavras iguais");
}
        for(i=0;i<3;i++)
            printf("\n %s",x[i]);
    printf("\n\n %s", y);
    return 0;
}
