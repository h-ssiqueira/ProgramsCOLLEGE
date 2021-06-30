#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA_STRING.h"
#define tam 50
/*
 Utilizando a biblioteca criada no exercício anterior, faça um programa que solicite ao usuário uma sequencia alternada de letras e números. Seu programa deverálistar as letras na ordem em que foram inseridas e os números na ordem inversa. 
 Exemplos:
 Entrada: A1E5T7W8G –Saída: AETWG8751 
 Entrada: 3C9H4Q6 –Saída: CHQ6493 
*/
int eh_numero(char c)//Verifica se o caracter é um número 
{
    if(c >= 48 && c <= 57) 
        return 1;
    return 0;
}

void lista_ordem(Lista_String *L)
{
    Lista_String *aux;
    char C[tam], novo[tam];
    int len, i, j=0;
    for(aux=L; !Vazia_LS(aux); aux = aux->prox)
    {
        j=0;
        strcpy(C,aux->string);
        len=strlen(C);
        for(i=0; i<len; i++)
            if(!eh_numero(C[i]))
                novo[j++]=C[i];
        for(i=len-1; i>=0; i--)
            if(eh_numero(C[i]))
                novo[j++]=C[i];
        novo[j]='\0';
        strcpy(aux->string, novo);
    }
}

int main()
{
    Lista_String *L = Cria_LS();
    char info[tam];
    int conf;
    do{
        printf("\nInsira Letras e numeros de maneira alternada:(digite BREAK para sair):");
        fflush(stdin);
        scanf("%s", info);
        //strupr(info);
        conf=strcmp(info,"BREAK");
        if(conf != 0)
            Insere_LS(&L, info);
     }while(conf != 0);
     system("clear");
     printf("\nLista Lida:");
     Imprime_LS(L);
     lista_ordem(L);
     printf("\n\nLista modificada:");
     Imprime_LS(L);
     Desaloca_LS(L);
     return 0;
}
