#include <stdio.h>

//Fa�a um programa que receba um n�mero inteiro e mostre o modulo

int main(){
 int valor;

 printf("Digite um numero e veja seu modulo: \n");
 scanf("%d", &valor);

 if (valor<0){
  valor = valor*(-1);
  printf("Valor: %d \n", valor);

  }
else{
    printf("Valor: %d \n", valor);
}

  return 0;
}
