#include <stdio.h>
#include <stdlib.h>

/*Ler um caractere e fazer testes para identificar se o caractere lido � um n�mero, uma
letra min�scula ou mai�scula ou um s�mbolo. Considere para isso os respectivos
c�digos ASCII dos caracteres:
N�meros de 0 - 9: c�digos de 48 a 57 respectivamente;
Letras min�sculas de a � z: c�digos de 97 a 122 respectivamente;
Letras mai�sculas de A � Z: c�digos de 65 a 90;
Demais s�mbolos incluindo letras acentuadas: c�digos maiores do que 33 e
diferentes dos listados acima. Fa�a uma pesquisa na internet sobre Tabela ASCII para
verificar os c�digos passados e os c�digos de outros caracteres.*/

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
