#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale (LC_ALL,"portuguese");
    int a=5,b=7,*p1=&a,*p2=&b,**p3=&p1;
    *p1=(*p2)*3;
    b+=4;
    a-=2;
    *p2+a;

    printf("Valor de a = %d\n",a);
    printf("Endere�o de a = %d\n",&a);
    printf("Conte�do de p1 = %d\n",*p1);
    printf("Valor de p1 = %d\n",p1);
    printf("Endere�o de p1 = %d\n",&p1);
    printf("Informa��o de p3 = %d\n",*(*p3));
    printf("Conte�do de p3 = %d\n",*p3);
    printf("Valor de p3 = %d\n",p3);
    printf("Endere�o de p3 = %d",&p3);
    return 0;
}
