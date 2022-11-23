#include <stdio.h>
#include <stdlib.h>

int main(){

int **matPtr; 
int i,j,n,m;

printf("\n Quantidade de linhas: \n");
scanf("%d", &n);

printf("\n Quantidade de colunas: \n");
scanf("%d", &m);

matPtr = (int**) malloc(n *sizeof(int*));




printf("\n Entrada de dados \n");

for(i=0; i<n; i++){
    matPtr[i] = (int*) malloc (m*sizeof(int));

    for(j=0;j<m;j++){
        printf("mat %d %d = ", i,j);
        scanf("%d", &matPtr[i][j]);
    }
}

printf("\n Saida de dados \n");

for(i=0; i<n; i++){
   

    for(j=0;j<m;j++){
        printf("%5d ",matPtr[i][j]);
        
    }
    printf("\n");
}






    return 0;
}