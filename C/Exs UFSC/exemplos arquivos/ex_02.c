#include <stdio.h>




int main(){

    FILE *in_fPtr;
    int num;

    in_fPtr = fopen("output.txt", "r");

    if(in_fPtr == NULL)
    {
        printf("\n Erro! Nao foi possivel criar arquivo! \n");
        return 1;
    }

    // leitura de dados do arquivo
    printf("\n Leitura de dados do arquivo output.txt \n");
   while (fscanf(in_fPtr,"%d", &num) == 1){
    printf("Numero = %d \n", num);
   }

    
    fclose(in_fPtr);
    
    return 0;
}