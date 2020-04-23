#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1=0, n2=1,n3, i;
    printf("%d\n%d\n", n1, n2);
    for(i=0;i<13;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    printf("%d\n",n3);
    }
    return 0;
}
