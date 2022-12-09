// Escreva um programa que receba as seguintes informaçoes de uma turma: nome, nota e matrícula. Armazene estas informaçoes em um registro e calcula a media da turma.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Turma{
    char nome[50];
    int matricula;
    float nota;
};

int main(){

    const int tamanho_turma;

    printf("digite o tamanho da turma: \n");
    scanf("%d", &tamanho_turma);


    struct Turma alunos[tamanho_turma];
    int i;

    float media =0;
    float soma_notas =0;

    for(i=0;i<tamanho_turma;i++){

        printf("nome do aluno %d: \n", i);
        scanf("%s", alunos[i].nome);

        printf("matricula do aluno: \n");
        scanf("%d", &alunos[i].matricula);

        printf("nota do aluno: \n");
        scanf("%f", &alunos[i].nota);
        printf("\n");
        
    }

    for(i=0;i<tamanho_turma;i++){
        printf("nome do aluno: %s\n", alunos[i].nome);
        

        printf("nome do aluno: %d\n", alunos[i].matricula);

        printf("nome do aluno: %.2f\n", alunos[i].nota);
        soma_notas = alunos[i].nota + soma_notas;

        printf("\n");
        printf("\n");
        
    }

    media = soma_notas/tamanho_turma;

    printf("a media da turma foi = %.2f", media);

    return 0;
}