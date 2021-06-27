#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int n,i;
    float v1[11],v2[11],v3[11],som1=0,som2=0,som3=0,med1,med2,med3,s2,s,err;
    printf("Digite um valor para n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nDigite um valor:");
        scanf("%f",&v1[i]);
    }
    for(i=0;i<n;i++)
        som1+=v1[i];
    med1=som1/n;
    for(i=0;i<n;i++){
        v2[i]=v1[i]-med1;
        if(v2[i]<0)
            v2[i]=v2[i]-2*v2[i];
    }
    for(i=0;i<n;i++)
        som2+=v2[i];
    med2=som2/n;
    for(i=0;i<n;i++)
        v3[i]=pow(v2[i],2);
    for(i=0;i<n;i++)
        som3+=v3[i];
    med3=som3/n;
    s2=som3/(n-1);
    s=sqrt(s2);
    err=s/sqrt(n);
    system("cls");
    printf("\n");
    for(i=0;i<n+1;i++){
        if(i!=n)
            printf("   %d  | %.4f | %.4f | %.4f \n",i+1,v1[i],v2[i],v3[i]);
        else
            printf(" SOMA | %.4f | %.4f | %.4f \n\n",som1,som2,som3);
    }
    printf("C�lculo da M�dia: %.4f\n\n",med1);
    printf("C�lculo do Desvio Absoluto M�dio: %.4f\n\n",med2);
    printf("C�lculo do Desvio-Quadratico M�dio: %.4f\n\n",med3);
    printf("C�lculo da Vari�ncia: %.4f\n\n",s2);
    printf("C�lculo do Desvio Padr�o: %.4f\n\n",s);
    printf("C�lculo do Erro Padr�o da M�dia: %.4f\n\n\n",err);
    return 0;
}
