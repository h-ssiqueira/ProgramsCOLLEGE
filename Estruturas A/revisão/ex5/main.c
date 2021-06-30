#include <stdio.h>
#include <stdlib.h>

int MDC(int n1,int n2,int var);

int main()
{
    int n1,n2,var;
    printf("\tInsira o primeiro valor: ");
    scanf("%d",&n1);
    printf("\tInsira o segundo valor: ");
    scanf("%d",&n2);
    if(n2>n1){
        n1=n1^n2;
        n2=n1^n2;
        n1=n1^n2;
    }
    var = n2;
    printf("\tMDC entre %d e %d = %d",n1,n2,MDC(n1,n2,var));
    return 0;
}

int MDC(int n1,int n2,int var){
if(n1 % var == 0 && n2 % var == 0)
    return var;

return MDC(n1,n2,var-1);
}


///int mdc(int dividendo,int divisor){
///    if(divisor == 0)
///        return divisor;
///    return(divisor,dividendo%divisor);
///}

