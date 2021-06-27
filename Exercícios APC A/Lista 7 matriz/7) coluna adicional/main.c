#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, s, n, m;
    printf("\n Insira o tamanho da matriz NxM = ");
    scanf("%dx%d", &n, &m);
    int X[n][m], Y[n][m+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
            printf("\n Insira um valor para [%d][%d] = ", i, j);
            scanf("%d", &X[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0, s=0;j<m;j++){
                Y[i][j]=X[i][j];
                s+=X[i][j];
        }
        Y[i][j]=s;
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
        for(j=0;j<m+1;j++)
            printf("%3d ", Y[i][j]);
        printf("\n\t");
    }
    return 0;
}
