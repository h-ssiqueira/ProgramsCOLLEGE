#include <stdio.h>
#include <stdlib.h>

int main()
{
    float C, F;

    printf("\t Grau F \t Grau C \n");
    printf("================================== \n");
    F = 30;

    while(F <= 50){

    C = 5.0 / 9 *(F - 32);
    printf("\t %6.2f \t %6.2f \n", F, C);
    F++;
    }

    return 0;
}
