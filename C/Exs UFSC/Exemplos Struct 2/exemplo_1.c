#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books
{
    int id;
    char titulo[50];
    char autor[50];
};

int main(){

    struct Books livro1;
    struct Books livro2;

    strcpy(livro1.titulo,"Cosmos");
    strcpy(livro1.autor, "Carl Sagan");
    livro1.id = 123;


    strcpy(livro2.titulo, "Sapiens");
    strcpy(livro2.autor, "Yuval Harari");
    livro2.id = 130;

    printf("\nLivro - %s \n", livro1.titulo);
    printf("\nAutor - %s \n", livro1.autor);
    printf("\nID - %d \n", livro1.id);
    printf("\n ----------------- \n");

    printf("\nLivro - %s \n", livro2.titulo);
    printf("\nAutor - %s \n", livro2.autor);
    printf("\nID - %d \n", livro2.id);
    printf("\n ----------------- \n");


    return 0;
}
