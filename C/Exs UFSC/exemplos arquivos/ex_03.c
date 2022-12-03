#include <stdio.h>

int main(){
        FILE *filePtr;
        int id, i = 1, ch;
        float n;
        char name[100];
        
        
        filePtr = fopen("alunos.txt", "w");
        
        if (filePtr == NULL){
            printf("\n Erro! Nao foi possivel criar arquivo \n");
            return 1;
        }

        printf("\n Programa grava dados para arquivo alunos.txt \n");

        while (i != 0)
        {
            printf("\n Digite a matricula do aluno: ");
            scanf("%i", &id);

            printf("\n Digite o nome do aluno: ");
            scanf(" %[^\t\n]s", name);
             
            printf("\n Digite a nota do aluno: ");
            scanf("%f", &n);

            printf("\nVoce digitou: ");
            printf("\n Matricula: %i", id);
            printf("\n Nome: %s", name);
            printf("\n Nota: %.2f", n);

            printf("\n Gravara para arquivo? 1 - Sim; 0 - Nao ");
            scanf("%i", &ch);

            if(ch == 1)
            {
                fprintf(filePtr, "%d\n", id);
                fprintf(filePtr, "%s\n", name);
                fprintf(filePtr, "%.2f\n", id);
            }
            
            printf("\n Deseja continuar? 1 - Sim; 0 - Nao ");
            scanf("%i", &i);
        }
        
        fclose(filePtr);
        return 0;
        }