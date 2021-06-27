#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[11], str2[11], str3[11];
    printf("Insira a primeira string: ");
    gets(str1);
    printf("Insira a segunda string: ");
    gets(str2);
    printf("Insira a terceira string: ");
    gets(str3);

    if(strcmp(str1,str2)&&strcmp(str1,str3)<0){
        printf("%s\n", str1);
        if(strcmp(str2,str3)<0)
            printf("%s\n%s", str2,str3);
        else
            printf("%s\n%s", str3, str2);
    }
    else if(strcmp(str2,str3)&&strcmp(str2,str1)<0){
        printf("%s\n", str2);
        if(strcmp(str1,str3)<0)
            printf("%s\n%s", str1, str3);
        else
            printf("%s\n%s", str3, str1);
        }
    else if(strcmp(str3,str1)&&strcmp(str3,str2)<0){
        printf("%s", str3);
        if(strcmp(str1,str2)<0)
            printf("%s\n%s", str1, str2);
        else
            printf("%s\n%s", str2, str1);
    }





    return 0;
}
