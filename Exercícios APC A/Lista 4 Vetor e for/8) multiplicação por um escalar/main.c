#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, k;
    printf("\n Insira o tamanho do vetor = ");
    scanf("%d", &N);
    printf("\n Insira o valor a ser multiplicado = ");
    scanf("%d", &k);
    int X[N], Y[N];
    for(i=0;i<N;i++){
        printf("\n Insira o valor de X[%d] = ", i);
        scanf("%d", &X[i]);
        Y[i]=X[i]*k;
    }
    printf("\n Y[] = ");
    for(i=0;i<N;i++)
        printf(" %d ", Y[i]);

    return 0;
}
