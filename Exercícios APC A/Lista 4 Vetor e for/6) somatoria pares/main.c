#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, S;
    printf("\n Insira o tamanho do vetor = ");
    scanf("%d", &N);
    int X[N];
    for(i=0, S=0;i<N;i++){
        printf("\n Insira o valor de X[%d] = ", i);
        scanf("%d", &X[i]);
        if(X[i]%2==0)
            S+=X[i];
    }
    printf("\n X[] = ");
    for(i=0;i<N;i++)
        printf(" %d ", X[i]);
    printf("\n \n Somatoria = %d", S);
    return 0;
}
