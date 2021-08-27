#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool identificaING(char *x){
    int i = 0;
    bool I=false,N=false,G=false;
    while(x[i] != 0){
        x[i] == 'i' ? (I = true) : (I && x[i] == 'n' ? (N = true) : (I && N && x[i] == 'g' ? (G = true) : (G = false,N = false,I=false)));
        if(I && N && G && x[i+1] == '\0')
            return true;
        i++;
    }
    return false;
}
int main(){
    char x[] = "piin\0";
    printf("%c", identificaING(x) ? '1':'0');
    return 0;
}