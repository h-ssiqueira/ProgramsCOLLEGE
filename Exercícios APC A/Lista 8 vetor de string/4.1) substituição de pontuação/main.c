#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[10]={0}, y[20]={0};
    int i, j;
    printf("\n Insira alguma coisa com pontos e virgulas = ");
    scanf("%[^\n]", x);
    for(i=0, j=0;x[i]!='\0';i++, j++){
        switch (x[i]){
        case 44:
            y[j]=86;
            //j++;
            y[++j]=71;
            break;
        case 46:
            y[j]=80;
            //j++;
            y[++j]=84;
            break;
        default:
            y[j]=x[i];
            break;
    }
       /* if(x[i]==44){
        y[j]=86;
        y[++j]=71;
        }
        else if(x[i]==46){
            y[j]=80;
            y[++j]=84;
        }
        else
        y[j]=x[i];
        */
    }
    printf("\n %s \n %s", x, y);
    return 0;
}
