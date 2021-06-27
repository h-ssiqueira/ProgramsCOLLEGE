#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que faz a conversão de um valor qualquer em reais (R$)
lido, nas seguintes moedas: dólar americano, dólar canadense, euro, libra esterlina,
franco suíço e peso chileno. Busque na internet o valor de R$1,00 nas moedas
citadas. Imprimir o valor em reais e as respectivas conversões nas demais moedas.*/

int main()
{
float BRL, USD, EUR, GBP, SFR, CLP;

 printf("\n Digite o valor em BRL = ");
 scanf("%f", &BRL);

 USD = BRL / 3.81;
 EUR = BRL / 4.32;
 GBP = BRL / 5.08;
 SFR = BRL / 3.80;
 CLP = BRL / 0.0057;

 printf("\n O valor R$%.2f para USD = $%.2f", BRL, USD);
 printf("\n O valor R$%.2f para EUR = $%.2f", BRL, EUR);
 printf("\n O valor R$%.2f para GBP = $%.2f", BRL, GBP);
 printf("\n O valor R$%.2f para SFR = $%.2f", BRL, SFR);
 printf("\n O valor R$%.2f para CLP = $%.2f \n", BRL, CLP);
 return 0;
}
