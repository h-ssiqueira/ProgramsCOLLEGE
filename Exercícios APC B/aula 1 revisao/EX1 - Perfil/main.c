#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int dia, mes, ano, dm, soma, parte1, parte2, total;
    float i=0;
    printf("Insira sua data de nascimento: ");
    scanf("%d/%d/%d", &dia,&mes,&ano);

    dm = dia*100 + mes;

    soma = dm + ano;

    i = (float)soma/100;

    parte1 = i;

    i-=parte1;

    parte2 = i*100;

    total = (parte1 + parte2)%5;

    switch(total){
    case 0:
        printf("\n Tímido");
        break;
    case 1:
        printf("\n Sonhador");
        break;
    case 2:
        printf("\n Paquerador");
        break;
    case 3:
        printf("\n Atraente");
        break;
    case 4:
        printf("\n Irresistível");
        break;
    }

    return 0;
}
