#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30

int palindrome(char correct[],int length,int count){
    if(length<=count) return 1;
        else if(correct[length]==correct[count])
                return palindrome(correct,--length,++count);
                    else return 0;
}

int main()
{
    int length,count=0,i,j;
    char phrase[max],correct[max]={0};

    printf("Insert your string: ");
    gets(phrase);
    fflush(stdin);
    strupr(phrase);

    for(i=0,j=0;i<max;i++){
        if(phrase[i] >= 65 && phrase[i] <= 90)
            correct[j++] = phrase[i];
    }

    length = strlen(correct);

    if(palindrome(correct,--length,count)==1)
        printf("'%s' is a palindrome",phrase);
    else
        printf("'%s' is not a palindrome");

    return 0;
}
