#include <stdio.h>
#include <stdlib.h>

/*Uma empresa paga a seus empregados um salário de R$1.500,00 por mês mais
uma comissão de R$200,00 para cada carro vendido e mais 5% do valor da venda.
Construir um programa para calcular o salário do mês de um funcionário, de
acordo com o descrito acima. Para o cálculo da comissão e do adicional de 5% do
valor da venda, o programa deverá ler o número de carros vendidos e valor total
das vendas, do empregado, no mês e, imprimir de forma bem explicativa o salário
do funcionário:
o Salario Base: R$ 1500.00
o Número de Carros Vendidos: .....
o Total de Vendas: R$ .....
o Total de Comissão: R$ ...
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
