#include <stdio.h>
#include <stdlib.h>

int main()
{
    float massa;
    int tempo;
    do{
        printf("Insira a massa (em gramas): ");
        scanf("%f", &massa);
    }while(massa<0.05);

    for(tempo=0;massa>0.05;tempo+=50){massa/=2;}


    printf("%d segundos", tempo);
    return 0;
}
