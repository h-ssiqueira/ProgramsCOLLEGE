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
    if(o == '+'){ // Para adi��o
    z = x + y;
    printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
    }
    else{
        if(o == '-'){ // Para subtra��o
            z = x - y;
            printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
        }
            else{
                if(o == '*'){ // Para multiplica��o
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
  if((x == 0 || y == 0) && o != '='){ // Valida��o de divis�o
        printf("\n divisao por zero!");
    }
    else{
        if(o == '/'){ // Para divis�o
            z = x / y;
            printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
            }
    }
    if((x<=0 || y<=0) && o == '^'){ // Valida��o de potencia��o
        printf("\n Numeros invalidos");
    }
    else{
    if(o == '^'){ // Para potencia��o
        z = pow(x,y);
        printf("\n %.2f %c %.2f = %.2f", x, o, y, z);
    }
    }
    }

    return 0;
}
