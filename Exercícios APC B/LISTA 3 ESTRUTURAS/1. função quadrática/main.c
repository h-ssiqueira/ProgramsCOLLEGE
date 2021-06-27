#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 10


typedef struct math{
float a,b,c;
}math;

void ler(math eq[]){
for(int i=0;i<tam;i++){
    fflush(stdin);
    printf("\n Insira o valor de a (ax%c+bx+c) -> ", 253);
    scanf("%f", &eq[i].a);
    fflush(stdin);
    printf(" Insira o valor de b (ax%c+bx+c) -> ", 253);
    scanf("%f", &eq[i].b);
    fflush(stdin);
    printf(" Insira o valor de c (ax%c+bx+c) -> ", 253);
    scanf("%f", &eq[i].c);
    system("cls");
}

}

float delta(math eq[],int i){
return (pow(eq[i].b,2) - 4 * eq[i].a * eq[i].c);
}

int main()
{
    math eq[tam];
    int i;
    float x1,x2,x,d;

    ler(eq);

    for(i=0;i<tam;i++){
    printf("\n %.3fx%c + (%.3f)x + (%.3f)\n", eq[i].a, 253, eq[i].b, eq[i].c);
    d=delta(eq,i);

    if(d < 0)
        printf("\n Sem ra%czes reais! \n", 161);

    else if(d == 0){
        x = (-eq[i].b / 2 * eq[i].a);
        printf("\n Raiz da equa%c%co: \n X = %.3f \n", 135, 198, x);
    }
    else if(d > 0){
        x1 = (-eq[i].b + (sqrt(d))) / (2 * eq[i].a);
        x2 = (-eq[i].b - (sqrt(d))) / (2 * eq[i].a);
        printf("\n Ra%czes da equa%c%co: \n X1 = %.3f \n X2 = %.3f \n", 161, 135, 198, x1, x2);
    }
    }
    return 0;
}
