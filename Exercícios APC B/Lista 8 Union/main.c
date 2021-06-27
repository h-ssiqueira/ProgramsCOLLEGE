// Alcides Gomes Beato Neto 19060987
// Henrique Sartori Siqueira 19240472

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct passatempo{
char sexo,RA[9],nome[25];
float gastos;
int pt;
union{
    struct leitura{
        float qml;
        char autor[30];
        int book;
        char tl[11];
    }ler;

    struct cinema{
    float qmf;
    char diretor[30],tf[13],cat[9];
    }cine;

    struct vgame{
    char jogo[30];
    float horas;
    }game;

    }A;
}pst;

void ler(pst x[]){
for(int i=0;i<max;i++){
    printf("\n\n Insira nome estudante %d: ",i+1);
    gets(x[i].nome);
    fflush(stdin);
    printf("\n Insira RA estudante %d: ",i+1);
    gets(x[i].nome);
    fflush(stdin);
    printf("\n Insira sexo estudante %d: ",i+1);
    scanf("%c",&x[i].sexo);
    printf("\n Insira gastos estudante %d: ",i+1);
    scanf("%f",&x[i].gastos);
    fflush(stdin);
    do{
    printf("\n Insira passatempo:\n1 para leitura\n2 para cinema\n3 para video game\n-> ");
    scanf("%d",&x[i].pt);
    fflush(stdin);
    }while(x[i].pt<1||x[i].pt>3);
    switch(x[i].pt){
case 1:
    printf("\n Insira tipo de livro: ");
    gets(x[i].A.ler.tl);
    fflush(stdin);
    printf("\n Insira quantidade media de livros lidos por mes: ");
    scanf("%f",&x[i].A.ler.qml);
    fflush(stdin);
    printf("\n Insira autor: ");
    gets(x[i].A.ler.autor);
    fflush(stdin);
    break;
case 2:
    printf("\n Insira tipo de filme: ");
    gets(x[i].A.cine.tf);
    fflush(stdin);
    printf("\n Insira a categoria: ");
    gets(x[i].A.cine.cat);
    fflush(stdin);
    printf("\n Insira quantidade media de filme: ");
    scanf("%f", &x[i].A.cine.qmf);
    fflush(stdin);
    printf("\n Insira seu diretor favorito : ");
    gets(x[i].A.cine.diretor);
    fflush(stdin);
    break;
case 3:
    printf("\nInsira principal jogo que joga: ");
    gets(x[i].A.game.jogo);
    fflush(stdin);
    printf("\nQuantidade de horas mensais que joga esse jogo: ");
    scanf("%f",&x[i].A.game.horas);
    fflush(stdin);
    break;
    }

}
}


float gamers(pst x[]){
    float aux=0;
    for(int i=0;i<max;i++){
        if(x[i].pt==3)
            aux++;
    }
return (aux/max);
}

int mgasta(pst x[]){
    int pos;
    float aux=0;
    for(int i=0;i<max;i++){
        if(x[i].gastos<aux){
            pos=i;
            aux=x[i].gastos;
        }
    }
return pos;
}

int lemais(pst x[]){
    float aux=0;
    int pos;
    for(int i=0;i<max;i++){
        if(x[i].pt==1){
            if(x[i].A.ler.qml<aux){
            aux=x[i].A.ler.qml;
            pos=i;
    }
        }
        }
return pos;
}

void busca(pst x[],char sra[]){
int m;
for(int i=0;i<max;i++){
    m=strcmp(sra,x[i].RA);
    if(m==0){
        switch (x[i].pt){
    case 1:
    printf("\n Tipo de livro: %s", x[i].A.ler.tl);
    printf("\n Quantidade media de livros lidos por mes: %f",x[i].A.ler.qml);
    printf("\n Autor: %s", x[i].A.ler.autor);
    break;
case 2:
    printf("\n Tipo de filme: %s",x[i].A.cine.tf);
    printf("\n Categoria: %s",x[i].A.cine.cat);
    printf("\n Quantidade media de filme: %f", x[i].A.cine.qmf);
    printf("\n Diretor favorito: %s", x[i].A.cine.diretor);
    break;
case 3:
    printf("\n Principal jogo que joga: %s",x[i].A.game.jogo);
    printf("\n Quantidade de horas mensais que joga esse jogo: %f",x[i].A.game.horas);
    break;
    } break;
    }

}

}

int main()
{
    pst n[max];
    char sra[9];
    float vg;
    int mg,leitor;
    ler(n);

    vg=gamers(n);
    mg=mgasta(n);
    leitor=lemais(n);
        printf("%2.f alunos jogam video game", vg);
        printf("RA do aluno que mais gasta: %s", n[mg].RA);
        printf("Nome do aluno que le mais livros: %s", n[leitor].nome);
    printf("\nDigite RA do individuo: ");
    gets(sra);
    busca(n,sra);

    return 0;
}
