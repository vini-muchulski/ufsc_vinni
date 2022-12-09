//Escreva um programa que contenha as seguintes funçoes que recebam uma matriz alocada dinamicamente : mostra uma matriz na tela e calcule o elemento máximo em valor absoluto.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int printa_matriz(int *mat);

int maior_elemento(int *mat);

int main(){

    int **mat;

    int m = 2,n =2;
    int i,j;
    int elemento_maximo;


    mat = (int**) malloc(n*sizeof(int*));

    // gera matriz
    for(i=0;i<n;i++){
        mat[i] = (int*)malloc(m*sizeof(int));
        for(j=0;j<m;j++){
            
            printf("Elemento [%d][%d] = \n",i,j);
            scanf("%d", &mat[i][j] );

    
        }
    }







 for(i=0; i < 2;i++){
        for(j=0; j < 2;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


 printa_matriz(mat);

 elemento_maximo = maior_elemento(mat);

 printf("maior elemento = %d", elemento_maximo);


    return 0;
}

int printa_matriz(int *mat){
    int i,j;
    for(i=0; i < 2;i++){
        for(j=0; j < 2;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

int maior_elemento(int *mat){
     int i,j;
     int maior_elemento;

    for(i=0; i < 2;i++){
        for(j=0; j < 2;j++){

            if(mat[i][j]<0){
                mat[i][j] = mat[i][j] * (-1);
            }
            if(i == 0 & j ==0){
                maior_elemento = mat[i][j];
            }
            else{
                if(mat[i][j]>maior_elemento){
                    maior_elemento = mat[i][j];
                }
            }
        }
       
    }
    return maior_elemento;
}