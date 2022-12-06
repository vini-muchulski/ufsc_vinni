#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  • Criar a matriz A com o tamanho mxn definido pelo usuário.
• Copiar todos os elementos pares dessa matriz para um vetor b que
deve ser criado dinamicamente.
*/


int main(){

int **mat;
int i,j;
int qnt_pares =0;;
int m,n;
int *vet_pares;
int cont = 0;

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


// conta pares

for(i=0;i<n;i++){

    for(j=0;j<m;j++){
    
        if(mat[i][j]%2 == 0){
            qnt_pares++;
        }
 
    }
}

vet_pares = (int*) malloc (qnt_pares*sizeof(int));

if( vet_pares == NULL){
    printf("ERRO DE ALOCACAO");
}

for(i=0;i<n;i++){

    for(j=0;j<m;j++){
        
        if(mat[i][j]%2 == 0){
            vet_pares[cont] = mat[i][j];
            cont++;
            
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



printf("\nVetor de Pares\n");
for(i = 0; i<cont;i++){
    printf("%d ", vet_pares[i]);
}

    return 0;
}
