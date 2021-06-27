#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[10]={0};
    int i;
    printf("\n Insira alguma coisa com pontos e virgulas = ");
    scanf("%s", x);
    for(i=0;i!='\0';i++){
            switch (x[i]){
        case ',':
            x[i]=86;
            x[++i]=71;
            break;
        case '.':
            x[i]=80;
            x[++i]=84;
            break;
        default:break;
        }
    }
    printf("\n %s ", x);
    return 0;
}
