#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    printf("\n Insira o tamanho do vetor = ");
    scanf("%d", &N);
    int X[N], Y[N], Z[N];
    for(i=0;i<N;i++){
        printf("\n Insira o valor de X[%d] = ", i);
        scanf("%d", &X[i]);
        printf("\n Insira o valor de Y[%d] = ", i);
        scanf("%d", &Y[i]);
        Z[i]=Y[i]+X[i];
    }
    printf("\n Z[%d] = ", N);
    for(i=0;i<N;i++)
        printf(" %d ", Z[i]);

    return 0;
}
