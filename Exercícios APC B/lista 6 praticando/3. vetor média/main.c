#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 1000

void ler(float v[]){

    for(int i=0;i<n;i++){
        printf("Insira um valor para [%d]: ",i);
        scanf("%f",&v[i]);
        fflush(stdin);
    }
}

float med(float x[]){

float media=0;

    for(int i=0;i<n;i++){
        media+=x[i];
    }

    media/=n;

return media;
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    float m[n];
    ler(m);
    for(int i=0;i<n;i++)
        printf(" %.3f ",m[i]);
    printf("\nMédia = %.3f",med(m));
    return 0;
}
