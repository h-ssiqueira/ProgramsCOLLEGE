#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale (LC_ALL,"portuguese");
    int n, c, i;

    do{
    printf("\n Insira um número maior que 2: ");
    scanf("%d", &n);
     for(i=2, c=0;i<=n/2;i++){
        if(n%i==0){
        c++;
        break;
        }
    }c==0?
    printf("\n Número primo"):


    printf("\n Número não primo");
    }while(n>2);



   // printf("\n Insira um número maior que 2: ");
    //scanf("%d", &n);




    return 0;
}
