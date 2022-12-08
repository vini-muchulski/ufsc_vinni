#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int **mat;
int i,j;
int m,n;

printf("Digite o numero de linhas: \n");
scanf("%d", &m);

printf("Digite o numero de colunas: \n");
scanf("%d", &n);



mat = (int**) malloc(sizeof(int)*m);

for(i=0;i<m;i++){
    mat[i] = (int*)malloc(n*sizeof(int));
    for(j=0;j<n;j++){
        
        printf("Elemento [%d][%d] = \n",i,j);
        scanf("%d", &mat[i][j] );

    }
}

for(i=0;i<m;i++){
    
    for(j=0;j<n;j++){
        
        printf("%d ",mat[i][j]);
        

    }
    printf("\n");
}
    return 0;
}


