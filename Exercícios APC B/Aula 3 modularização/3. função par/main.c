#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int par(int *aux){
if(*aux%2==0)
    return 1;
else
    return 0;
}

int main()
{
    setlocale (LC_ALL,"portuguese");
    int x;

    printf("Digite um n�mero: ");
    scanf("%d",&x);

    if(par(&x)==0)
        printf("\n �mpar.");
    else
        printf("\n Par.");
    return 0;
}
