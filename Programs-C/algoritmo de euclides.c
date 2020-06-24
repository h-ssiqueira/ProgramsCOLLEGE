#include <stdio.h>

int MDCr(int x, int y){
    if(y == 0)
        return x;
    return MDCr(y, x % y);
}

int MDCi(int x, int y){
    int r;
    while(y != 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}


int main(){
    int x = 24, y = 30;
    printf("MDC %d && %d = %d\n", x, y, MDCr(x, y));
    printf("MDC %d && %d = %d\n", x, y, MDCi(x, y));
    return 0;
}
