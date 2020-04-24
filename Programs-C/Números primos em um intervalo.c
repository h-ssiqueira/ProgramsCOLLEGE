#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,n,c,x;
	printf("\nInsert a number to see the primes in the range (0-X)");
	scanf("%d",&x);
	
	for(n = 1;n <= x; n++){
		for(i = 2, c = 0; i < n; i++){
			if(n % i == 0){
				c++;
				break;
			}
		}
		if(c == 0) printf("%d\n",n);
	}
    return 0;
}