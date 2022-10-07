#include <stdio.h>




/*
FILE: trab_03.c
TITLE: RELATORIO DE TRABALHO DE LABORATORIO 1

SUBMITTED BY: Vinicius Wolosky Muchulski, Natalia Farias Bianchini

FOR COURSE: Engenharia de computacao
DUE DATE: 7 de Outubro de 2022

PURPOSE:
Esse c�digo busca expressar a rela��o de fun��o entre dois valores, o qual um deles � informado
pelo usuario.

OVERALL METHOD:

Recebe um input dado pelo usu�rio e armazena este valor na vari�vel de X.
Ap�s isso, compara o valor com as condicionais dadas e verifica em qual intervalo a
variavel est� contida.
Caso o valor fornecido seja maior ou igual a -2 e menor ou igual a 2, o valor de Y ser� o
quadrado de X.
Em caso de valores superiores a 2 ou inferiores a -2 o valor de Y � pr�-definido em 4.
Em seguida, o codigo retorna um valor para a vari�vel Y, mostrando-a na tela.


INCLUDED FILES:
stdio.h

DATA FILES:
none

 */
int main(){
    int x,y;

    printf("DIGITE UM VALOR PARA X: \n");
    scanf("%i", &x);

    if(-2<=x<=2){
        y = x*x;

    }

    if(x>2  ||  x<-2 ){
        y=4;

    }

    printf("Y = %i",y);

    return 0;
}
