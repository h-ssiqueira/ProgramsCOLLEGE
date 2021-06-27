#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[2][3], y[3][2], m, n, i, j;
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
            printf("\n Insira um valor para [%d][%d] = ", n, m);
            scanf("%d", &x[n][m]);
        }
    }
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
            y[m][n]=x[n][m];
        }
    }
    printf("\n X = \t");
    for(n=0;n<2;n++){
        for(m=0;m<3;m++){
            printf(" %d ", x[n][m]);
        }
        printf("\n\t");
    }
    printf("\n Y = \t");
    for(n=0;n<3;n++){
        for(m=0;m<2;m++){
            printf(" %d ", y[n][m]);
        }
        printf("\n\t");
    }
    return 0;
}
