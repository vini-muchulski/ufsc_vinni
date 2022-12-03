#include <stdio.h>

int main(){

        FILE *filePtr;
        int id;
        float n;
        char name[100];

        filePtr = fopen("alunos.txt", "r");

        if(filePtr == NULL){
            printf("Erro! nao foi possivel abrir o arquivo \n");
            return 1;
        }

        printf("\n Programa faz a leitura de dados do arquivo alunos.txt\n");

        while (fscanf(filePtr,"%i", &id) != EOF)
        {
            fscanf(filePtr, "%i", &id);
            fgets(name,100,filePtr);
            fscanf(filePtr,"%f", &n);

            printf("\n Leitura de dados: ");
            printf("\n Matricula: %i", id);
            printf("\n Nome: %s", name);
            printf("Nota: %.2f \n \n",n);

        }

        fclose(filePtr);
        return 0;
        
}