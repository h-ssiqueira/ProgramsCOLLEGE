#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, N;

    printf("\n Digite o tamanho do vetor = ");
    scanf("%d", &N);
    int X[N], Y[N], Z[N*2];
    printf("\n");
    for(i=0, j=0 ; i<N && j<N ; i++, j++){

        printf("\n Insira um valor para X[%d] = ", i);
        scanf("%d", &X[i]);
        printf("\n Insira um valor para Y[%d] = ", j);
        scanf("%d", &Y[j]);
    }
    k=0, i=0, j=0;
    while(i<N && j<N){
            if(X[i]<Y[j]){
            Z[k]=X[i];
            k++, i++;
            }
            else{
                Z[k]=Y[j];
                k++, j++;
            }
    }
    while(i<N){
        Z[k]=X[i];
        k++, i++;
    }
    while(j<N){
        Z[k]=Y[j];
        k++, j++;
    }
    printf("\n Z[%d] = ", N);
    for(k=0;k<(2*N);k++){
        printf(" %2d ", Z[k]);
    }


    return 0;
}
