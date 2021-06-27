#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
if(a>b){
    return (2*a+b);
}
return (2*b+a);
}
void troca(int a, int *b){
int aux=a;
a=*b;
*b=aux;
}

void nada(int a, int b){
a=2*b;
b=a+7;
printf("%d",b);
}
int main()
{
    int x=5,y=4,z=7;
    z=soma(x,y);
    troca(x,&z);
    nada(y,x);
    printf("%d %d %d",x,y,z);
    return 0;
}
