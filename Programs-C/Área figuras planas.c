#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
#define R3 1.73
int main()
{
    float L, B, H, R, b, D, d;
    int x, y;

    do{
        printf("\n Insira: \n 0 para finalizar o programa. \n 1 para quadrado. \n 2 para ret%cngulo/paralelogramo. \n 3 para tri%cngulo. \n 4 para trap%czio. \n 5 para c%crculo. \n 6 para losango. \n -> ", 131, 131, 130, 161);
        scanf("%d", &x);
        system("cls");
        switch(x){
    case 0:
    break;

    case 1:
        printf("\n Insira o valor do lado do quadrado = ");
        scanf("%f", &L);
        printf("\n %crea do quadrado = %.3f \n Per%cmetro do quadrado = %.3f", 181, pow(L,2), 161, 4*L);
    break;

    case 2:
        printf("\n Insira a base do ret%cngulo/paralelogramo = ", 131);
        scanf("%f", &B);
        printf("\n Insira a altura do ret%cngulo/peralelogramo = ", 131);
        scanf("%f", &H);
        printf("\n %crea do ret%cngulo/paralelogramo = %.3f \n Per%cmetro do ret%cngulo/paralelogramo = %.3f", 181, 131, B*H, 161, 131, (2*B)+(2*H));
    break;

    case 3:
        printf("\n Insira 1 para tri%cngulo regular. \n Insira 2 para tri%cngulo equil%ctero.\n -> ", 131, 131, 160);
        scanf("%d", &y);
        if(y==1){
        printf("\n Insira a base do tri%cngulo = ", 131);
        scanf("%f", &B);
        printf("\n Insira a altura do tria%cngulo = ", 131);
        scanf("%f", &H);
        printf("\n %crea do tri%cngulo = %.3f", 181, 131, B*H/2);
        }else if(y==2){
        printf("\n Insira o lado do tri%cngulo = ", 131);
        scanf("%f", &L);
        printf("\n %crea do tri%cngulo = %.3f", 181, 131, (R3/4)*pow(L,2));
        }
    break;

    case 4:
        printf("\n Insira a base maior do trap%czio = ", 130);
        scanf("%f", &B);
        printf("\n Insira a base menor do trap%czio = ", 130);
        scanf("%f", &b);
        printf("\n Insira a altura do trap%czio = ", 130);
        scanf("%f", &H);
        printf("\n %crea do trap%czio = %.3f", 181, 130, ((B+b)*H)/2);
    break;

    case 5:
        printf("\n Insira o raio da circunfer%cncia = ", 136);
        scanf("%f", &R);
        printf("\n %crea da circunfer%cncia = %.3f \n Per%cmetro da circunfer%cncia = %.3f", 181, 136, PI*pow(R,2), 161, 136, 2*PI*R);
    break;

    case 6:
        printf("\n Insira a diagonal maior = ");
        scanf("%f", &D);
        printf("\n Insira a diagonal menor = ");
        scanf("%f", &d);
        printf("\n %crea do losango = %.3f", 181, d*D/2);
    break;

        }//switch

    printf("\n_______________________________________________________________________\n");

    }while(x>0 && x<7);
    return 0;
}
