#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char x[2][4], a[]={'aula'};int i, j=0;
    for(i=0;i<2;i++){
    printf("\n Insira 'aula', com letras maiusculas ou minusculas = ");
    scanf("%s", x[i]);
    }
    for(i=0;i<2;i++){
    if(stricmp(x[i],a)!=0)
        j++;
    }
    printf("\n %d", j); // deve resultar em 8 para que haja igualdade de strings
    return 0;
}
