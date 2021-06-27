#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char x[10]={0};
    int i, j=0, X;

    printf("\n Insira n%cmeros = ",163);
    scanf("%s", x);
    for(i=0;i!='\0';i++){
    switch(x[i]){
case 48:j++;
    break;
case 49:j++;
    break;
case 50:j++;
    break;
case 51:j++;
    break;
case 52:j++;
    break;
case 53:j++;
    break;
case 54:j++;
    break;
case 55:j++;
    break;
case 56:j++;
    break;
case 57:j++;
    break;
}
    }
    if(j<=i){
        X=atoi(x);
        printf("\t%d", X);
    }
    return 0;
}
