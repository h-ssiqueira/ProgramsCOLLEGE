#include <stdio.h>
#include <stdlib.h>

int main(){
	int fact, N, i;

	scanf("%d", &N);

	for(i = 1, fact = 1; i <= N; i++)
		fact *= i;
	printf("\n %d! = %d", N, fact);
    return 0;
}
