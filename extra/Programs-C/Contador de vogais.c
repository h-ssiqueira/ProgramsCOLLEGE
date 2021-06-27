#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char frase[100];
    int v=0, i, n;
    printf("\n Insira a frase = ");
    gets(frase);
    n=strlen(frase);
    for(i=0;i<n;i++){
        if(frase[i]=='a' || frase[i]=='A')
            v++;
        else if(frase[i]=='e' || frase[i]=='E')
            v++;
        else if(frase[i]=='i' || frase[i]=='I')
            v++;
        else if(frase[i]=='o' || frase[i]=='O')
            v++;
        else if(frase[i]=='u' || frase[i]=='U')
            v++;
    }
        printf("\n %s \n %d vogais", frase, v);
    return 0;
}
