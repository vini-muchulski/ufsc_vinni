#include <stdio.h>

int main(){
int var;
int *ptr;
int **pptr;

var = 5;

ptr = &var;

pptr = &ptr;

printf("\n Valor de var %d",var );
printf("\n endereco de var %p", &var);
printf("\n-------------------------------------\n");

printf("\nvalor disponivel  *ptr = %d \n",*ptr);
printf("\nendereco de ptr = %p \n", &ptr );
printf("\n Endereco armazenado em ptr = %p \n",ptr);
printf("\n-------------------------------------\n");

printf("\nvalor disponivel em **ptr = %d \n",**pptr);
printf("\nendereco de pptr = %p \n", &pptr);
printf("\nEndereco armazenado em pptr = %p \n",pptr);



    return 0;
}