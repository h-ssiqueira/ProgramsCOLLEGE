#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int divi(int *a, int *b){
if(*a%*b==0)
    return 1;
else
    return 0;

}

int main()
{
    setlocale (LC_ALL,"portuguese");

    int x, y;

    printf("Insira um dividendo: ");
    scanf("%d", &x);
    printf("Insira um divisor: ");
    scanf("%d", &y);

    if(divi(&x,&y)==1)
        printf("\nDivisível.");
    else
        printf("\nNão divisível.");
    return 0;
}
