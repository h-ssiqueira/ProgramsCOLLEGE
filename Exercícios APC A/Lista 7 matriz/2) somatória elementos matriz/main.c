#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[2][3], i=0, n, m;
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf("\n Insira um valor para [%d][%d] = ", n, m);
        scanf("%d", &x[n][m]);
        fflush(stdin);
        }
    }
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
            i+=x[n][m];
        }
    }
    printf("\n X = \t");
      for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf(" %d ", x[n][m]);
        }
        printf("\n\t");
    }
printf("\n Soma = %d", i);
    return 0;
}
