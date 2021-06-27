#include <stdio.h>
#include <stdlib.h>

//Alcides Gomes Beato Neto 19060987
//Henrique Sartori Siqueira 19240472


int main(){
    int joao = 0, maria = 0, vb = 0,
        vn = 0, Ne, i, x = 0, senha;
    float pv = 0;

    printf("Digite o numero de eleitores:");
    scanf("%d", &Ne);
    system("cls");

    do{
        printf("\n COD \t Candidato \n 11 \t Joao \n 45 \t Maria");
        printf("\n 0 \t Voto em branco \n");

        printf("Digite seu voto:");
        scanf("%d",&i);

        if(i == 11)
            joao++;

        else if(i == 45)
            maria++;

        else if(i == 0)
            vb++;

        else if(i == 1234){
            printf("\n Digite a senha:");
            scanf("%d", &senha);
            if(senha == 3571)
                break;
        }
        else
            vn++;

        system("cls");
        x++;

    }while(x <= Ne-1);
    pv = (float)x / Ne * 100;
    printf("\n Votacao encerrada! \n\n Votos esperados: %d", Ne);
    printf("\n Total de votos: %d \n porcentagem de votos: %.3f%%", x, pv);
    printf("\n Total votos Joao: %d \n Total votos Maria: %d \n ", joao, maria);
    printf("Total votos brancos e nulos: %d \n", vb+vn);
    printf("\n COD \t Candidato \t Votos \n 11 \t Joao \t\t %d", joao);
    printf(" \n 45 \t Maria \t\t %d", maria);
    printf("\n 0 \t Brancos/Nulos \t %d \n", vb+vn);

    return 0;
}
