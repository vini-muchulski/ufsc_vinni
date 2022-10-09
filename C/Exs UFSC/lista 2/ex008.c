/*• criar uma matriz A (4x4)
• achar o elemento máximo dessa matriz e a sua posição*/

#include <stdio.h>

int main(){

int matriz[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

int i,j,maximo,linha,coluna;

for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        if (i==0 && j ==0){
            maximo = matriz[i][j];
            linha = i;
            coluna = j;
        }
        else{
            if(matriz[i][j]>maximo){
                maximo = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }

    }
}

for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf(" %d  ", matriz[i][j]);
    }
    printf("\n");
}

printf("Valor maximo %d - Linha %d Coluna %d",maximo,linha,coluna);
    return 0;
}