#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, r, i, j, k, M, x, s;
    do{
        printf("\n Insira o tamanho da primeira matriz NxM = ");
        scanf("%dx%d", &n, &m);
        printf("\n Insira o tamanho da segunda matriz MxR = ");
        scanf("%dx%d", &M, &r);
    }while(m != M);
    int X[n][m], Y[M][r], Z[m][M];
    //system("cls");
    printf("\n\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("\n Insira um valor para X[%d][%d] = ", i, j);
            scanf("%d", &X[i][j]);
        }
    }
    //system("cls");
    printf("\n\n");
    for(i = 0; i < M; i++){
        for(j = 0; j < r; j++){
            printf("\n Insira um valor para Y[%d][%d] = ", i, j);
            scanf("%d", &Y[i][j]);
        }
    }
    //system("cls");
    printf("\n\n");

    for(i = 0; i < n; i++){
        for(j = 0; j < r; j++){
            Z[i][j]=0;
            for(k = 0; k < M; k++)
                s += X[i][k] * Y[k][j];
                  
            Z[i][j]=s;
            s=0;
        }
    }
    printf("\n\n");


    printf("\n Z[%d][%d]\n",n, r);
    for(i = 0; i < n; i++){
        for(j = 0; j < r; j++)
            printf("%3d ",Z[i][j]);
    printf("\n");
    }
    return 0;
}
