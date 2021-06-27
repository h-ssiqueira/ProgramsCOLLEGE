#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que lê dois números reais, representando notas de um
aluno: nota1 e nota2. Calcula a média ponderada, sendo peso 4 na primeira e 6 na
segunda nota digitada. Imprime os valores lidos e a média calculada.*/

int main(){
float x, y, m;

printf("\n Valor da nota 1 = ");
scanf("%f", &x);

printf("\n Valor da nota 2 = ");
scanf("%f", &y);

m = (x * 0.4) + (y * 0.6);

printf("\n Media do aluno = %f", m);

return 0;
}
