#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int i,j;
float mat[5][5];
float valor;
float soma_da_diagonal = 0;
float vet_aux[5];
float soma_coluna = 0;
int maior_coluna;
float soma_maior_coluna;


// recebe elementos da matriz
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        printf("Digite o valor do elemento na posicao [%d][%d]: \n",i,j);
        scanf("%f", &valor);
        mat[i][j] = valor;
    }
}

// printa matriz
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        printf("%.1f ",mat[i][j]);
         
        
    }
    printf("\n");
}

//verifica se algum elemento da diagonal é negativo
// realiza a soma dos elementos da diagonal
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        if(i == j){

       if(mat[i][j]<0){
        soma_da_diagonal = mat[i][j] * (-1) + soma_da_diagonal;
       }
       else{
        soma_da_diagonal = mat[i][j] + soma_da_diagonal;
       }
        }
        
    }
}

printf("Soma dos elementos da diagonal = %.2f ", soma_da_diagonal);


// b --------------------------------------------------
// gera a soma de cada coluna e guarda em um vetor auxiliar
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        soma_coluna = mat[j][i] + soma_coluna;

         
        
    }
    vet_aux[i] = soma_coluna;
    soma_coluna = 0;
    
}

for (i=0;i<5;i++){
    if( i == 0){
        maior_coluna = i;
        soma_maior_coluna = vet_aux[i];
    }
    else{
        if(vet_aux[i]>soma_maior_coluna){
            maior_coluna = i;
        soma_maior_coluna = vet_aux[i];

        }
    }
}


printf("\n A coluna com maior soma de elementos foi coluna %d com soma = %.2f", maior_coluna,soma_maior_coluna);

    return 0;
}

