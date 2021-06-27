#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5
int main()
{
    setlocale (LC_ALL,"portuguese");
    int v[tam], i, pmaior=0, vmenor=0, r3=0;

    for(i=0;i<tam;i++){
    printf("Insira um valor para v[%d]: ", i);
    scanf("%d", &v[i]);
    if(v[i]>v[pmaior])
    pmaior=i;
    if(v[i]<v[vmenor])
    vmenor=i;
    if(v[i]%7==3)
    r3++;
    }
    system("cls");
    printf("Posição do maior elemento: %d\nValor do menor elemento: %d\nNúmero de elementos com resto 3 pela divisão por 7: %d", pmaior, v[vmenor], r3);



    return 0;
}
