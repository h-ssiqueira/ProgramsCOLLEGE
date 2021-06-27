#include <stdio.h>
#include <stdlib.h>
#define tam 3
#define tamtam ((tam*2)+2)
/*
vetor contem a somatoria dos valores das colunas e linhas,
sendo a primeira componente [0,tam-1] as linhas, a segunda componente
[tam+1,2*tam] as linhas e as diagonais [tam] e [2*tam+1]
*/

void magic(int m[][tam]){

int vet[tamtam]={0},l,i,j,c;

for(i=0,l=0,c=1;i<tam;i++,l++,c++){
    for(j=0;j<tam;j++){
        if(i==j) {vet[tam]+=m[i][j];} // diagonal principal
        if((i+j)==(tam-1)) {vet[tamtam-1]+=m[i][j];} // diagonal secundaria
        vet[l]+=m[i][j]; // linhas
        vet[c+tam]+=m[j][i]; // colunas
    }
}
for(i=0;i<tam;i++){
        printf("\n");
        for(j=0;j<tam;j++){
            printf(" %d ",m[i][j]);
        }
    }

printf("\n\n");

for(i=0,j=0;i<tamtam;i++){
    printf(" %d ",vet[i]);
    if(vet[0]!=vet[i]){j++;break;}
}
if(j==0) printf("\nMagic matrix");
else printf("\nNot magic");
}

int main()
{
    int m[tam][tam],i,j;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("\nInsert a value for [%d][%d]: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }

    system("cls");

    magic(m);
    return 0;
}
