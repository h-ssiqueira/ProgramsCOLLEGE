#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculo(float a, char b){
float pi;
if(toupper(b)=='M')
    pi = 72.7 * a - 58;

else
    pi = 62.1 * a - 44.7;


return pi;
}

int main()
{
    float alt, peso;
    char s;

    printf("Insira sua altura: ");
    scanf("%f",&alt);
    fflush(stdin);
    printf("Insira seu sexo(M/F): ");
    s=getchar();
    system("cls");
    peso = calculo(alt,s);
    printf("Seu peso ideal corresponde a: %.2f Kg", peso);
    return 0;
}
