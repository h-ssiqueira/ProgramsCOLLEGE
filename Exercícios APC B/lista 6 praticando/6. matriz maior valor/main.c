#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 40

void ler(float m[][n]){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        printf("Insira um valor para [%d][%d]: ",i,j);
        scanf("%f",&m[i][j]);
        fflush(stdin);
        }
    }
}

int search(float x[][n],float m,int *lm){

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(m==x[i][j]){
        *lm=i;
        return j;
        }
    }
}
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    int lm=-1,cm;
    float v[n][n],x;

    ler(v);

    printf("Insira o valor a ser procurado: ");
    scanf("%f",&x);

    cm=search(v,x,&lm);

    system("cls");

    if(lm>=0)
       printf("Valor encontrado! Posição v[%d][%d]",lm,cm); // colocar o valor (%f) não funciona

    else
       printf("Valor não encontrado");

    return 0;
}
