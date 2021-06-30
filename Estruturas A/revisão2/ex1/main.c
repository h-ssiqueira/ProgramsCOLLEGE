#include <stdio.h>
#include <stdlib.h>

struct reg{
char nome[50], idd[5];
int idade;
float salario;
};

void coleta(struct reg funcionarios[], int n);

int main()
{
    struct reg *funcionarios;
    int n;
    do{
    printf("\tInsira a quantidade de funcionarios: ");
    scanf("%d",&n);
    fflush(stdin);
    }while(n<1);

    funcionarios = (struct reg *)malloc(sizeof(struct reg)*n);

    coleta(funcionarios,n);
    free(funcionarios);
    return 0;
}

void coleta(struct reg funcionarios[],int n){
    for(int i = 0; i < n;i++){
        printf("\tInsira o nome: ");
        gets(funcionarios[i].nome);
        fflush(stdin);
        do{
            printf("\n\tInsira a idade de %s: ",funcionarios[i].nome);
            scanf("%d",&funcionarios[i].idade);
            fflush(stdin);
        }while(funcionarios[i].idade < 1);
        printf("\n\tInsira o registro profissional na empresa de %s:",funcionarios[i].nome);
        gets(funcionarios[i].idd);
        fflush(stdin);
        do{
            printf("\t\nInsira o salario de %s: ",funcionarios[i].nome);
            scanf("%f",&funcionarios[i].salario);
            fflush(stdin);
        }while(funcionarios[i].salario < 0);
    }

}
