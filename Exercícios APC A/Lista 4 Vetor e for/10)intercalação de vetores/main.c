#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    printf("\n Insira o tamanho do vetor = ");
    scanf("%d", &N);
    int X[N], Y[N], Z[2*N];
    for(i=0, j=0;i<N;i++, j++){
        printf("\n Insira o valor de X[%d] = ", i);
        scanf("%d", &X[i]);
        printf("\n Insira o valor de Y[%d] = ", i);
        scanf("%d", &Y[i]);
        Z[j]=X[i];
        Z[++j]=Y[i];
    }
    printf("\n X[%d] = ", N);
    for(i=0;i<N;i++)
        printf(" %d ", X[i]);
    printf("\n Y[%d] = ", N);
    for(i=0;i<N;i++)
        printf(" %d ", Y[i]);
    printf("\n Z[%d] = ", N*2);
    for(i=0;i<N*2;i++)
        printf(" %d ", Z[i]);

    return 0;
}
