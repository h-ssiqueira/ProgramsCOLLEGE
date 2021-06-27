#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[2][3], y[2], n, m, k;
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf("\n Insira um valor para [%d][%d] = ", n, m);
        scanf("%d", &x[n][m]);
        fflush(stdin);
        }
    }
    printf("\n Insira a coluna a ser criado o vetor = ");
    scanf("%d", &k);
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
            if(k==m)
                y[n]=x[n][m];
        }
    }
    printf("\n X = \t");
      for(n=0;n<2;n++){
        for(m=0;m<3;m++){
        printf(" %5d ", x[n][m]);
        }
        printf("\n\t");
    }
printf("\n Vetor da %d%c coluna = ", k, 166);

    for(m=0;m<2;m++)
printf(" %3d ", y[m]);
    return 0;
}
