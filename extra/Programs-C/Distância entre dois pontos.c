#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    float x1, x2, y1, y2, z1, z2, d;
    do{
        printf("\n Insira as coordenadas do primeiro ponto (x1,y1,z1), com par%cnteses e separados por v%crgulas, sem espa%cos\n p1 = ", 136, 161, 135);
        scanf("(%f,%f,%f)", &x1, &y1, &z1);
        fflush(stdin);
        printf("\n Insira as coordenadas do segundo ponto (x2,y2,z2), com par%cnteses e sepados por v%crgulas, sem espa%cos\n p2 = ", 136, 161, 135);
        scanf("(%f,%f,%f)", &x2, &y2, &z2);
        fflush(stdin);
        d=sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));

        system("cls");
        printf("\n  Dist%cncia entre (%.2f,%.2f,%.2f) e (%.2f,%.2f,%.2f) = %.3f", 131, x1, y1, z1, x2, y2, z2, d);
        printf("\n___________________________________________________________\n");
        printf("\n Insira 0 para todas as coordenadas para sair\n OU");
    }while((x1!=0||x2!=0)||(y1!=0||y2!=0)||(z1!=0||z2!=0));

    return 0;
}
