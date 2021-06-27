#include <stdio.h>
#include <stdlib.h>

float Soma(int n){
if(n==1) return 2;

else return ((float)(((n)*(n))+1)/((n)+3) + Soma(--n));

}

int main()
{
    int N;
    float S;
    printf("Digite o valor: ");
    scanf("%d",&N);
    S=Soma(N);
    printf("Soma: %.3f", S);
    return 0;
}
