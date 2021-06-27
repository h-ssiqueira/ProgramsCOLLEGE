#include <stdio.h>
#include <stdlib.h>

typedef struct pnt{
float x,y;
}pnt;

typedef struct ret{
pnt p1,p2;
}ret;

void ler(ret *a){
printf("\nInsira x1: ");
scanf("%f",&a->p1.x);
printf("\nInsira y1: ");
scanf("%f",&a->p1.y);
printf("\nInsira x2: ");
scanf("%f",&a->p2.x);
printf("\nInsira y2: ");
scanf("%f",&a->p2.y);

}

int check(ret a,pnt p){
if((a.p1.x <= p.x && p.x <= a.p2.x)&&(a.p1.y <= p.y && p.y <= a.p2.y))
return 1;
else
return 0;
}

int main()
{
    ret a;
    pnt p;
    int boolean;

    ler(&a);
    fflush(stdin);


    printf("\n Insira px: ");
    scanf("%f",&p.x);
    fflush(stdin);
    printf("\n Insira py: ");
    scanf("%f",&p.y);

    boolean=check(a,p);

    switch(boolean){
    case 0:printf("\nNao esta contido");
    break;
    case 1:printf("\nEsta contido");
    break;
    }
    return 0;
}
