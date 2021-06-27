#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, res = 0;
	
	printf("\nInsira os numeros inteiros que serao multiplicados (N*N): ");
	scanf("%d*%d",&a,%b);
	
	printf("\nA\tB\tresult\n%d\t%d\t%d", a, b, res);
	
	if(a % 2 != 0){
		res = b;
		printf("\nA\tB\tresult\n%d\t%d\t%d", a, b, res);
	}
	while(a > 0){
		a /= 2;
		b *= 2;
		if(a % 2 != 0) res += b;
		printf("\nA\tB\tresult\n%d\t%d\t%d", a, b, res);
	}
	printf("\nA\tB\tresult\n%d\t%d\t%d", a, b, res);
    return 0;
}