#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char x[1000];
	
	printf("\nInsira a string: ");
	gets(x);
	for(int i = 0; i < strlen(x); i++)
		printf(" %d ", x[i]);
    return 0;
}