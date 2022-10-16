/* calcula qnts elementos pares tem uma matriz*/
#include <stdio.h>

int main(){

int i,j;
int cont_pares = 0;

int matriz[4][4] ={ {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};

    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matriz[i][j]%2 == 0){
                cont_pares +=1;
            }
        }
    }

printf("na matriz foram encontrasdos %d elementos pares", cont_pares);


return 0;
}