#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, c, i;

	/*
    do{
		printf("\n Insira um número maior que 2: ");
		scanf("%d", &n);
		for(i=2, c=0;i<=n/2;i++){
			if(n%i==0){
				c++;
				break;
			}
		}
		c==0 ? printf("\n Número primo") : printf("\n Número não primo");
    }while(n > 2);
	*/

	do{
		printf("\n Insira um número maior que 2: ");
		scanf("%d", &n);
		for(i = 2, c = 0; i < sqrt(n); i++){
			if(n % i == 0){
				c++;
				break;
			}
		}
		c == 0 ? printf("\n Número primo") : printf("\n Número não primo");
	}while(n > 2);

    return 0;
}
