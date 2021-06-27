#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, S;
    printf("\n Insira o comprimento do vetor = ");
    scanf("%d", &N);
    float vet[N];
    for(i=0, S=0;i<N;i++){
        printf("\n Insira o valor de vet[%d] = ", i);
        scanf("%f", &vet[i]);
        S+=vet[i];
    }
    printf("\n Vetor = ");
    for(i=0; i<N; i++)
        printf(" %.2f ", vet[i]);
    printf("\n \n Somatoria = %d", S);
    return 0;
}
