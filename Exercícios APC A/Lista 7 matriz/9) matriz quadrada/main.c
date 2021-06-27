#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, m;
    printf("\n Insira o tamanho da matriz = ");
    scanf("%dx%d", &n, &m);
    int X[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
            printf("\n Insira um valor para X[%d][%d] = ", i, j);
            scanf("%d", &X[i][j]);
        }
    }
    system("cls");
    printf("\n X =\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%3d ", X[i][j]);
        printf("\n\t");
    }
    if(n==m)
        printf("\n Matriz quadrada!");
    else
        printf("\n N%co %c matriz quadrada", 198, 130);

    return 0;
}
