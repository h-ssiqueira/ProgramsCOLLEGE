#include <stdio.h>
#include <stdlib.h>

int main(){

    float op1, op2, res;
    char opc;
    //printf("\n Criado por Henrique Sartori Siqueira. Copyright © 2019 Henrique Sartori Siqueira. Todos os direitos reservados. \n \n");

    printf("\n Coloque numero operando numero ou 0=0 para finalizar = ");
    scanf("%f%c%f", &op1,&opc,&op2);
    while(opc != '='){
        switch (opc){
        case '+':
            res = op1 + op2;
            printf("\n %.2f%c%.2f=%.2f \n", op1, opc, op2, res);
            break;
        case '*':
            res = op1 * op2;
            printf("\n %.2f%c%.2f=%.2f \n", op1, opc, op2, res);
            break;
        case '-':
            res = op1 - op2;
            printf("\n %.2f%c%.2f=%.2f \n", op1, opc, op2, res);
            break;
        case '/':
            if(op2 == 0){
                printf("\n operacao invalida \n");
                return 0;
            }
            res = op1 / op2;
            printf("\n %.2f%c%.2f=%.2f \n", op1, opc, op2, res);
            break;
        case '=':
            printf("\n finalizacao de programa \n");
            return 0;
            break;
        case '^':
            res = pow(op1,op2);
            printf("\n %.2f%c%.2f=%.2f \n", op1, opc, op2, res);
            break;
        default:
            printf("\n operacao invalida \n");
        }
        printf("\n Coloque numero operando numero ou 0=0 para finalizar = ");
        scanf("%f%c%f", &op1,&opc,&op2);
    }
    return 0;
}
