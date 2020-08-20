#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    int i, n, space=0, lower=0, upper=0, digit=0, num=0, alpha=0;
    printf("\n Insira o tamanho da frase/palavra = ");
    scanf("%d", &n);
    char c[n];
    fflush(stdin);
    printf("\n Insira a palavra/frase = ");
    scanf("%[^\n]s", c);

    for(i=0;i<n;i++){
    if (isspace(c[i])!=0)
        space++;
    if (islower(c[i])!=0)
        lower++;
    if (isupper(c[i])!=0)
        upper++;
    if (isdigit(c[i])!=0)
        digit++;
    if (isalnum(c[i])!=0)
        num++;
    if (isalpha(c[i])!=0)
        alpha++;
    }

    printf("\n %s", c);
    printf("\n %d spaces", space);
    printf("\n %d lowers", lower);
    printf("\n %d uppers", upper);
    printf("\n %d digits", digit);
    printf("\n %d numbers or digits", num);
    printf("\n %d alphas", alpha);

    return 0;
}
