#include <stdio.h>
#include <stdlib.h>
#define tam 15

typedef struct atleta{
int matricula,idade;
float altura;
}at;

void ler(at n[]){
for(int i=0;i<tam;i++){
printf("\nInsira matricula: ");
scanf("%d",&n[i].matricula);
printf("\nInsira idade: ");
scanf("%d",&n[i].idade);
printf("\nInsira altura: ");
scanf("%f",&n[i].altura);
fflush(stdin);

}
}

float alt(at n[]){
    float aux=0;
    for(int i=0;i<tam;i++){
        aux+=n[i].altura;
    }
return (aux/tam);
}

int idd(at n[]){
    int aux=0;
    for(int i=0;i<tam;i++){
        aux+=n[i].idade;
    }
return (aux/tam);
}

int main()
{
    at n[tam];
    int medi;
    float meda;
    ler(n);
    meda=alt(n);
    medi=idd(n);
    for(int i=0;i<tam;i++){
        printf("\n\nMatricula: %d\nIdade: %d\nAltura: %.2f",n[i].matricula,n[i].idade,n[i].altura);
    }

    printf("\n\n\nMedia altura: %.3f\nMedia idade: %d",meda,medi);
    return 0;
}
