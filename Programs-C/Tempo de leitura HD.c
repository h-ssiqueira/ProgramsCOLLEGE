#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Todos os valores em ms
int main(){
    float TL, seek, lag, BTT, t, by, trilhas, setor, arm, spb, st, rpm;

    printf("\n Insira a quantidade de trilhas e setores por trilha (trilhas,setor) = ");
    scanf("%f,%f", &trilhas, &setor);
    printf("\n Insira a quantidade de bytes por setor = ");
    scanf("%f", &by);
    printf("\n Insira a quantidade de setores por bloco = ");
    scanf("%f", &spb);
    arm=(by*trilhas*setor)/pow(10,9);

    printf("\n Insira o valor de rota%c%ces por minuto = ", 135, 228);
    scanf("%f", &rpm);

    lag=(60000*0.5)/rpm;

    printf("\n Insira a trilha que o arquivo se encontra = ");
    scanf("%f", &t);

    seek=(0.2+0.001*t);

    printf("\n Insira o valor do BTT(ms) = ");
    scanf("%f", &BTT);
    printf("\n Insira o %cltimo setor ocupado pelo arquivo = ", 163);
    scanf("%f", &st);

    TL=seek+lag+BTT*((int)(st/spb)+1);

    printf("\n Armazenamento = %.2f GB", arm);
    printf("\n Tempo de seek = %.3f ms\n Tempo de meia rota%c%co(lat%cncia) = %.3f ms", seek, 135, 198, 136, lag);
    printf("\n Tempo de btt = %.3f ms", BTT*((int)(st/spb)+1));
    printf("\n Tempo de leitura = %.3f ms", TL);

    return 0;
}
