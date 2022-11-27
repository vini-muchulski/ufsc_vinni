//Exemplo 3: Alocação dinâmica de estrutura e uso de variável seta

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

 struct Books *aPtr;
 struct Books *bPtr;


 aPtr = (struct Books *) malloc (sizeof( struct Books));
 bPtr = (struct Books *) malloc (sizeof( struct Books));

printf(" Entrada de dados livros 1 \n");

printf("Identificador: \n");
scanf("%d",&aPtr->id);

printf("Titulo do livro: \n");
scanf(" %[^\n]%*c",aPtr->titulo);

printf("Autor: \n");
scanf(" %[^\n]%*c",aPtr->autor);



printf("\n Entrada de dados livros 2 \n");

printf("Identificador: \n");
scanf("%d", &bPtr->id);

printf("Titulo do livro: \n");
scanf(" %[^\n]%*c",  bPtr->titulo);

printf("Autor: \n");
scanf(" %[^\n]%*c",  bPtr->autor);


printf(" \n Livros cadastrados \n");


printf(" \n Livro 1 \n");

printf("Codigo ID =  %d \n",aPtr->id );
printf("Titulo = %s \n",aPtr->titulo );
printf("Autor = %s \n",aPtr->autor );


printf(" \n Livro 2 \n");

printf("Codigo ID = %d \n",bPtr->id );
printf("Titulo = %s \n",bPtr->titulo );
printf("Autor = %s \n",bPtr->autor );

free(aPtr);
free(bPtr);


    return 0;
}