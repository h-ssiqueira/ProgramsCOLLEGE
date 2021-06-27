#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10

int main(){
    float xi[n],yi[n],somax1=0,somay1=0,x2i[n],y2i[n],somax2i=0,somay2i=0,xy[n],somaxy=0;
    for(int i=0;i<n;i++){
		printf("\nXi[%d]: ",i+1);
		scanf("%f",&xi[i]);
		printf("Yi[%d]: ",i+1);
		scanf("%f",&yi[i]);

		somax1+=xi[i];
		somay1+=yi[i];

		x2i[i]=pow(xi[i],2);
		y2i[i]=pow(yi[i],2);

		somax2i += x2i[i];
		somay2i += y2i[i];

		xy[i]=xi[i]*yi[i];

		somaxy+=xy[i];
    }
    system("clear");
    printf("Xi\t\tYi\t\tX2i\t\tY2i\t\tXY\n");
    for(int i=0;i<n;i++)
		printf("%f\t%f\t%f\t%f\t%f\n",xi[i],yi[i],x2i[i],y2i[i],xy[i]);

    printf("\n\n%f\t%f\t%f\t%f\t%f\n",somax1,somay1,somax2i,somay2i,somaxy);
    //system("pause");

    float A,B;
    B=((n*somaxy)- (somax1*somay1))/((n*somax2i)-pow(somax1,2));

    A=(somay1-(B*somax1))/n;

    printf("\n\nB=%f\nA=%f\n",B,A);

    //system("pause");
	//getchar();

    float auxy,yny[n],yny2[n],somayny2=0;
    for(int i=0;i<n;i++){
        auxy=A+B*xi[i];
        yny[i]=yi[i]-auxy;
        yny2[i]=pow(yny[i],2);
        somayny2+=yny2[i];
    }
    printf("Y-^y\t\tY-^y2\n");
    for(int i=0;i<n;i++)
        printf("%f\t%f\n",yny[i],yny2[i]);

    printf("\n\t\t%f\n",somayny2);

    //system("pause");
	//getchar();

    float dA,dB;

    dB = sqrt((n*somayny2)/((n-2)*((n*somax2i)-pow(somax1,2))));

    dA = sqrt((somayny2/n*(n-2))*(1+(pow(somax1,2)/((n*somax2i)-pow(somax1,2)))));

    printf("\ndB=%lf\ndA=%lf", dB, dA);

    return 0;
}