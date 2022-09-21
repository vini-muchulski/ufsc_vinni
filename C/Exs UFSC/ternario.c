#include <stdio.h>

// Utilizando operador ternário escreva um programa que receba um número e verifique se esse número é positivo ou negativo.

int main(){

int a;
printf("Digite um valor: \n");
scanf("%d", &a);
printf("%s", a>0 ? "Positivo" : "Negativo");
return 0;
}
