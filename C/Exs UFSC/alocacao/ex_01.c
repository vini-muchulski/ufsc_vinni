#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vPtr;
    int tamanho;
    int i;

    printf("Digite o tamanho: ");
    scanf("%d", &tamanho);

    //alocacao de memoria
    vPtr = (int*)malloc(tamanho*sizeof(int));

    printf("\n Input dados: \n");
    for(i=0;i<tamanho; i++){

        printf("\n V[%d] = ", i);
        scanf("%d", &vPtr[i]);

    }

    printf("\n printando: \n");
    for(i=0;i<tamanho; i++){

        printf(" V[%d] = %d \n",i,vPtr[i]);
        
    }

    return 0;
}