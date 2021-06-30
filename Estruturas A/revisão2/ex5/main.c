#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
char busao[6],co[20],cd[20],data[11],hora[6],passagem[8],poltrona[3],nome[15],idd[13];
float dist;
};

void info(struct dados pass[],int n);
void ma_e_me_dist(struct dados pass[],int n);
void madestino(struct dados pass[],int n);
void relbus(struct dados pass[],int n);

int main()
{
    struct dados *pass;
    int n;
    printf("\n\tInsira o numero de passagens: ");
    scanf("%d",&n);
    pass = (struct dados *)malloc(n * sizeof(struct dados));

    info(pass,n);
    ma_e_me_dist(pass,n);
    madestino(pass,n);
    relbus(pass,n);
    free(pass);
    return 0;
}

void info(struct dados pass[],int n){
    for(int i = 0; i < n;i++){
        system("cls");
        fflush(stdin);
        printf("\tInsira numero do onibus: ");
        gets(pass[i].busao);
        fflush(stdin);
        printf("\tInsira cidade origem: ");
        gets(pass[i].co);
        fflush(stdin);
        printf("\tInsira cidade destino: ");
        gets(pass[i].cd);
        fflush(stdin);
        printf("\tInsira data: ");
        gets(pass[i].data);
        fflush(stdin);
        printf("\tInsira hora: ");
        gets(pass[i].hora);
        fflush(stdin);
        printf("\tInsira passagem: ");
        gets(pass[i].passagem);
        fflush(stdin);
        printf("\tInsira poltrona: ");
        gets(pass[i].poltrona);
        fflush(stdin);
        printf("\tInsira nome: ");
        gets(pass[i].nome);
        fflush(stdin);
        printf("\tInsira idade: ");
        gets(pass[i].idd);
        fflush(stdin);
        printf("\tInsira distancia: ");
        scanf("%f",&pass[i].dist);
    }
}

void ma_e_me_dist(struct dados pass[],int n){
    float ma = pass[0].dist,me = pass[0].dist;
    for(int i = 0; i < n;i++){
        if(ma < pass[i].dist)
            ma = pass[i].dist;
        if(me > pass[i].dist)
            me = pass[i].dist;
    }
    printf("\t\nMaior distancia: %.2f\n\tMenor distancia: %.2f",ma,me);
}

void madestino(struct dados pass[],int n){
    for(int i = 0; i < n;i++){

    }
}

void relbus(struct dados pass[],int n){
    char aux[6];
    int a;
    fflush(stdin);
    printf("\tInsira o numero de onibus a ser procurado: ");
    gets(aux);
    for(int i = 0; i < n;i++){
        a = strcmp(pass[i].busao,aux);
        if(a == 0)
            printf("\t%s\n",pass[i].nome);
    }
}
