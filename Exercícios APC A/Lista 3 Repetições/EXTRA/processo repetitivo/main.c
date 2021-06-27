#include <stdio.h>
#include <stdlib.h>

int main()
{
    int K;

    printf("\t K \t K*K \n");
    printf("================================ \n");
    K=1;
    while(K<=100){

    printf("\t %3d \t %5d \n", K, K*K);
    K=K+1;
    }
    return 0;
}
