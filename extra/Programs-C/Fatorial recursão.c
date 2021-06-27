#include <stdio.h>
#include <stdlib.h>

int fact(int x){
	if(x == 1 || x == 0) return 1;
	 else 
	 return (x * fact(x-1));
}

int main(){
	int x;
	
	scanf("%d",&x);
	printf("%d",fact(x));
    return 0;
}