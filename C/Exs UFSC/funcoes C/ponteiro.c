#include <stdio.h>

int main(){
    int x = 2;
    int *xPTR;

    xPTR = &x;

    printf("Endereco da variavel x = %p \n", &x);

    printf("Endereco armazenado em xPTR = %p \n", &xPTR);

    printf("Valor de x = %d \n", x);

     printf("valor da variavel apontada por xPTR = %d \n", *xPTR);

     // *& and &*
    printf("Valor de *& xPTR = %p \n", *&xPTR);
    printf("Valor de &* xPTR = %p \n", &*xPTR);




    return 0;
}