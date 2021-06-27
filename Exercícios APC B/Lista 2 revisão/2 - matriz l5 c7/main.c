#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 10

int main()
{
    setlocale (LC_ALL,"portuguese");
    int m[tam][tam], i, j, ma5=m[0][0], ma7=m[0][0], me5=m[0][0], me7=m[0][0];

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
        printf("Insira um valor para: ");
        scanf("%d", &m[i][j]);
        if(i==5){
            if(m[5][j]>ma5)
            ma5=m[5][j];
            if(m[5][j]<me5)
            me5=m[5][j];
        }
        if(j==7){
            if(m[i][7]>ma7)
            ma7=m[i][7];
            if(m[i][7]<me7)
            me7=m[i][7];
        }
        }
    }
    printf("menor valor da linha 5: %d\n Maior valor da linha 5: %d\n Menor valor da coluna 7: %d\n Maior valor da coluna 7:", me5, ma5, me7, ma7);
    return 0;
}
