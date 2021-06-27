#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 3

struct aluno{
char nome[25];
float altura;
float peso;
};

void ler(struct aluno v[]){
for(int i=0;i<max;i++){
    printf("\nInsira nome do aluno %d: ",i+1);
    gets(v[i].nome);
    fflush(stdin);
    printf("\nInsira altura do aluno %d: ",i+1);
    scanf("%f",v[i].altura);
    fflush(stdin);
    printf("\nInsira peso do aluno %d: ",i+1);
    scanf("%f",&v[i].peso);
    fflush(stdin);

}

}

int ma_altura(struct aluno v[]){
    int x=0;

    for(int i=0;i<max;i++){
        if(v[i].altura>v[x].altura)
            x=i;
    }
return x;
}

int me_peso(struct aluno v[]){
int p=0;

for(int i=0;i<max;i++){
    if(v[i].peso<v[p].peso)
    p=i;
}
return p;
}

int imc(struct aluno v[],int *meimc){
float imc[max];
int maior=0;
for(int i=0;i<max;i++){
    imc[i] = v[i].peso / pow(v[i].altura,2);
    if(imc[i]>imc[maior]) maior=i;
    if(imc[i]<imc[*meimc]) *meimc=i;
}

return maior;
}

int main()
{
    struct aluno v[max];
    int a,p,maimc,meimc=0;
    ler(v);
    system("cls");
    a = ma_altura(v);
    p = me_peso(v);
    maimc = imc(v,&meimc);
    printf("%s foi o aluno(a) com maior altura\n",v[a].nome);
    printf("%s foi o aluno(a) com menor peso\n",v[p].nome);
    printf("%s foi o aluno(a) com menor imc\n",v[meimc].nome);
    printf("%s foi o aluno(a) com maior imc",v[maimc].nome);
    return 0;
}
