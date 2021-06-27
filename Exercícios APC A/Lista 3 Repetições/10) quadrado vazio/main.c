#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1, y;

    do{
        printf("\n Insira um valor entre 1 e 20 = ");
        scanf("%d", &y);
    }while(y<0 && y>21);

       while(i<=y)
        {
            printf("*");
            i++;
        }
        printf("\n");

        i=1;
        while(i <= y*(y-2))
        {
            if(i%y == 1)
                printf("*");
            else
                if(i%y == 0)
                    printf("*\n");
                else
                    printf(" ");

            i++;
        }

        i=1;
        while(i<=y)
        {
            printf("*");
            i++;
        }
        printf("\n");




    return 0;
}
