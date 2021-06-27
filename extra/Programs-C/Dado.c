#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	
	srand(time(NULL));
	n = rand()%6+1;
	if(n == 1)
		printf("  _____\n |     |\n |  O  |\n |_____|");
	else if(n == 2)
		printf("  _____\n |   O |\n |     |\n |_O___|");
	else if(n == 3)
		printf("  _____\n |   O |\n |  O  |\n |_O___|");
	else if(n == 4)
		printf("  _____\n | O O |\n |     |\n |_O_O_|");
	else if(n == 5)
		printf("  _____\n | O O |\n |  O  |\n |_O_O_|");
	else 
		printf("  _____\n | O O |\n | O O |\n |_O_O_|");
    return 0;
}