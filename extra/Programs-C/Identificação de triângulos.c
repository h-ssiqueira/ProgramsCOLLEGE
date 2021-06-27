#include <stdio.h>
#include <stdlib.h>

int main(){
    int X, Y, Z;

    printf("\n Insira um valor para X = ");
    scanf("%d", &X);

    printf("\n Insira um valor para Y = ");
    scanf("%d", &Y);

    printf("\n Insira um valor para Z = ");
    scanf("%d", &Z);



    if((X < 0) || (Y < 0) || (Z < 0) || X > (Y + Z) || Y > (X + Z) || Z > (X + Y))
        printf("\n nao se adequa ao valor de comprimento");
    else{

        if((X == Y && Y == Z) && (Z == X)){
            printf("\n Eh um triangulo equilatero");
        }

        if((X==Y && X!=Z) || (Y==Z && Y!=X)||(Z!=Y && Z==X)){
            printf("\n Eh um triangulo isosceles");
        }

        if(X != Y && Y != Z && Z != X){
            printf("\n Eh um triangulo escaleno");
        }
    }
    return 0;
}
