#include <stdio.h>
#include <stdlib.h>

int main(){
	int fact, N, i;
	do{
		printf("\tInsira o valor inteiro para calcular o fatorial: ");
		scanf("%d", &N);
	}while(N < 0);
	for(i = 1, fact = 1; i <= N; i++)
		fact *= i;
	printf("\n %d! = %d", N, fact);
    return 0;
}
