#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int m,i,j;
int **mat;
int *b;
int cont_b = 0;

printf("Digite o tamanho da matriz: \n");
scanf("%d", &m);

mat = (int**) malloc(m*sizeof(int*));

// gera matriz
for(i=0;i<m;i++){
    mat[i] = (int*)malloc(m*sizeof(int));
    for(j=0;j<m;j++){
        
        printf("Elemento [%d][%d] = \n",i,j);
        scanf("%d", &mat[i][j] );
 
    }
}

// gera vetor b com elementos da diagonal
b = (int*) malloc(m*sizeof(int));

for(i=0;i<m;i++){
   
    for(j=0;j<m;j++){
        if(i==j){
            b[cont_b] = mat[i][j];
            cont_b++;
        }
      
    }
}
printf("\n Vetor b \n");
for(i=0;i<m;i++){
    printf("%d ",b[i]);
}
printf("\n");

//--------------------------------


int *vetor_c;

vetor_c = (int*) malloc(m*sizeof(int));

float *vetor_aux;

vetor_aux = (int*) malloc(m*sizeof(int));

float soma_linha =0;
float media_linha =0;
int maior_linha;


for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        soma_linha = soma_linha + mat[i][j]; 
    }
    media_linha = soma_linha/m;
    vetor_aux[i] = media_linha;
    media_linha = 0;
    soma_linha = 0;
}

printf("Valor medio dos elementos de cada linha \n");

for(i=0;i<m;i++){
    printf("%.2f ", vetor_aux[i]);
    if(i == 0){
        maior_linha = i;
    }
    else{
        if(vetor_aux[i]>maior_linha){
            maior_linha = i;
        }
    }
}
for(j=0;j<m;j++){
    vetor_c[j] = mat[maior_linha-1][j];
}
printf("%d \n", maior_linha);

printf("\n");
printf("vetor c\n");
for(j=0;j<m;j++){
    printf("%d ",vetor_c[j]);
}




    return 0;
}