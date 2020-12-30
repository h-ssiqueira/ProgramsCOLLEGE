#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char p[101], a[101];
	int letras[26] = {0}, i;
	bool conf = true;

	scanf("%s", p);
	getchar(); // ou fflush(stdin) para windows
	scanf("%s", a);
	getchar(); // ou fflush(stdin) para windows

	if(strlen(a) == strlen(p)){
		for(i = 0; i < strlen(a); i++){
			if((p[i] > 'z' || p[i] < 'a') && (a[i] > 'z' || a[i] < 'a') && a[i] != '*'){
				printf("N");
				conf = false;
				break;
			}
			letras[p[i]-97]++;
		}
		for(i = 0; i < strlen(a); i++){
			if(letras[a[i]-97] == 0 && a[i] != '*'){
				printf("N");
				conf = false;
				break;
			}
			else if(a[i] == '*')
				continue;
			else
				letras[a[i]-97]--;
		}
		if(conf)
			printf("S");
	}
	else
		printf("N");
	return 0;
}