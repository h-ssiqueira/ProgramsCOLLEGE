#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 100

void ler(float vet[]){

    for(int i=0;i<n;i++){
        printf("Insira um valor para [%d]: ",i);
        scanf("%f",&vet[i]);
        fflush(stdin);
    }
}

int search(float x[],float m){

for(int i=0;i<n;i++){
    if(m==x[i])
    return i;
}
return -1;
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    int pos;
    float v[n],x;

    ler(v);

    printf("Insira o valor a ser procurado: ");
    scanf("%f",&x);

    pos=search(v,x);

    system("cls");

    if(pos>=0)
       printf("Valor encontrado! Posição v[%d]",x,pos); // colocar o valor (%f) não funciona

    else
       printf("Valor não encontrado",x);

    return 0;
}
