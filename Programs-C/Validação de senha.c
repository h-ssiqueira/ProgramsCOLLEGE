#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
	char x[15];
	printf("\nInsert password: ");
	gets(x);
	
	int l = strlen(x), e = 0, n = 0, s = 0, a = 0;
	
	if(l > 16 || l < 8)
		e++;
	for(int i = 0; i < l; i++){
		if(isspace(x[i]))
			e++;
		else if(isdigit(x[i]))
			n++;
		else if(isalpha(x[i]))
			a++;
		else
			s++;
	}
	printf("%s",x);
	if(e == 0 && n != 0 && s != 0)
		printf("\nValid password");
	else
		printf("\nInvalid password");

	printf("\n\n%d spaces or out of range(5-10 chars)\n%d numbers\n%d letters\n%d symbols",e,n,a,s);
	/*
	/*
Faça um programa que valide uma senha, sendo ela composta de 6 a 12 caracteres,
contendo letras minúsculas e maiúsculas, números e símbolos. Classificar a senha
como forte (11-12 caracteres com letras minúsculas e maiúsculas, símbolos e números),
 média (8-10 letras minúsculas e números), fraca (6-7 caracteres, somente letras minúsculas)
  ou inválida (mais que 12 caracteres ou menos que 6 caracteres).

*/

/*
    int mi = 0,ma = 0,n = 0,s = 0,i,l;
    char senha[13];
    printf("\n\tDigite a senha: ");
    gets(senha);
    l = strlen(senha);
    for(i = 0; i < l; i++){
        if(senha[i] > 47 && senha[i] < 58)
            n++;
        else if(senha[i] > 64 && senha[i] < 93)
            ma++;
        else if(senha[i] > 96 && senha[i] < 123)
            mi++;
        else
            s++;
    }
    if(l < 6 || l > 12)
        printf("\n\tSenha invalida!");
    else if(l == 6 || l == 7){
        if(mi != 0)
            printf("\n\tSenha fraca!");
        else
            printf("\n\tSenha sem letras minusculas!");
    }
    else if(l == 8 || l == 10){
        if(mi != 0 && n != 0)
            printf("\n\tSenha moderada!");
        else if(n == 0 && mi == 0)
            printf("\n\tSenha sem letras minusculas e numeros!");
        else if(n != 0)
            printf("\n\tSenha sem letras minusculas!");
        else
            printf("\n\tSenha fraca!");
    }
    else{
        if(mi != 0 && n != 0 && ma !=0 && s != 0)
            printf("\n\tSenha forte!");
        else
            printf("\n\tSenha com tipos de caracter faltando");
    }
     */
	
	
	
    return 0;
}
