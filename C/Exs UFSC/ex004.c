#include <stdio.h>

//#Desenvolva um programa que leia o comprimento de tr�s retas e diga ao usu�rio se elas podem ou n�o formar um tri�ngulo.

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
