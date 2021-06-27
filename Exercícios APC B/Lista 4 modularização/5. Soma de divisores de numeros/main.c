#include <stdio.h>
#include <stdlib.h>

void Ler(int *a){
do{
printf("Insira um numero: ");
scanf("%d", a);
}while(a<0);

}
int SomaDivisores(int a){
    int soma=0;
for(int i=1;i<a;i++){
        if(a%i==0)
    soma+=i;
    }
    return soma;
}

int main()
{
    int n, i=0;
    do{
    Ler(&n);
    printf("\n%d\n",SomaDivisores(n));
    i++;
    }while(i<5);

    return 0;
}
