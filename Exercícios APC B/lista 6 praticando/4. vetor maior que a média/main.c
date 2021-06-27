#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 30

void ler(float v[]){

    for(int i=0;i<n;i++){
        printf("Insira um valor para [%d]: ",i);
        scanf("%f",&v[i]);
        fflush(stdin);
    }
}

void med(float x[]){

int i;
float media=0;

    for(i=0;i<n;i++){
        media+=x[i];
    }

    media/=n;

    for(i=0;i<n;i++){
        if(x[i]>media)
          printf(" %.3f ",x[i]);
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    float m[n];
    ler(m);
    med(m);
    return 0;
}
