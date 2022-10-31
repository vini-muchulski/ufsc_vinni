#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void imprime_Matriz( int A[MAX][MAX], int lin, int col);

int main(){
int A[MAX][MAX] = {{1,2,3},{4,5,6}};

imprime_Matriz(A,2,3);

    return 0;
}

void imprime_Matriz( int A[MAX][MAX], int lin, int col){

    for (int i = 0; i<lin ; i++){
        for(int j = 0; j <col ; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
}