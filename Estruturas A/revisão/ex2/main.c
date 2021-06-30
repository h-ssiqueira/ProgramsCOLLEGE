#include <stdio.h>
#include <stdlib.h>

int soma(int vet[],int i);

int main()
{
    int vet[10],i;
    for(i = 0;i<10;i++){
        printf("insira posicao %i: ",i+1);
        scanf("%i",&vet[i]);
    }i=0;
    printf("\n\nres = %d",soma(vet,i));

    return 0;
}


int soma(int vet[],int i){
if(i==10)
    return 0;

return vet[i]+soma(vet,(i+1));
}
