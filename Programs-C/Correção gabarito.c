// Alcides Gomes Beato Neto RA 19060987
// Henrique Sartori Siqueira RA 19240472
#include <stdio.h>
#include <stdlib.h>

int main(){
    char gabarito[10]= {'a','a','a','a','a','a','a','a','a','a'}, resposta[10];
    int nota, cap = 0, ca = 0, i, RA, freq[11] = {0}, maior, pos;
    float a;
    do{
        printf("Digite o RA: ");
        scanf("%d",&RA);
        if(RA == 9999)
            break;
        else{
            for(i = 0, nota = 0; i < 10; i++){
                printf("\n Insira a resposta da quest%co %d: ",198, i+1);
                fflush(stdin);
                scanf("%c", &resposta[i]);
                system("cls");
                if(resposta[i] == gabarito[i])
                    nota++;

            }
            if(nota>=5){
                cap++;
                ca++;
            }
            else
                ca++;

            freq[nota]++;

            printf("\n RA: %d. \n Nota = %d. \n", RA, nota);
            printf("_____________________________________________________ \n");
        }
    }while(RA != 9999);
    a = (float)cap / ca;
    for(maior = -1, pos = -1, i = 0; i < 11; i++){
        if(freq[i] > maior){
            maior = freq[i];
            pos = i;
        }
    }
    printf("\n Porcentagem de aprova%c%co = %.2f%%", 135, 198, a*100);
    printf("\n Maior frequ%cncia de nota %d = %d alunos. \n", 136, pos, maior);

    return 0;
}
