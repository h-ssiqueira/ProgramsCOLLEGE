
#include <stdlib.h>
#include <iostream>

using namespace std;
double pi(int n){
    double sum = 0.0;
    int sign = 1;
    for(int i = 0; i < n; ++i){
        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
    }
    return 4.0 * sum;
}
int main(int argc, char *argv[]){
    if(argc != 2)
        return 1;
    int n = atoi(argv[1]);
    cout << "Executando o programa: " << argv[0] << endl;
    cout << "- Calculando pi usando séries de Taylor; n = " << n << endl;
    cout.precision(17);
    for(int i = 0; i < n; i++)
        cout << "pi(" << i << ") = " << pi(i) << endl;
    return 0;
}

