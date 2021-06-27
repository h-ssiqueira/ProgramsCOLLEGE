#include <stdio.h>
#include <stdlib.h>
#define tam 15
#define max 10

typedef struct atleta{
int matricula,idade;
float altura;
}at;

typedef struct data{
int dia,mes,ano;
}d;

typedef struct equipe{
at p[tam];
char nome[30];
d date;
}eq;

void ler(eq x[]){
    int i,j;
for(i=0;i<max;i++){
    for(j=0;j<tam;i++){
        printf("\nInsira matricula(%d): ",j+1);
        scanf("%d",&x[i].p[j].matricula);
        printf("\nInsira idade(%d): ",j+1);
        scanf("%d",&x[i].p[j].idade);
        printf("\nInsira altura(%d): ",j+1);
        scanf("%f",&x[i].p[j].altura);
        fflush(stdin);
    }
    printf("\nInsira nome da equipe(%d): ",i+1);
    gets(x[i].nome);
    printf("\nInsira data fundacao(dd/mm/aaaa)(%d): ",i+1);
    scanf("%d/%d/%d",&x[i].date.dia,&x[i].date.mes,&x[i].date.ano);

}
}

int main()
{
    int i,j;
    eq x[max];
    ler(x);
    for(i=0;i<max;i++){
        for(j=0;j<tam;j++){
        printf("\nMatricula(%d): %d",j+1,x[i].p[j].matricula);
        printf("\nIdade(%d): %d",j+1,x[i].p[j].idade);
        printf("\nAltura(%d): %.2f",j+1,x[i].p[j].altura);
    }
    printf("\nNome da equipe(%d): %s",i+1,x[i].nome);
    printf("\nFundacao(%d): %d/%d/%d",i+1,x[i].date.dia,x[i].date.mes,x[i].date.ano);
        }

    return 0;
}
