/*Criar a matriz A com o tamanho mxn definido pelo usuário.
• Criar a matriz B, que é a matriz transposta da matriz A.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int **mat;
int i,j;
int tamanho_a;
int m,n;
int k=0;
int s=0;

int **Bmat;

printf("Digite o numero de linhas: \n");
scanf("%d", &n);


printf("Digite o numero de colunas: \n");
scanf("%d", &m);

mat = (int**) malloc(n*sizeof(int*));

// gera matriz
for(i=0;i<n;i++){
    mat[i] = (int*)malloc(m*sizeof(int));
    for(j=0;j<m;j++){
        
        printf("Elemento [%d][%d] = \n",i,j);
        scanf("%d", &mat[i][j] );

 
    }
}

// matriz transposta
Bmat = (int**) malloc(m*sizeof(int*));

for(j=0;j<m;j++){
    Bmat[j] = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        Bmat[j][i] = mat[i][j];
        printf("%d ", Bmat[j][i]);
    }
    printf("\n");
}


    return 0;
}
