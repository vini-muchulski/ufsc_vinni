#include <stdio.h>




int main(){

    FILE *filePtr;
    int i;

    filePtr = fopen("output.txt", "w");

    if(filePtr == NULL)
    {
        printf("\n Erro! Nao foi possivel criar arquivo! \n");
        return 1;
    }

    // gravar dados
    for(i=1; i<=10; i++){
        fprintf(filePtr,"%d\n", i);
    }

    printf("\n O programa gravou numeros de [1,10] para arquivo output.txt \n");
    fclose(filePtr);
    
    return 0;
}
