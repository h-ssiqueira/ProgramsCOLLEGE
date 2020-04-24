#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
	char x[15];
	printf("\nInsert password: ");
	gets(x);
	
	int l = strlen(x), e = 0, n = 0, s = 0, a = 0;
	
	if(l > 16 || l < 8)
		e++;
	for(int i = 0; i < l; i++){
		if(isspace(x[i]))
			e++;
		else if(isdigit(x[i]))
			n++;
		else if(isalpha(x[i]))
			a++;
		else
			s++;
	}
	printf("%s",x);
	if(e == 0 && n != 0 && s != 0)
		printf("\nValid password");
	else
		printf("\nInvalid password");

	printf("\n\n%d spaces or out of range(5-10 chars)\n%d numbers\n%d letters\n%d symbols",e,n,a,s);
    return 0;
}