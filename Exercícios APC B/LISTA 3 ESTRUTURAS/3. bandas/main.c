#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10


typedef struct banda{
char nome[20],gen[20];
int ints,rank;
}band;

void ler(band x[]){
for(int i=0;i<tam;i++){
fflush(stdin);
printf("Insira nome da banda: ");
fgets(x[i].nome,20,stdin);
printf("\nInsira genero musical: ");
fgets(x[i].gen,20,stdin);
printf("\nIntegrantes: ");
scanf("%d",&x[i].ints);
printf("\nRank: ");
scanf("%d",&x[i].rank);
system("cls");

}
}

void imprimir(band x[]){
for(int i=0;i<tam;i++){
printf("\n\n%s",x[i].nome);
printf("\n%s",x[i].gen);
printf("\n%d Integrantes",x[i].ints);
printf("\nRank:%d ",x[i].rank);
}
}

void sgen(band x[]){
    char n[20];
    int aux,count=0;
    printf("\nInsira genero a ser procurado: ");
    fgets(n,20,stdin);

    printf("Bandas com tal genero:");
    for(int i=0;i<tam;i++){
    aux=strcmp(n,x[i].gen);
    if(aux==0){
printf("\n%s",x[i].nome);
    count++;}
}
if(count==0)
    printf("\nSem bandas com esse genero.");
}

void nr(band x[]){
    char y[20];
    int aux,count=0;
printf("\n Insira nome da banda a ser procurada: ");
fgets(y,20,stdin);

for(int i=0;i<tam;i++){
    aux=strcmp(y,x[i].nome);
    if(aux==0){
            count++;
        printf("A banda esta no rank %d",x[i].rank);
        break;
    }

}
if(count==0)
    printf("A banda n esta no rank");
}

int main()
{
    band x[tam];
    ler(x);
    sgen(x);
    nr(x);
    imprimir(x);
    return 0;
}
