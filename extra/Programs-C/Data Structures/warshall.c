#include <stdio.h>
#include <stdlib.h>
#define n 6

void print(int m[][n]){
	int i,j;
	printf("  "); // 1
	for(i = 0; i < n; i++) // 1 + n(2)
		printf("v%d ",i); // n
	printf("\n"); // 1
	for(i = 0; i < n; i++){ // 1 + n(2)
		printf("v%d ",i); // n
		for(j = 0; j < n; j++){ // n + n²(2)
			printf("%d  ",m[i][j]); // n²
		}
		printf("\n"); // n
	}
	printf("\n"); // 1
	// 1 + 1 + n(2) + n + 1 + 1 + n(2) + n + n + n²(2) + n² + n + 1
	// = 5 + 8n + 3n²
}

int main(){
	int m[][n] = {{0,1,1,0,0,0},
				  {1,0,0,1,0,0},
				  {0,1,0,0,0,0},//{0,0,0,0,0,0},
				  {0,1,2,0,0,1},//{0,1,2,1,0,1},
				  {0,0,1,1,0,1},
				  {0,0,0,1,0,0}}, p[n][n],i,j,k;

	for(i = 0; i < n; i++){ // 1 + n(2)
		for(j = 0; j < n; j++) // n + n²(2)
			m[i][j] > 0 ? (p[i][j] = 1) : (p[i][j] ^= p[i][j]); // n²(2)
	}
	// = 1 + 3n + 4n²
	for(k = 0; k < n; k++){ // 1 + n(2)
		for(i = 0; i < n; i++){ // n + n²(2)
			for(j = 0; j < n; j++){ // n² + n³(2)
				if(p[i][j] == 0) // n³
					p[i][j] = p[i][k] * p[k][j]; // n³
			}
		}
	}
	// = 1 + 3n + 3n² + 4n³

	print(m); // = 5 + 8n + 3n²
	print(p); // = 5 + 8n + 3n²
	return 0;
}

/*
Complexidade: O(n³)

Primeiro loop (definindo valores da matriz p):
1 + 3n + 4n²

Segundo loop (algoritmo de warshall):
1 + 3n + 3n² + 4n³

Exibição na tela:
2 * (5 + 8n + 3n²)

Soma da complexidade:
12 + 22n + 13n² + 4n³

Ignorar termos de ordem inferior relativos ao maior termo:
4n³

Ignorar constantes:
O(n³)
*/