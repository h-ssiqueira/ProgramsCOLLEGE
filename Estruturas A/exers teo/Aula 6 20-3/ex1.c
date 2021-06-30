#include<stdio.h>
#include<stdlib.h>
#include"PILHA_FILA.h"

int main()
{
Pilha *um, *dois; int a;
Fila * F1,* F2;
um=CriaPilha();
dois= CriaPilha ();
F1 = CriaFila();
F2= CriaFila();
push(um,1);//           1

push(dois,3);//         3

push(um,4);//           4   1

push(dois,5);//         5   3

push(um,6);//           6   4   1

push(dois,7);//         7   5   3


insereFila(F1,4);//     4
insereFila(F1,6);//     4   6      
insereFila(F1,9);//     4   6   9
insereFila(F1,14);//    4   6   9   14  


insereFila(F2,16);//    16        
insereFila(F2,19);//    16  19      
insereFila(F2,41);//    16  19  41  
insereFila(F2,12);//    16  19  41  12

insereFila(F2,pop(um));//   um = 4  1
                        //  F2 = 16  19  41  12  6

insereFila (F1,retiraFila(F2));//   F2 = 19  41  12  6
//                                  F1 = 4  6   9   14  16

push(dois,retiraFila(F2));//   F2 = 41  12  6
//                                  dois = 19   7   5   3

push(dois,retiraFila(F1));//        F1 = 6   9   14  16
//                                  dois = 4   19   7   5   3

push(um,pop(dois));//       dois = 19   7   5   3
//                          um = 4  4  1

insereFila(F1, retiraFila(F2)); //  F2 = 12  6
//                                  F1 = 6   9   14  16   41


LiberaFila(F1);
LiberaFila(F2);
LiberaPilha(um);
LiberaPilha(dois);
return 0;

}
