#include <stdio.h>
#include <stdlib.h>

float Soma(int N){

if(N==1) return 1;

return ((float)1/N + Soma(--N));
}

int main()
{
    int N;

    printf("Insira um valor:");
    scanf("%d",&N);

    printf("%.3f",Soma(N));

    return 0;
}
