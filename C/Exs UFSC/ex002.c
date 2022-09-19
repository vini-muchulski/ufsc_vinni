#include <stdio.h>

//Faça um programa que receba dois ints e mostre o maior

int main(){
  int a,b;
  printf("Digite o PRIMEIRO valor: \n");
  scanf("%d", &a);

  printf("Digite o SEGUNDO valor: \n");
  scanf("%d", &b);

  if (a>b){
  printf("O PRIMEIRO valor %d eh maior que o SEGUNDO valor %d", a,b);
  }

 else{
     printf("O SEGUNDO valor %d eh maior que o PRIMEIRO valor %d", b,a);
         }



 return 0;

 }

