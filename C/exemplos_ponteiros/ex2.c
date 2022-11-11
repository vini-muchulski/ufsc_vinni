#include <stdio.h>

int main(){

int y = 5;
int *yPtr;


    yPtr = &y;

    printf("Endereco da variavel y: %p \n", &y);

    printf("Endereco armazenado em yptr variavel: %p \n", yPtr);

    printf("Valor de Y: %d \n", y);



    printf("Valor de *yptr: %d \n", *yPtr);

    printf("valor of *& yptr: %p \n ", *&yPtr);
    printf("valor of *& yptr: %p \n ", &*yPtr);


    return 0;
}