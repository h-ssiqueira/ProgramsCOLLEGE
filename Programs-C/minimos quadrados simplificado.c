#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10

int main(){
    double xi[]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0},
	yi[]={0.000425,0.000850,0.001280,0.001700,0.002130,0.002550,0.002980,0.003400,0.003830,0.004250},
	somax1 = 0, somay1 = 0, mediax = 0, somamed = 0, resultmed = 0, mediay = 0;
    for(int i = 0; i < n; i++){
		somax1 += xi[i];
		somay1 += yi[i];
    }
    printf("\n\tSomaX = %.10lf m\n\tSomaY = %.10lf ohm", somax1,somay1);
    mediax = somax1 / n;
	mediay = somay1 / n;
	printf("\n\tMediaX = %.10lf m\n\tMediaY = %.10lf ohm", mediax,mediay);
	for(int i = 0; i < n; i++){
		somamed +=(xi[i]-mediax)*yi[i];
		resultmed += pow((xi[i]-mediax),2);
	}
	printf("\n\t(X - MediaX) * Y = %.10lf ohm * m\n\t(X - MediaX)**2 = %.10lf m**2\n",somamed, resultmed);
	printf("\n\tA = %.10lf ohm / m",somamed/resultmed);
	printf("\n\tB = %.10lf ohm",mediay-((somamed/resultmed)*mediax));
	printf("\n\ty = Ax + B\n\ty = %10lfx + %10lf\n\n", somamed/resultmed,(mediay-((somamed/resultmed)*mediax)));
  
    return 0;
}
