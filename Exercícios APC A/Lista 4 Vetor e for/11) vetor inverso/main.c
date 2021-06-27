#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    printf("\n Insira o tamanho do vetor = ");
    scanf("%d", &N);
    int X[N];
    for(i=0;i<N;i++){
    printf("\n X[%d] = ", i);
    scanf("%d", &X[i]);
    }
    i--;
    printf("\n Inverso de X[%d] = [", N);
    while(i>=0){
        printf(" %d ", X[i]);
        i--;
    }
    printf("]");
    return 0;
}
