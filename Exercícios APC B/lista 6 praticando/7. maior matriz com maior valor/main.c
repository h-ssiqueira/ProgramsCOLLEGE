#include <stdio.h>
#include <stdlib.h>
#define n 20

void ler(int m[][n]){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        printf("Insira um valor para [%d][%d]: ",i,j);
        scanf("%d",&m[i][j]);
        }
    }
}

void maior(int a[][n],int b[][n],int c[][n]){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]>b[i][j]) c[i][j]=a[i][j];
        else c[i][j]=b[i][j];
    }
}

}

int main()
{
    int a[n][n],b[n][n],c[n][n],i,j;
    ler(a);
    ler(b);

    maior(a,b,c);
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf(" %d ", a[i][j]);
        }
    }
    printf("\n\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf(" %d ", b[i][j]);
        }
    }
    printf("\n\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf(" %d ", c[i][j]);
        }
    }

    return 0;
}
