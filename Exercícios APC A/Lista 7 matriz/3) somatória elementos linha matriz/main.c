#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[2][3], s=0, n, m, k;
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf("\n Insira um valor para [%d][%d] = ", n, m);
        scanf("%d", &x[n][m]);
        fflush(stdin);
        }
    }
    printf("\n Insira a linha a ser somado os valores = ");
    scanf("%d", &k);
    for(n=0;n<2;n++){
            if(k==n){
        for(m=0;m<3;m++){
            s+=x[n][m];
        }
            }
    }
    printf("\n X = \t");
      for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf(" %5d ", x[n][m]);
        }
        printf("\n\t");
    }
printf("\n Soma da %d%c linha = %d", k, 166, s);
    return 0;
}
