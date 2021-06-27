#include <stdio.h>
#include <stdlib.h>

/*Ler um caractere e fazer testes para identificar se o caractere lido é um número, uma
letra minúscula ou maiúscula ou um símbolo. Considere para isso os respectivos
códigos ASCII dos caracteres:
Números de 0 - 9: códigos de 48 a 57 respectivamente;
Letras minúsculas de a – z: códigos de 97 a 122 respectivamente;
Letras maiúsculas de A – Z: códigos de 65 a 90;
Demais símbolos incluindo letras acentuadas: códigos maiores do que 33 e
diferentes dos listados acima. Faça uma pesquisa na internet sobre Tabela ASCII para
verificar os códigos passados e os códigos de outros caracteres.*/

int main()
{
    char a;

    printf("\n Insira um caractere = ");
    scanf("%c", &a);

    switch(a){
case 'a':
case 'b':
case 'c':
case 'd':
case 'e':
case 'f':
case 'g':
case 'h':
case 'i':
case 'j':
case 'k':
case 'l':
case 'm':
case 'n':
case 'o':
case 'p':
case 'q':
case 'r':
case 's':
case 't':
case 'u':
case 'v':
case 'w':
case 'x':
case 'y':
case 'z':
     printf("\n Letra minuscula");
break;
case 'A':
case 'B':
case 'C':
case 'D':
case 'E':
case 'F':
case 'G':
case 'H':
case 'I':
case 'J':
case 'K':
case 'L':
case 'M':
case 'N':
case 'O':
case 'P':
case 'Q':
case 'R':
case 'S':
case 'T':
case 'U':
case 'V':
case 'W':
case 'X':
case 'Y':
case 'Z':
    printf("\n Letra maiuscula");
break;
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
    printf("\n eh um numero");
break;
default:
printf("\n eh um simbolo");

    }
    return 0;
}
