#include <stdio.h>

int main(){

int a, b, c, d;
printf("\n Digite o valor de a = ");
scanf("%d", &a);

printf("\n Digite o valor de b = ");
scanf("%d", &b);

printf("\n Digite o valor de c = ");
scanf("%d", &c);

printf("\n Digite o valor de d = ");
scanf("%d", &d);

a = b;
b = a;
c = d;
d = c;

printf("\n valor de a %d \n Valor de b = %d \n Valor de c = %d \n Valor de d = %d \n", a, b, c, d);

return 0;
}
