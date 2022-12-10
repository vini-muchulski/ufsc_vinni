#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
FILE: prob1.c
TITLE: RELATORIO DE TRABALHO DE LABORATORIO 1

SUBMITTED BY: Vinicius Wolosky Muchulski

FOR COURSE: Engenharia de computacao
DUE DATE: 9 de Dezembro de 2022

PURPOSE:

Esse código busca ter a capacidade de gerar um struct que funciona como uma biblioteca, permitindo assim guardar os valores de 3 livros em um arquivo

OVERALL METHOD:

É declarado um struct com 3 atributos, sendo o primeiro id referente a um numero do livro, o char representa o titulo da oba e o char seguinte recebe o nome do autor;
No main serão gerados 3 estruturas referentes ao livros 1,2 e 3 que serão guardados.
Além disso, logo no inicio é gerado um arquivo que irá receber as informacoes de cada livro que serão dadas pelo usuario
Ainda assim, é realizada uma verificação se o arquivo foi alocado com sucesso, caso contrário o codigo gera exit.
Logo após isso, ocorre o processo de fornecimento das informacoes pelo usuário, que serão guardadas e posteriormente ficarão no arquivo1.txt

FUNCTIONS:

INCLUDED FILES:


stdio.h
stdlib.h
string.h

DATA FILES:
arquivo1.txt

 */


struct Biblioteca
{
    
    char titulo[50];
    char autor[50];
    int id;
};


int main(){

//gera arquivo
FILE *filePtr;

filePtr = fopen("arquivo1.txt", "w");

// verifica alocação
if( filePtr == NULL){
    printf("Erro de alocacao");
    return 1;
}

  //geraçao de estruturas  
    struct Biblioteca livro1;
    struct Biblioteca livro2;
    struct Biblioteca livro3;


    
    // processo de recebimento de informacoes do livro 1
    printf("Digite o ID do livro 1 = \n");
    scanf("%d", &livro1.id);

    printf("Titulo do livro 1 = \n");
    scanf(" %[^\n]%*c", livro1.titulo);

    printf("Autor do livro 1 = \n");
    scanf(" %[^\n]%*c", livro1.autor);
    
    

    fprintf(filePtr, "%s\n", livro1.titulo);
    fprintf(filePtr, "%d\n", livro1.id);
    fprintf(filePtr, "%s\n", livro1.autor);
    fprintf(filePtr, "\n");


// ---------------------------------------------------------
    // processo de recebimento de informacoes do livro 2

    printf("Digite o ID do livro 2 = \n");
    scanf("%d", &livro2.id);

    printf("Titulo do livro 2 = \n");
    scanf(" %[^\n]%*c", livro2.titulo);

    printf("Autor do livro 2 = \n");
    scanf(" %[^\n]%*c", livro2.autor);
    
    

    fprintf(filePtr, "%s\n", livro2.titulo);
    fprintf(filePtr, "%d\n", livro2.id);
    fprintf(filePtr, "%s\n", livro2.autor);
    fprintf(filePtr, "\n");
    

// ---------------------------------------------------------
    // processo de recebimento de informacoes do livro 3

    printf("Digite o ID do livro 3 = \n");
    scanf("%d", &livro3.id);

    printf("Titulo do livro 3 = \n");
    scanf(" %[^\n]%*c", livro3.titulo);

    printf("Autor do livro 3 = \n");
    scanf(" %[^\n]%*c", livro3.autor);
    
    

    fprintf(filePtr, "%s\n", livro3.titulo);
    fprintf(filePtr, "%d\n", livro3.id);
    fprintf(filePtr, "%s\n", livro3.autor);
    fprintf(filePtr, "\n");
    

fclose(filePtr);


    return 0;
}