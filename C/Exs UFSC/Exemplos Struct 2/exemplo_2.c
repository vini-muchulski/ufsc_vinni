// Exemplo 2: Criação de um vetor de estruturas Books. Estrutura como argumento de uma função

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books
{
    int id;
    char titulo[50];
    char autor[50];
};

void PrintBook (struct Books livro, int n);

int main(){

    const int lib_size = 3;
    struct Books livros[lib_size];
    int i;

    for (i=0; i< lib_size; i++){

        printf("\n\n Entrada de dados do livro %d \n\n", i);
        
        livros[i].id = 100 + i;

        printf("Digite o titulo do livro: \n");
        scanf("%s", livros[i].titulo);

        printf("Autor do livro: \n");
        scanf("%s", livros[i].autor);

    }

    printf("\n LIVROS NA BIBLIOTECA \n");

    for (i=0; i< lib_size; i++){

       PrintBook(livros[i], i);
    }

    return 0;
}


void PrintBook (struct Books livro, int n){
    printf("\n Livro %d \n",n);
    printf("\n Nome = %s \n", livro.titulo);
    printf("\n Autor = %s \n",livro.autor);
    printf("\n Livro ID %d \n",livro.id);

}