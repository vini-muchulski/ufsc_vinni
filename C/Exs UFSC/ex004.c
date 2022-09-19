#include <stdio.h>

//#Desenvolva um programa que leia o comprimento de três retas e diga ao usuário se elas podem ou não formar um triângulo.

int main(){
 int a,b,c, cont;
 cont = 0;
 printf("Digite o PRIMEIRO valor: \n");
  scanf("%d", &a);

  printf("Digite o SEGUNDO valor: \n");
  scanf("%d", &b);

    printf("Digite o TERCEIRO valor: \n");
  scanf("%d", &c);

if (b+a>c){
    cont++;
}
if (b+c>a){
    cont++;
}
if (c+a>b)
{
    cont++;
}
if (cont==3){
    printf("O trinagulo EXISTE!");
}

else{
printf("O trinagulo nao possui condicao de existencia");
}

return 0;
}
