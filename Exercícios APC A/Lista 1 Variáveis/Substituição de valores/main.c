#include <stdio.h>

/*Escreva um programa que leia, via teclado, valores para quatro vari�veis inteiras a,
b, c, d. Ap�s lidos os valores, inverta os valores a com b e c com d, e imprima na tela
as vari�veis na mesma ordem de entrada. Veja que n�o � apenas imprimir invertido
� mudar nas vari�veis os valores.*/

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
