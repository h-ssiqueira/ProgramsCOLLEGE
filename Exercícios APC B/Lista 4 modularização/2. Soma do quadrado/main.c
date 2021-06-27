#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ler(int *a){
printf("Insira um numero: ");
scanf("%d", a);
system("cls");
}

int quad(int *a){
return pow(*a,2);
}

int soma(int *a, int *b){
return quad(&*a)+quad(&*b);;
}

int main()
{
    int x,y;

    ler(&x);
    ler(&y);
    printf("%d", soma(&x,&y));
    return 0;
}
