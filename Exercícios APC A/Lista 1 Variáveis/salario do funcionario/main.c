#include <stdio.h>
#include <stdlib.h>

/*Uma empresa paga a seus empregados um sal�rio de R$1.500,00 por m�s mais
uma comiss�o de R$200,00 para cada carro vendido e mais 5% do valor da venda.
Construir um programa para calcular o sal�rio do m�s de um funcion�rio, de
acordo com o descrito acima. Para o c�lculo da comiss�o e do adicional de 5% do
valor da venda, o programa dever� ler o n�mero de carros vendidos e valor total
das vendas, do empregado, no m�s e, imprimir de forma bem explicativa o sal�rio
do funcion�rio:
o Salario Base: R$ 1500.00
o N�mero de Carros Vendidos: .....
o Total de Vendas: R$ .....
o Total de Comiss�o: R$ ...
o Total de Adicional de 5%: R$ ....
o Salario a RECEBER: R$.....*/

int main()
{
    int CV;
    float VTV, SB, TC, TA, SR;

    SB = 1500;

    printf("\n Numero de carros vendidos = ");
    scanf("%d", &CV);

    printf("\n Valor total de vendas = ");
    scanf("%f", &VTV);

    TC = 200 * CV;
    TA = 0.05 * VTV;
    SR = SB + TC + TA;

    printf("\n Salario base: R$%.2f \n Numero de carros vendidos: %d \n Total de vendas: R$%.2f \n Total de comissao: R$%.2f \n Total de adicional de 5%%: %.2f \n Salario a receber: R$%.2f", SB, CV,VTV, TC, TA, SR);
    return 0;
}
