#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    float a, b, c, x, x1, x2, delta, xv, yv;

    do{

		printf("\n Insira o valor de a (ax%c+bx+c) -> ", 253);
		scanf("%f", &a);
		if(a==0)
			break;
		printf(" Insira o valor de b (ax%c+bx+c) -> ", 253);
		scanf("%f", &b);
		printf(" Insira o valor de c (ax%c+bx+c) -> ", 253);
		scanf("%f", &c);

		delta = pow(b,2) - 4 * a * c;

		system(("cls"));
		printf("\n %.3fx%c + (%.3f)x + (%.3f)\n", a, 253, b, c);
		printf("\n Delta = %.3f", delta);

		if(delta < 0)
			printf("\n Sem ra%czes reais! \n", 161);

		else if(delta == 0){
			x = (-b / 2 * a);
			printf("\n Raiz da equa%c%co: \n X = %.3f \n", 135, 198, x);
		}
		else if(delta > 0){
			x1 = (-b + (sqrt(delta))) / (2 * a);
			x2 = (-b - (sqrt(delta))) / (2 * a);
			printf("\n Ra%czes da equa%c%co: \n X1 = %.3f \n X2 = %.3f \n", 161, 135, 198, x1, x2);
		}

		xv = -b / 2*a;
		yv = -delta / 4*a;

		printf("\n X do v%crtice = %.3f \n Y do v%crtice = %.3f \n", 130, xv, 130, yv);
		printf("________________________________________ \n");

	}while(a!=0);

    return 0;
}
