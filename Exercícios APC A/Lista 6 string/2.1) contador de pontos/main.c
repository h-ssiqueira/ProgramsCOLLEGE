#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int n, i, p=0, sp=0, v=0;
    printf("\n Insira o tamanho da string = ");
    scanf("%d", &n);
    char c[n];
    fflush(stdin);
    printf("\n Insira a string = ");
    scanf("%[^\n]", c);
    for(i=0;i<n;i++){
            switch(c[i]){
        case 44:
            v++;
            break;
        case 46:
            p++;
            break;
        case 32:
            sp++;
            break;
            }
    }
    printf("\n %s \n %d v%crgulas \n %d pontos \n %d espa%cos \n", c, v, 161, p, sp, 135);
    return 0;
}
