#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 3
int main()
{
    //setlocale (LC_ALL,"portuguese");
    int m[tam][tam], i, j, soma=0, produto=1;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
        printf("Insira um numero para m[%d][%d]: ", i, j);
        scanf("%d", &m[i][j]);
        if(i==j)
        soma+=m[i][j];
        if(j+i==tam-1)
        produto*=m[i][j];
        }
    }

    for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
    printf("Soma da diagonal principal: %d\n Produto da diagonal secundaria: %d", soma, produto);

    return 0;
}
