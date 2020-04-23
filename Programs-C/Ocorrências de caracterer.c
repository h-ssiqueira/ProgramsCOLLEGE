#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char x, frase[21];
    int n=0, i;

    printf("Insira a frase: ");
    scanf("%[^\n]", frase);
    fflush(stdin);
    printf("Insira um caracter: ");
    scanf("%c", &x);

    for(i=0;i<strlen(frase);i++){
        if(frase[i]==x)
        n++;
    }
    system("cls");
    printf("O caracter '%c' apareceu %d vezes na frase:\n%s", x, n, frase);

    return 0;
}
