#include <stdio.h>
#include <stdlib.h>
#define tam 3

int main()
{
    FILE *arq;
    int i, x[tam], aux;
    arq = fopen("teste.txt","w");
    for (i=0;i<tam;i++){
    printf("Insira valor [%d]",i+1);
    scanf("%d",&x[i]);
    fprintf(arq, "%d\n",x[i]);
    }
    fclose(arq);
    fopen("teste.txt","r");
    printf("\n\n\nLendo.....\n\n\n");
    for (i=0;i<tam;i++){
        fscanf(arq, "%d", &aux);
        printf("%d\n",aux);
    }
    return 0;
}
