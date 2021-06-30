#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int letra = 0,tam,i,j;
    char word[20];
    printf("\tInsira uma palavra: ");
    scanf("%s",word);
    tam=strlen(word);
    ///pal(i,j,word);
    for(i=0, j=tam-1;i<tam/2;i++,j--){
        if(word[i]!=word[j])
            if(word[i+1]==word[j]||word[i]==word[j-1])
                letra++;
            else{
                letra=-1;
                break;
            }
    }

    letra == -1 ? printf("\t%s n eh palindroma",word):letra%2!=0 ? printf("\t%s eh palindroma se retirar %d letras",word,letra%2):printf("%s eh palindroma",word);

    return 0;
}

/*int pal(int i,int j,char word[]){ ///falta var de qntd de letras a ser retirada para ser palindroma
    if(word[i]!=word[j])
        if(word[i+1]==word[j])
            pal(i+1,j,word);
        if(word[i]==word[j-1])
            pal(i,j-1,word);
    else
        return 1;

}*/
