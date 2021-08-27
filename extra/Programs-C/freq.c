#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void QuickSort3way(int *array, int start, int end){
	if(end > start){
		int low = start, great = end;
		int aux, piv = *(array+start), *i = array+start;
		while(i-array <= great){ // Set the pivot in the center of the array, sorting greaters and lowers values in the array comparing to pivot
			if(*i < piv){ // Compares if the value is lower than pivot
				aux = *i; // If so, change the positions of index and low
				*i = *(array+low);
				*(array+low) = aux;
				low++;
				i++;
			}
			else if(*i > piv){ // if the value is greater than pivot
				aux = *i; // if so, change the positions of index and great
				*i = *(array+great);
				*(array+great) = aux;
				great--;
			}
			else // if the value is the same as the pivot
				i++;
		}
		QuickSort3way(array, start, low-1); // Recursively change the pivot
		QuickSort3way(array, great+1, end); // To sort the other elements
	}
}

int main(){
    int arr[] = {/*Fill the array with numbers*/
7,        8,    1,     7,    13,       6,    2,     5,     3,      8,    11,    12,    12,    3,    17,    4,     7,     4,    4,    15,    2,    14,    3,      10,   8,    9,     8,     5,        2,    7,    14,    12,    10,    10,     7,     6,     2,     3,     6,     7,    5,     2,    3,    12
    };
    int length = sizeof(arr)/sizeof(int);
    QuickSort3way(arr,0,length-1);
    int min = arr[0],sum = 0,modal = 0;
    int range = arr[length-1]-min+1;
    int *freq = calloc(range,sizeof(int));
    double Median, average,variance = 0, standard_deviation, variantion, E1, E2, Q1, Q2, Q3,Pearson1,Pearson2;
    for(int *i = arr; i < arr+length; i++){
        (*(freq+*i-min))++;
        sum += *i;
    }
    printf("Sum = %d",sum);
    average = (double)sum/length;
    printf("\nLength = %d",length);
    printf("\nFrequency table:\n");
    for(int i = 0; i < range; i++){
        printf("%d -> %d\n",i+min,freq[i]);
        if(freq[i] > modal)
            modal = freq[i];
        if(freq[i] != 0)
            variance += ((i+min-average)*(i+min-average)*freq[i]);
    }
    printf("\n\n\nsum variance = %lf",variance);
    Median = length % 2 == 0 ? (arr[length/2] + arr[length/2 + 1 ]) / 2.0 : (float)arr[length/2];
    variance /= (length-1.0);
    standard_deviation = sqrt(variance);
    variantion = standard_deviation / average * 100.0;
    printf("\nAverage = %lf\n",average);
    printf("Median = %lf\n", Median);
    printf("Separatrices:\nQuartile:\n");
    for(int i = 1,j; i < 4; i++){
        j = ceil(i*length/4);
        printf("Q%d = %d\t",i,arr[j]);
        if(i == 1)
            Q1 = arr[j];
        if(i == 2)
            Q2 = arr[j];
        if(i == 3)
            Q3 = arr[j];
    }
    printf("\n\nDecile:\n");
    for(int i = 1,j; i < 10; i++){
        j = ceil(i*length/10);
        printf("D%d = %d\t",i,arr[j]);
    }
    printf("\n\nPercentile:\n");
    for(int i = 1,j; i < 100; i++){
        j = ceil(i*length/100);
        printf("P%d = %d\t",i,arr[j]);
    }
    printf("\n\nVariance: %lf", variance);
    printf("\n\nStandard Deviation: %lf", standard_deviation);
    printf("\n\nVariation: %.3lf%%", variantion);
    E1 = Q1 - 1.5*(Q3-Q1);
    E2 = Q3 + 1.5*(Q3-Q1);
    printf("\nOutliers\nE1 = %lf\nE2 = %lf",E1,E2);
    Pearson1 = (average - modal)/standard_deviation;
    Pearson2 = (Q1+Q2-Median)/(Q3-Q1);
    printf("\n1st Pearson coeficient = %lf", Pearson1);
    printf("\n2nd Pearson coeficient = %lf", Pearson2);
    free(freq);
    return 0;
}