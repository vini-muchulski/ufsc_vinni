#include <stdio.h>

int main(){
int soma, valor,i;
float media;

soma = 0;
valor = 0;
i=1;

do{
printf("Digite o %d valor: \n", i);
scanf("%d",&valor);
soma = soma + valor;
i++;
}while(i<=5);

media = soma/5;

printf("A media foi %.2f", media);

return 0;
}
