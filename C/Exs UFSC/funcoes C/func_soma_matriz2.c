#include <stdio.h>
#include <stdlib.h>

#define i 3
#define j 3

#define m 3
#define n 3


int soma_matriz(int a[i][j], int b[m][n]);



int main(){

int x,y;



int a[i][j] = {{0,4,1},{1,1,1},{1,1,1}};

int b[i][j] = {{2,2,2},{2,2,2},{2,2,2}};



soma_matriz(a,b);



    return 0;
}


int soma_matriz(int a[i][j], int b[m][n]){
    int x,y;
    int c[i][j];

    // verifica se as matrizes tem o msm tamanho e soma elas
    
        for( x=0;x<i;x++){
            for( y=0;y<j;y++){
                c[x][y] = a[x][y]+b[x][y];
                printf("%d ", c[x][y] );
            
        }
        printf("\n");

        }

    


}
