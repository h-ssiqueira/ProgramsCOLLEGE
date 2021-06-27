#include <stdio.h>
#include <stdlib.h>

int valor(int a, int aux){
    if(a==0){
        printf("\n");
        return aux;
}
else {
    printf("\n%d",aux++);
    return valor(--a,aux);
    }
}

int main()
{
    int n, aux=0;
    printf("Insira um valor positivo: ");
    scanf("%d",&n);
    system ("cls");
    printf("%d",valor(n,aux));
    return 0;
}
