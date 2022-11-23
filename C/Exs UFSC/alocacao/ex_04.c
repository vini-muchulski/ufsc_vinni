#include <stdio.h>
#include <stdlib.h>

int main(){

int *matPtr; // ponteiro
int i, j ,n,m;

printf("Digite a quantidade de linhas: \n");
scanf("%d", &n);


printf("Digite a quantidade de colunas: \n");
scanf("%d", &m);

// alocacao de memorioa

matPtr = (int*) malloc(n*m*sizeof(int));

    printf("\n Entrada de Dados \n");
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("mat [%d][%d] = ",i,j);
            scanf("%d", (matPtr+ i*m +j));


        }
    }

    printf("\n Saida de Dados \n");
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("%5d ",*(matPtr+ i*m +j));


        }
        printf("\n");
    }



    return 0;
}