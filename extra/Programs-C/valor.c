#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define max 100

bool N(char n){
    if(n >= 48 && n <= 57)
        return true;
    return false;
}

bool B(char *string, int *i){
    int j;
    while(*i < max-3){
        if(*(string+*i) == ',') // Cadeia correta
            return true;
        else if(*(string+*i) == '.'){ // Começo de cadeia
            (*i)++;
            j = 0;
            while(j < 3 && N(*(string+*i))){ // Verifica NNN
                j++;
                (*i)++;
            }
            if(j != 3) // Não possui NNN
                return false;
        }
        else
            return false;
    }
    return false;
}

bool A(char *string, int *i){
    int j = 0;
    while(N(*(string+*i)) && j < 3){ // j verifica se a quantidade de dígitos confere (N | NN | NNN)
        (*i)++;
        j++;
    }
    if(!N(*(string+*i)) && j != 0) // i ficará com a posição do '.'
        return true;
    return false;
}

bool V(char *string){
    int i = 3;
    if(*string == 'R' && *(string+1) == '$' && *(string+2) == ' '){ // Conferência para "R$ "
        if(A(string,&i)){ // Conferência para N | NN | NNN
            if(B(string,&i)){ // Conferência da repetição ou não de .NNN
                if(*(string+i) == ',' && N(*(string+i+1)) && N(*(string+i+2)) && *(string+i+3) == '\0') // Conferência do sufixo ,NN\0
                    return true;
            }
        }
    }
    return false;

}

int main(){
    char *string = calloc(max,sizeof(char));
    printf("\nInsira o valor a ser transferido para sua conta: ");
    scanf("%[^\n]s", string);
    getchar();
    V(string) ? printf("\nValor correto e transferido!\n\n") : printf("\nValor/formato incorreto -> nada foi transferido!\n\n");
    free(string);
    return 0;
}