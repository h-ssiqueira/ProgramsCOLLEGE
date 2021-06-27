#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, s, n, m;
    printf("\n Insira o tamanho da matriz = ");
    scanf("%dx%d", &n, &m);
    int X[n][m], Y[n][m], Z[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
            printf("\n Insira um valor para X[%d][%d] = ", i, j);
            scanf("%d", &X[i][j]);
        }
    }
        for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
            printf("\n Insira um valor para Y[%d][%d] = ", i, j);
            scanf("%d", &Y[i][j]);
        }
    }


    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                Z[i][j]=Y[i][j]+X[i][j];
        }
    }
    printf("\n X =\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%3d ", X[i][j]);
        printf("\n\t");
    }
    printf("\n Y =\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%3d ", Y[i][j]);
        printf("\n\t");
    }
    printf("\n Z =\t");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%3d ", Z[i][j]);
        }
        printf("\n\t");
    }
    return 0;
}
