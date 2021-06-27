#include <stdio.h>
#include <stdlib.h>
#define tam 10 // define here the size of triangle

int main(){
	int m[tam][tam];
	for(int i = 0; i < tam; i++){
		for(int j = 0;j < tam; j++){
			if(i == j || j == 0) m[i][j] = 1;
			else if(j < i) m[i][j] = m[i-1][j] + m[i-1][j-1];
			else m[i][j] = 0;
			printf(" %3d ", m[i][j]);
		}
		printf("\n");
	}
    return 0;
}