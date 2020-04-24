#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define h 0.1

int main()
{
    float x,A,a,b,fab=0,soma=0,y,y2;
    int i,n;

    printf("\nInsira o intervalo (a|b): ");
    scanf("%f|%f",&a,&b);
    fflush(stdin);

    n = (b-a)/h;

    x = a;

    printf("\n\nI\t\tXi\t\tf(x)\t\t2f(x)");

    for(i=0;i<=n;i++){
        y = x+(1/x);// insira a função aqui #########
        y2 = 2*y;
        if(i==0 || i==n)
            fab+=y;
        else
            soma+=y2;
        printf("\n%d\t\t%.2f\t\t%.4f\t\t%.4f",i,x,y,y2);
        x+=h;
    }

    printf("\n%f\n%f",x,fab);

    A = (h/2)*(fab+soma);
    printf("\nSoma(2y) = %.4f\nA = %.5f",soma,A);
    return 0;
}
