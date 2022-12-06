#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Criar a matriz A com o tamanho mxn definido pelo usuário.
• Procurar pelo maior elemento nessa matriz e mostrar a sua posição
(linha e coluna).*/


int main(){

int **mat;
int i,j;
int maior[3];
int m,n;

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


for(i=0;i<n;i++){
   
    for(j=0;j<m;j++){
        
       

       //descobre o maior elemento
        if(i==0 && j ==0){
            maior[0] = mat[i][j];
            maior[1] = i;
            maior[2] = j;
        }
        else{
            if(mat[i][j]>maior[0]){
                maior[0] = mat[i][j];
                maior[1] = i;
                maior[2] = j;
            }
        }
         
    }
}
printf("\n");
// printa matriz

for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        printf("%d ",mat[i][j]);
         
    }
    printf("\n");
}

printf("Maior Elemento = %d \nPosicao = %d %d", maior[0],maior[1],maior[2]);

    return 0;
}
