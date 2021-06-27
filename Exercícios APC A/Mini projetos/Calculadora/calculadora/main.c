//Henrique Sartori Siqueira RA - 19240472

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float x, y, z;
    char o;



    printf("\n Insira os valores com a operacao entre os valores = ");
    scanf("%f%c%f", &x, &o, &y);
    while (o != '='){
    if(o == '+'){ // Para adição
    z = x + y;
    printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
    }
    else{
        if(o == '-'){ // Para subtração
            z = x - y;
            printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
        }
            else{
                if(o == '*'){ // Para multiplicação
                    z = x * y;
                    printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
                }
                else{ // Para finalizar programa
                    if(o == '='){
                        printf("\n Fim de programa");
                      }
                }
            }
    }
  if((x == 0 || y == 0) && o != '='){ // Validação de divisão
        printf("\n divisao por zero!");
    }
    else{
        if(o == '/'){ // Para divisão
            z = x / y;
            printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
            }
    }
    if((x<=0 || y<=0) && o == '^'){ // Validação de potenciação
        printf("\n Numeros invalidos");
    }
    else{
    if(o == '^'){ // Para potenciação
        z = pow(x,y);
        printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
    }
    }
    }

    return 0;
}
