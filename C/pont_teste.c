#include <stdio.h>

int main(){
int *x,valor,y;

valor = 35;

x =&valor; // Atribuindo o endereco de valor a x;

y = *x; // Atribuindo o conteudo da variavel apontada por x a y;

printf(" Endereco da variavel comum valor: %p \n", &valor);
printf(" Lendo o conteudo do ponteiro x: %p \n", x);
printf(" Endereço da variavel ponteiro x: %p \n", &x);
printf(" Conteudo da variavel apontado por x: %d \n",*x);
printf(" Conteudo da varaivel comum y: %d\n", y);


return 0;
}
