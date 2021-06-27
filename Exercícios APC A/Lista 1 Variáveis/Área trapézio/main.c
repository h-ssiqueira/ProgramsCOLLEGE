/* Escreva um programa que receba como entradas os valores (inteiros) da base maior,
base menor e da altura de um trapézio, calcule e imprima a Área do Trapézio. */

#include <stdio.h>
int main() {

float B, b, H, A;

printf("\n Valor da Base maior = ");
scanf("%f", &B);

printf("\n Valor da base menor = ");
scanf("%f", &b);

printf("\n Valor da altura = ");
scanf("%f", &H);

A = (B + b)*H/2;

printf("\n Valor da base maior = %.2f \n Valor da base menor = %.2f \n Valor da altura = %.2f \n Valor da area = %.2f \n", B, b, H, A);

return 0;
}
