#include <stdio.h>
int main(int hu)
{
    int ia;
    do{
    printf("\n Insira:\n 1 para pedra.\n 2 para papel.\n 3 para tesoura.\n -> ");
    scanf("%d", &hu);
    system("cls");
    }while(hu<1||hu>3);
    srand(time(NULL));
    ia=rand()%3+1;
    if(ia==hu)
    printf("EMPATE");
    else if(ia==1){
        if(hu==2){
        printf("\n Papel vence");
        printf("\n %c%c%c%c%c%c%c\n %c     %c\n %c     %c\n %c     %c\n %c%c%c%c%c%c%c", 218,196,196,196,196,196,191,179,179,179,179,179,179,192,196,196,196,196,196,217);
        printf("\n Parab%cns", 130);
        }
        else if(hu==3){
        printf("\n Pedra vence");
        printf("\n   _______\n  /       \\\n /        /\n \\       /\n  \\     /\n   \\___/");
        printf("\n Tente novamente");
        }
    }
    else if(ia==2){
        if(hu==1){
        printf("\n Papel vence");
        printf("\n %c%c%c%c%c%c%c\n %c     %c\n %c     %c\n %c     %c\n %c%c%c%c%c%c%c", 218,196,196,196,196,196,191,179,179,179,179,179,179,192,196,196,196,196,196,217);
        printf("\n Tente novamente");
        }
        else if(hu==3){
        printf("\n Tesoura vence");
        printf("\n   \\ /\n   .X.\n   O O");
        printf("\n Parab%cns", 130);
        }
    }
    else if(ia==3){
        if(hu==1){
        printf("\n Pedra vence");
        printf("\n   _______\n  /       \\\n /        /\n \\       /\n  \\     /\n   \\___/");
        printf("\n Parab%cns", 130);
        }
        else if(hu==2){
        printf("\n Tesoura vence");
        printf("\n   \\ /\n   .X.\n   O O");
        printf("\n Tente novamente");
        }
    }

//printf("\n %c%c%c%c%c%c%c\n %c     %c\n %c     %c\n %c     %c\n %c%c%c%c%c%c%c", 218,196,196,196,196,196,191,179,179,179,179,179,179,192,196,196,196,196,196,217);
//printf("\n   \\ /\n   .X.\n   O O");
//printf("\n   _______\n  /       \\\n /        /\n \\       /\n  \\     /\n   \\___/");
    return 0;
}
