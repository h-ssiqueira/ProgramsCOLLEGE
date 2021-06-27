#include <stdio.h>
#include <stdlib.h>

void LeiaVetor10(int n[]){
    for(int i=0;i<10;i++){
        printf("insira um valor para v[%d]:",i);
        scanf("%d", &n[i]);
    }
}

void multiplica(int n[], int x){
    for(int i=0;i<10;i++){
    n[i]*=x;
    }
}

void EscreveVetor10(int n[]){
    for(int i=0;i<10;i++)
    printf("\n%d", n[i]);
}


int main()
{
    int v[10], m;
    LeiaVetor10(&v);
    printf("Insira o numero a ser multiplicado: ");
    scanf("%d", &m);
    multiplica(&v,m);
    EscreveVetor10(v);
    return 0;
}
