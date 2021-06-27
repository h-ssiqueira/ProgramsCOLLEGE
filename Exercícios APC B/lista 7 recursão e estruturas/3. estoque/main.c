#include <stdio.h>
#include <stdlib.h>
#define max 5

struct estoque{
int serial;
int qtd;
float p_venda;
float p_custo;
};

void ler(struct estoque peca[]){
for(int i=0;i<max;i++){
    printf("\nSerial peca[%d]: ",i);
    scanf("%d",&peca[i].serial);
    printf("\nQuantidade peca[%d]: ",i);
    scanf("%d",&peca[i].qtd);
    printf("\nPreco venda peca[%d]: ",i);
    scanf("%f",&peca[i].p_venda);
    fflush(stdin);
    printf("\nPreco custo peca[%d]: ",i);
    scanf("%f",&peca[i].p_custo);
    fflush(stdin);
    system("cls");
}
}

int menor_est(struct estoque peca[]){
int ser,menor;
menor = peca[0].qtd;
for(int i=0;i<max;i++){
    if(menor>peca[i].qtd){
        menor = peca[i].qtd;
        ser = peca[i].serial;
    }
}
return ser;
}

int maior_lucro(struct estoque peca[],int *est){
int ser;
float maior,aux;

for(int i=0;i<max;i++){
    aux = peca[i].p_venda - peca[i].p_custo;

    if(maior<aux){
    ser = peca[i].serial;
    *est = peca[i].qtd;
    maior = aux;
    }
}
return ser;
}

float media_venda(struct estoque peca[]){
float media=0;

for (int i=0;i<max;i++)
    media += peca[i].p_venda;

return (media/max);
}

float percentual(struct estoque peca[],float r){
float p=0;
for(int i=0;i<max;i++){
    if(peca[i].p_custo>r)
    p++;
}
return ((p/max)*100);
}

int main()
{
    struct estoque peca[max];
    int menor_qtd,est,ser_lucro;
    float med,percent,x;

    ler(&peca);

    printf("Preco de pecas maior que: $");
    scanf("%f",&x);

    menor_qtd = menor_est(peca);

    ser_lucro = maior_lucro(peca,&est);

    med = media_venda(peca);

    percent = percentual(peca,x);

    printf("\n\nMenor quantidade: %d",menor_qtd);
    printf("\nSerial e quantidade de maior lucro: %d %d",ser_lucro,est);
    printf("\nValor medio preco de venda: %.2f",med);
    printf("\nPercentual de pecas com preco de custo maior que %.2f = %.2f%%",x,percent);
    return 0;
}
