#include <stdio.h>

// Utilizando operador tern�rio escreva um programa que receba um n�mero e verifique se esse n�mero � positivo ou negativo.

int main(){

int a;
printf("Digite um valor: \n");
scanf("%d", &a);
printf("%s", a>0 ? "Positivo" : "Negativo");
return 0;
}
