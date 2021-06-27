#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, j;
   float sum=100, fact=1;

   for(i=99, j=1;j<=2;i--,j++){
        fact=(float)j*fact;
        sum+=(float)i/fact;

   }

    printf("\n Soma dos 20 primeiros termos = %f", sum);

    return 0;
}
