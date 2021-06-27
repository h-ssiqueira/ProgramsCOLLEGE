#include <stdio.h>
#include <stdlib.h>
#define max 2

void consulta(FILE *arq){
    char desc[25];
    int o;
    float preco;

    arq = fopen("produtos.dat","r");

    system("cls");
    printf("\n\nProdutos com preco superior a 500...\n\n\n");
    for(int i=0;i<max;i++){
        fscanf(arq,"%d\n",&o);
        fscanf(arq,"%s\n",&desc);
        fscanf(arq,"%f\n",&preco);
        if(preco>500.00){
        printf("%s\n",desc);
        }
    }
    if(arq!=NULL)fclose(arq);



}


int main()
{
    FILE *arq;
    int i,cod,count=0;
    float preco;
    char desc[25];

    arq = fopen("produtos.dat","w");

    for(i=0;i<max;i++){
        printf("\nInsira codigo: ");
        scanf("%d",&cod);
        fflush(stdin);
        fprintf(arq, "%d\n",cod);
        printf("\nInsira descricao: ");
        gets(desc);
        fflush(stdin);
        fprintf(arq, "%s\n",desc);
        printf("\nInsira preco: ");
        scanf("%f",&preco);
        fflush(stdin);
        fprintf(arq, "%.2f\n\n",preco);
        system("cls");
    }
    if(arq!=NULL) fclose(arq);

    consulta(arq);
    return 0;
}
