#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, N, a;

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
    k=0, i=0, j=0, a=0;
    while(i<N && j<N){
            if(X[i]<=Y[j]){
                    if(X[i]==Y[j])
                        i++, j++;
                    else{
                        Z[k]=X[i];
                        k++, i++, a++;
                    }
            }
            else if(Y[j]<=X[i]){
                        if(X[i]==Y[j])
                            i++, j++;
                        else{
                            Z[k]=Y[j];
                            k++, j++, a++;
                        }
            }
    }

    while(i<N){
        Z[k]=X[i];
        k++, i++, a++;
    }
    while(j<N){
        Z[k]=Y[j];
        k++, j++, a++;
    }

    //imprimir vetores

    printf("\n X[i] = ");
    for(i=0;i<N;i++)
        printf(" %d ", X[i]);

    printf("\n Y[j] = ");
    for(j=0;j<N;j++)
        printf(" %d ", Y[j]);

    printf("\n Z[k] = ");
    for(k=0;k<a;k++)
        printf(" %d ", Z[k]);



    return 0;
}
