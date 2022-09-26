#include <stdio.h>
 // soma de numeros inteiros
int main(){
int valor,total,contador,seq;

total = 0;
contador = 0;

printf("Digite a quantidade de digitos da sequencia: \n");
scanf("%d", &seq);

printf("Digite o valor: \n");
scanf("%d", &valor);
total = total + valor;

while(contador < seq-1){


printf("Digite o valor: \n");
scanf("%d", &valor);
total = total + valor;
contador++;
}

printf("Total da soma dos numeros = %d \n", total);
return 0;
}
