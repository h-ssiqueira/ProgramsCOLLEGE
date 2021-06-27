#include <stdio.h>
#include <stdlib.h>
#define max 5
int main()
{
    FILE *arq;
    int i,x,n[max];
    char nome[15];

    printf("Insira nome do arquivo seguido de .txt: ");
    gets(nome);
    fflush(stdin);

    arq = fopen(nome,"w");

    for(i=0;i<max;i++){
        printf("\nInsira numero: ");
        scanf("%d",&x);
        fprintf(arq, "%d\n",x);
    }
    if(arq!=NULL) fclose(arq);

    arq = fopen(nome,"r");
    system("cls");
    for(i=0;i<max;i++){
        fscanf(arq,"%d",&n[i]);
    }
    printf("\nLendo...\n\n");
    if(arq!=NULL)fclose(arq);
    for (i=0;i<max;i++)
    printf("%d\n",n[i]);
    return 0;
}
