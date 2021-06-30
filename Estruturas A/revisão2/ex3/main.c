#include <stdio.h>
#include <stdlib.h>

struct cheque{
char agencia[4], num_conta[10], correntista[20], num_cheque[15];
struct calendario{int dia,mes,ano;}data;
float valor;
};

void dados(int n,struct cheque cad[]);

int main()
{
    int n;
    struct cheque *cad;

    do{
        printf("\tInsira a quantidade de cheques: ");
        scanf("%d",&n);
    }while(n<1);
    cad = (struct cheque *)malloc(sizeof(struct cheque)*n);
    dados(n,cad);
    free(cad);
    return 0;
}


void dados(int n,struct cheque cad[]){
for(int i = 0;i < n;i++){
    fflush(stdin);
    printf("\n\n\tInsira a agencia: ");
    gets(cad[i].agencia);
    fflush(stdin);
    printf("\n\tInsira o numero da conta: ");
    gets(cad[i].num_conta);
    fflush(stdin);
    printf("\n\tInsira o nome do corretista: ");
    gets(cad[i].correntista);
    fflush(stdin);
    printf("\n\tInsira o numero do cheque: ");
    gets(cad[i].num_cheque);
    fflush(stdin);
    printf("\n\tInsira o valor do cheque: ");
    scanf("%f",&cad[i].valor);
    printf("\n\tInsira a data do cheque: ");
    scanf("%d/%d/%d",&cad[i].data.dia,&cad[i].data.mes,&cad[i].data.ano);


}

}
