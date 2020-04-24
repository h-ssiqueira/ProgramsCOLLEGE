#include <stdio.h>
#include <math.h>
int main(){
int  x;
double J, M, C, i, n;

printf("\n Criado por Henrique Sartori Siqueira. Copyright %c 2019 Henrique Sartori Siqueira. Todos os direitos reservados. \n \n", 184);
printf("\n Bem-vindo(a) a este programa. Ele realiza o c%clculo das vari%cveis das f%crmulas dos juros compostos e simples. \n", 160, 160, 162);

        do{
printf("\n Insira 1 para juros simples. \n Insira 2 para juros compostos. \n -> ");
scanf("%d", &x);
        }while(x!=1 && x!=2);
system("cls");

//Juros simples
if(x==1){
    do{
        do{
printf("\n Juros simples. Insira: \n 0 para finalizar o programa. \n 1 para calcular o valor do juros. \n 2 para calcular o valor do capital. \n 3 para calcular a taxa de juros. \n 4 para calcular o tempo. \n -> ");
scanf("%d", &x);
        }while(x<0 && x>4);
        system("cls");
switch(x){
case 0:
    break;
case 1:
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    J = C*(i/100)*n;
    M = J+C;

    printf("\n Valor do juros: R$ %.2f. \n Valor do montante: R$ %.2f.", J, M);
    printf("\n _____________________________________________________________________ \n");
    break;
case 2:
    printf("\n Insira o valor do juros: ");
    scanf("%lf", &J);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    C = J/((i/100)*n);
    M = J+C;

    printf("\n Valor do capital: R$ %.2f. \n Valor do montante: R$ %.2f.", C, M);
    printf("\n _____________________________________________________________________ \n");
    break;
case 3:
    printf("\n Insira o valor do juros: ");
    scanf("%lf", &J);
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    i = J/(C*n);
    M = J+C;

    printf("\n Valor da taxa: %.2f%% ao m%cs. \n Valor do montante: R$ %.2f.", i*100, 136, M);
    printf("\n _____________________________________________________________________ \n");
    break;
case 4:
    printf("\n Insira o valor do juros: ");
    scanf("%lf", &J);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);

    n = J/((i/100)*C);
    M = J+C;

    printf("\n Valor do tempo: %.2f meses. \n Valor do montante: R$ %.2f.", n, M);
    printf("\n _____________________________________________________________________ \n");
    break;
        }
    }while(x!=0);

    //Juros compostos
} else if(x==2){
        do{
            do{
printf("\n Juros compostos. Insira: \n 0 para finalizar o programa. \n 1 para calcular o valor do montante. \n 2 para calcular o valor do capital. \n 3 para calcular a taxa de juros. \n 4 para calcular o tempo. \n -> ");
scanf("%d", &x);
            }while(x<0 && x>4);
            system("cls");
switch(x){
case 0:
    break;
case 1:
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    M = C * pow(1+(i/100),n);

    printf("\n Valor do montante: R$ %.2f.", M);
    printf("\n _____________________________________________________________________ \n");
    break;
case 2:
    printf("\n Insira o valor do montante: ");
    scanf("%lf", &M);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    C = M / pow(1+(i/100),n);

    printf("\n Valor do capital: R$ %.2f.", C);
    printf("\n _____________________________________________________________________ \n");
    break;
case 3:
    printf("\n Insira o valor do montante: ");
    scanf("%lf", &M);
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);
    printf("\n Insira o valor do tempo: ");
    scanf("%lf", &n);

    i = pow(M/C, 1/n) - 1;

    printf("\n Valor da taxa: %.2f%% ao m%cs. ", i*100, 136);
    printf("\n _____________________________________________________________________ \n");
    break;
case 4:
    printf("\n Insira o valor do montante: ");
    scanf("%lf", &M);
    printf("\n Insira o valor da taxa(em porcentagem): ");
    scanf("%lf", &i);
    printf("\n Insira o valor do capital: ");
    scanf("%lf", &C);

    n = (log10 (M/C) / log10 (1+(i/100)));

    printf("\n Valor do tempo: %.2f meses. ", n);
    printf("\n _____________________________________________________________________ \n");
    break;
   }
        }while(x!=0);
    }
return 0;
}
