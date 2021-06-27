#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char nome[101], in[50]={0};
    int i, j;

    printf("Digite seu nome completo: ");
    scanf("%[^\n]", nome);
    in[0]=nome[0];

    for(i=0, j=1;i<strlen(nome);i++){
        if(nome[i]==32)
            in[j++]=nome[++i];
    }
    strupr(in);
    printf("%s\n%s", nome, in);
    return 0;
}
