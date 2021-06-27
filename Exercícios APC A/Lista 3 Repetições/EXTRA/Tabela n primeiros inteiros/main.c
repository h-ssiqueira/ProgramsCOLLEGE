#include <stdio.h>
#include <stdlib.h>

int main()
{
    int K;
    printf("\n \t K \t K*3 \n");
    printf("============================= \n");
    K = 2;

    while(K<=50){
        printf("\t %3d \t %3d \n", K, K*3);
        K = K + 2;
    }
    return 0;
}
