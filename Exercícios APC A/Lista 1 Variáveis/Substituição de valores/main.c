#include <stdio.h>

/*Escreva um programa que leia, via teclado, valores para quatro variáveis inteiras a,
b, c, d. Após lidos os valores, inverta os valores a com b e c com d, e imprima na tela
as variáveis na mesma ordem de entrada. Veja que não é apenas imprimir invertido
é mudar nas variáveis os valores.*/

int main(){

int a, b, c, d, x, y, z, w;
printf("\n Digite o valor de a = ");
scanf("%d", &a);

printf("\n Digite o valor de b = ");
scanf("%d", &b);

printf("\n Digite o valor de c = ");
scanf("%d", &c);

printf("\n Digite o valor de d = ");
scanf("%d", &d);

x = a;
y = b;

b = x;
a = y;

z = d;
w = c;

c = z;
d = w;

printf("\n valor de a = %d \n Valor de b = %d \n Valor de c = %d \n Valor de d = %d \n", a, b, c, d);

return 0;
}
