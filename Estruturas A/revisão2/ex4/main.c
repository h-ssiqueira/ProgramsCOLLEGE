#include <stdio.h>
#include <stdlib.h>

struct carros{
    char proprietario[25],modelo[15],cor[10],chassi[17],placa[8];
    int ano,combustivel;
};

void info(struct carros carro[],int n);
void alccol2k(struct carros carro[],int n);
void placaA(struct carros carro[],int n);
void vogal(struct carros carro[],int n);

int main()
{
    int n,x;
    struct carros *carro;
    do{
        printf("\tInsira a quantidade de carros: ");
        scanf("%d",&n);
    }
    while(n<1);
    carro = (struct carros *)malloc(n * sizeof(struct carros));
    info(carro,n);
    printf("\n\t1 - Alcool\n\t2 - Placa\n\t3 - Vogal\n\t->");
    scanf("%d",&x);
    switch(x){
    case 1:alccol2k(carro,n);
        break;
    case 2:placaA(carro,n);
        break;
    case 3:vogal(carro,n);
        break;
    }
    free(carro);

    return 0;
}


void info(struct carros carro[],int n){
    for(int i = 0; i < n; i++){
        fflush(stdin);
        printf("\tInsira o nome do proprietario: ");
        gets(carro[i].proprietario);
        fflush(stdin);
        printf("\tInsira o modelo do carro: ");
        gets(carro[i].modelo);
        fflush(stdin);
        printf("\tInsira a cor do carro: ");
        gets(carro[i].cor);
        fflush(stdin);
        printf("\tInsira o chassi do carro");
        gets(carro[i].chassi);
        fflush(stdin);
        printf("\tInsira a placa do carro (XXX-0000): ");
        gets(carro[i].placa);
        fflush(stdin);
        printf("\tInsira o ano do carro: ");
        scanf("%d",&carro[i].ano);
        printf("\tInsira o tipo de combustivel do carro.\n\t\t1 -> alcool.\n\t\t2 -> gasolina.\n\t\t3 -> Flex");
        scanf("%d",&carro[i].combustivel);
    }
}

void alccol2k(struct carros carro[],int n){
    for(int i = 0; i < n; i++){
        if(carro[i].ano <= 2000 && carro[i].combustivel == 1)
            printf("\n\t%s",carro[i].proprietario);
    }
}

void placaA(struct carros carro[],int n){
    for(int i = 0; i < n; i++){
        if(carro[i].placa[0] == 65)
            switch(carro[i].placa[7]){
        case '0':printf("\n\t%s -> %s",carro[i].placa,carro[i].proprietario);
            break;
        case '2':printf("\n\t%s -> %s",carro[i].placa,carro[i].proprietario);
            break;
        case '4':printf("\n\t%s -> %s",carro[i].placa,carro[i].proprietario);
            break;
        case '7':printf("\n\t%s -> %s",carro[i].placa,carro[i].proprietario);
            break;
            }
    }
}

void vogal(struct carros carro[],int n){
    for(int i = 0; i < n;i++){
        switch(carro[i].placa[1]){
    case 'A':printf("\n\t%s %s",carro[i].modelo,carro[i].cor);
        break;
    case 'E':printf("\n\t%s %s",carro[i].modelo,carro[i].cor);
        break;
    case 'I':printf("\n\t%s %s",carro[i].modelo,carro[i].cor);
        break;
    case 'O':printf("\n\t%s %s",carro[i].modelo,carro[i].cor);
        break;
    case 'U':printf("\n\t%s %s",carro[i].modelo,carro[i].cor);
        break;
        }
    }
}
