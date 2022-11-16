#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vPtr;
    int *auxPtr;
    int tamanho;
    int i;

    printf("Digite o tamanho: ");
    scanf("%d", &tamanho);

    //alocacao de memoria
    vPtr = (int*)malloc(tamanho*sizeof(int));

    auxPtr = vPtr;
    printf("\n Input dados: \n");
    for(i=0;i<tamanho; i++){

        printf("\n V[%d] = ", i);
        scanf("%d", auxPtr);
        auxPtr++;

    }

    auxPtr = vPtr;
    printf("\n printando: \n");
    for(i=0;i<tamanho; i++){

        printf(" V[%d] = %d \n",i,*auxPtr); // ponteiro com inicio fixo & [] - ponteiro que vai variando, por exemplo a partir de um ponteiro inicial *
        auxPtr++;
    }

    return 0;
}