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
        if(c[i]==',')
            v++;
        else if(c[i]=='.')
            p++;
        else if(isspace(c[i])!=0)
            sp++;
    }
    printf("\n %s \n %d v%crgulas \n %d pontos \n %d espa%cos \n", c, v, 161, p, sp, 135);
    return 0;
}
