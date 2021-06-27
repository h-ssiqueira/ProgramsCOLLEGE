#include <stdio.h>
#include <stdlib.h>
#define tam 5

int coluna(int m[][tam]){
int c=0,aux,i,j;

for(i=0;i<tam;i++){
    for(j=0,aux=0;j<tam;j++){
     if(m[j][i]==0) aux++;
    }
    if(aux==tam) c++;
}

return c;
}

int linha(int m[][tam]){
int l=0,aux,i,j;

    for(i=0;i<tam;i++){
        for(j=0,aux=0;j<tam;j++){
            if(m[i][j]==0) aux++;
        }
        if(aux==tam) l++;
}
return l;
}

int main()
{
    int m[tam][tam],i,j,ln,cn;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("Valor para [%d][%d]",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    ln=linha(m);
    cn=coluna(m);
    printf("%d linhas nulas\n%d colunas nulas",ln,cn);
    return 0;
}
