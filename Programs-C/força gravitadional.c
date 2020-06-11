#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 0.0000000000667

typedef struct {
double massa;
float x,y,z,*dis,**ver; //coordenadas, vetor de distancia [n-1], e matriz dos versores [n-1][3]
}vetor;


void info(vetor v[],int n); //coleta as informacoes de cada particula

void show(vetor v[],int n); //mostra as informacoes de cada particula

void calcular(vetor v[],int n,int p); //calcula a forca resultante relacionada a particula escolhida

vetor * libera(vetor *v,int n); //libera a memoria alocada


int main()
{
    vetor *v;
    int n,p,a;

    //coleta quantidade de particulas para alocacao
    do{
        printf("\tInsira a quantidade de part%cculas: ", 161);
        scanf("%d", &n);
        if(n < 2){
            system("cls");//system("clear");
            printf("\tErro! Tente novamente.\n\n");
        }
    }while(n < 2);
    
    v = (vetor *) malloc(n * sizeof(vetor));

    //coleta as informacoes de cada particula
    info(v,n);

    system("cls");//system("clear");
    
    //escolha de calculo da forca resultante de uma particula
    do{
        do{
            show(v,n);
            printf("\n\n\tQual part%ccula ser%c calculada a for%ca resultante?\n\t-> ",161,160,135);
            scanf("%d",&p);
            if(p <= 0 || p > n){
                system("cls");//system("clear");
                printf("\tErro! Tente novamente.\n\n");
            }
        }while(p <= 0 || p > n);
        p--; //inicia-se em 0 o contador de particulas
        calcular(v,n,p);

        printf("\n\n\n\tDeseja calcular outra part%ccula?\n\t\t1 -> Sim.\n\t\t2 -> N%co.\n\t-> ",161,198);
        scanf("%d",&a);
        system("cls");//system("clear");

    }while(a==1);

    v = libera(v,n);
    return 0;
}

void info(vetor v[],int n){
    int i,j,k;
    for(i = 0; i < n; i++){
        system("cls");//system("clear");

        do{
            printf("\tInsira a massa da part%ccula %d (kg): ",161,i+1);
            scanf("%lf",&v[i].massa);
            if(v[i].massa <= 0){
                system("cls");//system("clear");
                printf("\tErro! Tente novamente.\n\n");
            }
        }while(v[i].massa <= 0);

        printf("\n\tInsira a coordenada da part%ccula %d(x,y,z): ",161,i+1);
        scanf("%f,%f,%f",&v[i].x,&v[i].y,&v[i].z);
    }
    //calcula a distancia entre as particulas e as armazena em um vetor
    for(i = 0; i < n; i++){
        v[i].dis = (float *)malloc((n-1)*sizeof(float));
        for(j = 0, k = 0; j < n; j++){
            if(j != i){
                v[i].dis[k] = sqrt(pow(v[i].x - v[j].x,2) + pow(v[i].y - v[j].y,2) + pow(v[i].z - v[j].z,2));
                k++;
            }
        }
    }
    //calcula o versor de uma particula em relacao as demais particulas
    for(i = 0; i < n; i++){
        v[i].ver = (float **)malloc((n-1) * sizeof(float));
        for(j = 0,k = 0; j < n; j++){
            v[i].ver[k] = (float *)malloc(3 * sizeof(float));
            if(j != i){
                v[i].ver[k][0] = (v[j].x - v[i].x) / v[i].dis[k];//X
                v[i].ver[k][1] = (v[j].y - v[i].y) / v[i].dis[k];//Y
                v[i].ver[k][2] = (v[j].z - v[i].z) / v[i].dis[k];//Z
                k++;
            }
        }
        
    }
}

void show(vetor v[],int n){
    int i,j,k;

    //barra superior da tabela
    printf("\t");
    for(i = 0;i < 70;i++)
        printf("_");

    printf("\n\t|Vetor\t\tMassa\t\tCoordenada                           |");
    
    //mostra as informacoes de cada particula
    for(i = 0;i < n;i++){
        printf("\n\t|");

        for(j = 0;j < 68;j++) //linha em branco da tabela
            printf(" ");

        printf("|\n\t| P%d\t%17.2lf\t%8.3f i, %8.3f j, %8.3f k   |",i+1,v[i].massa,v[i].x,v[i].y,v[i].z);
    }
    printf("\n\t|");

    //linha inferior da tabela
    for(i = 0;i < 68;i++)
        printf("_");
    printf("|");

    //linha superior da tabela
    printf("\n\n\t___________");
    for(i = 0; i < n; i++)
        printf("__________");

    //titulo de cada coluna
    printf("\n\t|Dist%cncia |",131);
    for(i = 0; i < n; i++)
        printf("   P%2.d   |",i+1);

    //informacoes de cada linha
    for(i = 0; i < n; i++){
        printf("\n\t|    P%2.d   |",i+1);

        for(j = 0,k = 0; j < n; j++)
            i != j ? printf(" %8.3f|",v[i].dis[k]), k++ : printf("    -    |");
    }
    //linha inferior da tabela
    printf("\n\t|__________|");
    for(i = 0; i < n; i++)
        printf("_________|");
}

void calcular(vetor v[],int n,int p){
    double res,total = 0;
    int i,j,k;
    float x,y,z,xt = 0,yt = 0,zt = 0;

    //linha superior da tabela
    printf("\n\n\t%c",218);

    for(i = 0; i < 67; i++)
        printf("%c",196);

    printf("%c",191);
    //titulo de cada coluna
    printf("\n\t%cPonto\tM%cdulo For%ca resultante\t\tFor%ca resultante\t    %c\n\t%c",179,162,135,135,179,179);
    
    //linha em branco
    for(j = 0;j < 67;j++)
        printf(" ");

    printf("%c",179);
    //forca relativa a duas particulas em cada linha
    for(i = 0,j = 0; i < n; i++){
        if(p != i){
            res = -(G * v[p].massa * v[i].massa) / pow(v[p].dis[j],2); //calculo do modulo da forca
            
            //calculo da forca vetorialmente
            x = -res * v[p].ver[j][0];
            y = -res * v[p].ver[j][1];
            z = -res * v[p].ver[j][2];
            
            xt += x;
            yt += y;
            zt += z;
            
            printf("\n\t%cF%d;%d\t%.15lf\t%8.3f i, %8.3f j, %8.3f k  %c\n\t%c",179,p+1,i+1,res,x,y,z,179,179);
            //linha em branco
            for(k = 0;k < 67;k++)
                printf(" ");

            printf("%c",179);
            total += res;
            j++;
        }
    }
    //linha inferior da tabela
    printf("\n\t%c",192);
    for(i = 0; i < 67; i++)
        printf("%c",196);

    printf("%c",217);
    //informacoes da forca e coordenada resultante
    printf("\n\n\tM%cdulo da for%ca resultante total = %.15lf",162,135,total);
    printf("\n\tFor%ca resultante total:\n\t %.8f i\n\t %.8f j\n\t %.8f k",135,xt,yt,zt);
}

vetor * libera(vetor *v,int n){
    for(int i = 0; i < n;i++){
        free(v[i].dis); //desaloca a distancia entre duas particulas
        for(int j = 0; j < n-1; j++) //desaloca a matriz de versores
            free(v[i].ver[j]); //desaloca o vetor de coordenadas do versor
        free(v[i].ver); //desaloca o vetor de particulas que armazenava as coordenadas do versor
    }
    free(v); //desaloca o vetor de estruturas das particulas
    return NULL;
}
