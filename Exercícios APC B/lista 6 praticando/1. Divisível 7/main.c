#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 100

void ler(int x[]){

    for(int i=0;i<n;i++){
        printf("Insira um valor para [%d]: ",i);
        scanf("%d",&x[i]);

    }
}

int dsete(int x[]){
int aux=0;

for(int i=0;i<n;i++){
    if(x[i]%7==0)
        aux++;
}

return aux;
}

int main()
{
setlocale(LC_ALL,"portuguese");
    int sete,v[n];

    ler(v);
    sete=dsete(v);
    system("cls");
    for(int i=0;i<n;i++){
        printf(" %d ",v[i]);
    }
    printf("\n\n%d números divisíveis por 7",sete);

    return 0;
}
