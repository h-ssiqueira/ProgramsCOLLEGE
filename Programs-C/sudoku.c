#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool line(int m[][9],int i){
    for(int j = 0; j < 9; j++)
        for(int k = 0; k < 9; k++)
            if(m[i][j] == m[i][k] && j != k)
                return false;
    return true;
}

bool colunm(int m[][9],int i){
    for(int j = 0; j < 9; j++)
        for(int k = 0; k < 9; k++)
            if(m[j][i] == m[k][i] && j != k)
                return false;
    return true;
}

bool square(int m[][9], int i, int j){
    int a, b, c, d;
    for(a = i; a < i+3; a++)
        for(b = j; b < j+3; b++)
            for(c = i; c < i+3; c++)
                for(d = j; d < j+3; d++)
                    if(m[a][b] == m[c][d] && a != c && b != d)
                        return false;
    return true;
}


int main(){
    bool conf[27],check = true;
    int i,j,k,m[9][9]={
        {3,5,2,9,1,8,6,7,4},{8,9,7,2,4,6,5,1,3},{6,4,1,7,5,3,2,8,9},
        {7,8,3,5,6,9,4,2,1},{9,2,6,1,3,4,7,5,8},{4,1,5,8,2,7,9,3,6},
        {1,6,4,3,7,5,8,9,2},{2,7,8,4,9,1,3,6,5},{5,3,9,6,8,2,1,4,7}};

    /*
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            do{
                printf("\nInsert a value for %dx%d: ",i+1,j+1);
                scanf("%d",&m[i][j]);
            }while(m[i][j] < 1 || m[i][j] > 9);
        }
    }
    */

    for(i = 0, k = 0; i < 9; i++, k++) // Check lines
        conf[k] = line(m,i);
    for(j = 0; j < 9; j++, i++, k++) // Check colunms
        conf[k] = colunm(m,i);
    for(i = 0; i < 9; i += 3)
        for(j = 0; j < 9; j += 3, k++) // Check squares
            conf[k] = square(m,i,j);
    
    
    for(i = 0; i < 27; i++){
        if(conf[i] == false && i < 9){ // 0-8 lines
            printf("\n\tMistake on line: %d", i+1);
            check = false;
        }
        else if(conf[i] == false && i < 18){ // 9 - 17 colunms
            printf("\n\tMistake on colunm: %d", i-8);
            check = false;
        }
        else if(conf[i] == false && i < 27){ // 18-26 squares
            printf("\n\tMistake on square: %d", i-17);
            check = false;
        }
    }
    check == true ? printf("\n\tValid sudoku table") : printf("\n\tNot valid sudoku table");
    return 0;
}
