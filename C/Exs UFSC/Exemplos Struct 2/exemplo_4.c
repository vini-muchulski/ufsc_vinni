
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

        struct Books *bPtr;
        int nBooks;
        int i;

        printf("Qnts livros tera no cadastro: ");
        scanf("%d", &nBooks);

 bPtr = (struct Books *) malloc(nBooks * sizeof ( struct Books));

 for (i=0;i<nBooks;i++){

            printf("\n Entrada de dados livros %d \n",i);

        printf("Identificador: \n");
        scanf("%d", &(bPtr + i)->id);

        printf("Titulo do livro: \n");
        scanf(" %[^\n]%*c",  (bPtr + i)->titulo);

        printf("Autor: \n");
        scanf(" %[^\n]%*c",  (bPtr + i)->autor);
        }

        printf(" \n Livros cadastrados \n");

 for (i=0;i<nBooks;i++){

            printf(" \n Livro %d \n",i);

        printf("Codigo ID = %d \n",(bPtr + i)->id );
        printf("Titulo = %s \n",(bPtr + i)->titulo );
        printf("Autor = %s \n",(bPtr + i)->autor );

        }

return 0;
}