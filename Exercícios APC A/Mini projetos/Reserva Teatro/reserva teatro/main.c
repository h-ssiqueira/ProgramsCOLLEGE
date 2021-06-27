// Alcides Gomes Beato Neto 19060987
// Henrique Sartori Siqueira 19240472
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int ml[10][20]={0}, i, j, F;
	char L;

	while(L != '&'){
		for(i = 0; i < 10; i++){
			printf("\t%c ", 65+i);
			for(j = 0; j < 20; j++){
				printf("| %3d |", ml[i][j]);
			}
			printf("\n");
		}
		printf("\t  ");
		for(i = 0; i < 20; i++)
			printf("  %3d  ", i+1);

		do{
			printf("\n Escolha uma fileira <'A' a 'J' e '&' para sair>: ");
			scanf("%c", &L);
			if(L == '&')
                return 0;
			printf("\n Escolha um assento da fileira <1 a 20>: ");
			scanf("%d", &F);
			getchar();
			L = toupper(L);
		}while((L < 65 || L > 76) || (F < 1 || F > 20));
		i = L - 65;
		F--;

		if(ml[i][F] != 0)
			printf("\nLugar ocupado!\n");
		else{
			ml[i][F] = 1;
			printf("\nReserva feita com sucesso!");
			printf("\nIngresso");
			printf("\n--------------------------------------------");
			printf("\nNome da pe%ca: O Fantasma da Opera", 135);
			printf("\nHor%crio: 18h as 21h", 134);
			printf("\nLugar %c%d \n\n", L,++F);
		}
	}
}
