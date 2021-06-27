#include <stdio.h>
#include <stdlib.h>

/*Construir um programa que faz a leitura de duas notas de um aluno, N1 e N2, e os
respectivos pesos, P1 e P2. Calcular a média e imprimir: as notas lidas, os pesos, a
média calculada e se APROVADO ou REPROVADO. Média maior ou igual à 5.0
representa aprovado.*/

int main()
{
    float n1, n2, p1, p2, r;

    printf("\n Insira a primeira nota = ");
    scanf("%f", &n1);

    printf("\n Insira a segunda nota = ");
    scanf("%f", &n2);

    p1 = 0.4 ;
    p2 = 0.6 ;

    r = n1 * p1 + n2 * p2;

    printf("\n valor da primeira e segunda notas = %.2f e %.2f \n Valor dos pesos = %.2f e %.2f \n Valor da media = %.2f", n1, n2, p1, p2, r);

    if(r>=5){
        printf("\n APROVADO \n");
    }

    else{
        printf("\n REPROVADO \n");
    }


    return 0;
}
