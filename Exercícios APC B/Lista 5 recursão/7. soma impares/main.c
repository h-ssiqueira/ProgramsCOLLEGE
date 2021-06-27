#include <stdio.h>
#include <stdlib.h>

int cal(int x, int j){
    if(x>0) return j+cal(--x,j+2);
}

int main()
{
    int n ,sum=0 ,boo ,i=1;

    do{
    printf("Insira um valor inteiro positivo: ");
    scanf("%d", &n);
    }while(n<0);

    do{
    printf("\nInsira: \n0 para calcular de forma iterativa.\n1 para calcular de forma recursiva.\n-> ");
    scanf("%d",&boo);
    }while(boo!=0 && boo!=1);

    system("cls");

    switch(boo){
    case 0:
        while(n>0){
            sum+=i;
            i+=2;
            n--;
        }
        break;
    case 1:
        sum=cal(n,i);
        break;
    }

    printf("%d",sum);
    return 0;
}
