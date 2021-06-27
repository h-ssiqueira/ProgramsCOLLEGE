#include <stdio.h>
#include <stdlib.h>

struct dma{
int dia,mes,ano;
};

void ler(struct dma *d){
printf("\nInsira data aa/mm/aaaa: ");
scanf("%d/%d/%d",&d->dia,&d->mes,&d->ano);
system("cls");
}

int qtd_dias(struct dma x,struct dma y){
    int dias=0,ax,ay;
    ax=((x.ano*365)+(x.mes*30)+x.dia);
    ay=((y.ano*365)+(y.mes*30)+y.dia);

    dias=ay-ax;
return dias;
}

int main()
{
    struct dma x,y;

    ler(&x);
    ler(&y);

    printf("%d dias decorreram entre as duas datas.",qtd_dias(x,y));
    return 0;
}
