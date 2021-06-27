#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[10];
    int i;
    printf("\n Insira a string aqui = ");
    scanf("%s", x);
    for(i=0;i<10;i++){
        if(x[i]==97)
            x[i]=111;
        else if(x[i]==101)
            x[i]=117;
    }
    printf("\n %s", x);
    return 0;
}
