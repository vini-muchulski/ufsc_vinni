#include <stdio.h>

int main(){
int soma, valor,i,cont;
float media;

soma = 0;
valor = 0;
i = 1;

printf("Digite o numero de tentativas:\n");
scanf("%d", &cont);


do{
printf("Digite o %d valor: \n", i);
scanf("%d",&valor);

 if( valor%2 == 0 && valor%3 ==0){
soma = soma + valor;
 }

i++;
}while(i<=cont);


printf("A soma dos numeros inteiros pares e multiplos de tres foi %d", soma);

return 0;
}
