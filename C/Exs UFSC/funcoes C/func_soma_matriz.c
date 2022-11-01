#include <stdio.h>
#include <stdlib.h>

#define i 3
#define j 3

#define m 3
#define n 3


int soma_matriz(int a[i][j], int b[m][n]);



int main(){

int x,y;



int aa[i][j] = {{1,0,1},{1,1,1},{1,1,1}};

int bb[i][j] = {{2,2,2},{2,2,2},{2,2,2}};

int c[i][j] = {0};

//soma_matriz(a[i][j],b[i][j]);


        for( x=0;x<i;x++){
            for( y=0;y<j;y++){
                c[x][y] = aa[x][y]+bb[x][y];
                printf("%d ", c[x][y] );
            
        }
        printf("\n");

        }

    


    return 0;
}


int soma_matriz(int a[i][j], int b[m][n]){
    int x,y;
    int c[i][j];

    // verifica se as matrizes tem o msm tamanho e soma elas
    if ( i == m && j ==n){
        for( x=0;x<i;x++){
            for( y=0;y<j;y++){
                c[i][j] = a[i][j]+b[i][j];
                printf("%d ", c[i][j] );
            
        }
        printf("\n");

        }

    }
    else{
        printf("As matrizes devem ter o msm tamanho");
    }



}
