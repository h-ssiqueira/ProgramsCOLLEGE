#include <stdio.h>
#include <stdlib.h>

void sum(int n, int *s){
    int i;
    for(i=1;i<n;i++){
    *s+=i*i;
    }
}

int main()
{
    int n, soma=0;
    printf("Insira o limite da soma: ");
    scanf("%d", &n);

    sum(n,&soma);

    printf("Soma: %d", soma);
    return 0;
}
