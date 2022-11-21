#include <stdio.h>

//VAMOS ESCREVER UMA FUNCAO QUE RECEBA DOIS NUMEROS INTEIROS E TROQUE O VALOR DELES

void troca(int *x , int *y);

int main(){

int a,b;

a = 5;
b = 3;

troca(&a,&b);

printf("a = %d \nb = %d", a,b);

    return 0;


}

void troca(int *x , int *y){

    int aux;
    aux = *x;
    *x = *y;
    *y = aux;

    

}