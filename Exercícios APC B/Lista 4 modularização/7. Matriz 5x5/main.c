#include <stdio.h>
#include <stdlib.h>

void LeiaMatriz(float l[][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
           printf("Insira um valor para [%d][%d]", i, j);
           scanf("%d",&l[i][j]);
        }
    }
}

int MaiorValorLinha(float l[][5], int x){
    int maior=0;
for(int i=0;i<5;i++){
    if(maior>l[x][i])
    maior=l[x][i];
}
return maior;
}

void SomaLinha(float l[][5], int x, int y){
for(int i=0;i<5;i++){
    l[x][i]+=l[y][i];
}

}

void TrocaLinha(float l[][5], int *x, int *y){
    int aux;
for(int i=0;i<5;i++){
    aux=l[*x][i];
    l[*x][i]=l[*y][i];
    l[*y][i]=aux;
}

}

void imprimeMatriz(float l[][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
           printf(" %.3d ", l[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    float m[5][5];int r, l,l1,l2;
    LeiaMatriz(&m);
    system("cls");
    printf("Insira:\n 1 para maior elemento de uma linha\n 2 para somar uma linha com outra\n 3 para trocar linhas\n->");
    scanf("%d",&r);
    system("cls");
    switch(r){
    case 1:
    printf("Insira a linha:");
    scanf("%d", &l);
    printf("Maior valor: %.3f",MaiorValorLinha(m,l));
    break;
    case 2:
        printf("Insira o numero da primeira linha:");
        scanf("%d", &l1);
        printf("Insira o numero da segunda linha: ");
        scanf("%d", &l2);
        SomaLinha(m,l1,l2);
        break;
    case 3:
        printf("Insira o numero da primeira linha:");
        scanf("%d", &l1);
        printf("Insira o numero da segunda linha: ");
        scanf("%d", &l2);
        TrocaLinha(m,&l1,&l2);
        break;
    }

    imprimeMatriz(m);
    return 0;
}
