#include <stdio.h>
#include <stdlib.h>
#define max 30
#define tam 25


int main()
{
    FILE *arq;
    int i;
    char n1[tam],n2[tam];

    arq = fopen ("teste.txt","w");

    for(i=0;i<max;i++){
        printf("nome e sobrenome:"); scanf("%s %s",n1,n2);
        fprintf(arq,"%s %s\n",n1,n2);
    }

    fclose(arq);
    arq = fopen("teste.txt","r");

    printf("lendo...\n\n");

    for(i=0;i<max;i++){
        fscanf(arq,"%s",n1);
        fscanf(arq,"%s",n2);
        printf("%s %s\n",n1,n2);
    }

    return 0;
}
