#include <stdio.h>
#include <stdlib.h>
#define tam 3
//MF 0,3*p1+0,5*p2+0,2*projeto
struct nota{
float p1;
float p2;
float projeto;
float media;

};

struct aluno{
char nome[50];
char RA[9];
struct nota MF;
};

void ler(struct aluno *a,int *count){
    for(int i=0;i<tam;i++){
    printf("\nNome: ");
    gets(a[i].nome);
    fflush(stdin);
    printf("\nRA: ");
    gets(a[i].RA);
    fflush(stdin);
    printf("\nNota P1: ");
    scanf("%f",&a[i].MF.p1);
    fflush(stdin);
    printf("\nNota P2: ");
    scanf("%f",&a[i].MF.p2);
    fflush(stdin);
    printf("\nNota projeto: ");
    scanf("%f",&a[i].MF.projeto);
    fflush(stdin);

    a[i].MF.media=(0,3*a[i].MF.p1+0,5*a[i].MF.p2+0,2*a[i].MF.projeto);
    if(a[i].MF.media<5) *count=*count+1;
    }
}

int main()
{
struct aluno a[tam];
int count=0;
ler(a,&count);
system("cls");
printf("%d alunos com media menor que 5",count);




    return 0;
}
