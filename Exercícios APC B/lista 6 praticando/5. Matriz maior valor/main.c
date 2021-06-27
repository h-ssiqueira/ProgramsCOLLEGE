#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 10

void ler(float x[][n]){

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("Insira valor para[%d][%d]:",i,j);
        scanf("%f",&x[i][j]);
    }
}
}

float maior(float m[][n],int *k){
    float maior;
    int i,j,jm=0;
    maior=m[0][0];
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(m[i][j]>maior){
            maior=m[i][j];
            *k=i;
            jm=j;
        }
    }
}
return jm;
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    float m[n][n];
    int im=0,jm;
    ler(m);
    jm=maior(m,&im);
    printf("Localização do maior valor [%d][%d]",im,jm);
    return 0;
}
