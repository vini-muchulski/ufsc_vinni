#include <stdio.h>
 // soma de numeros inteiros maior que zero de uma dada sequencia
int main(){
int valor,total,contador,seq;

total = 0;
contador = 0;

printf("Digite a quantidade de digitos da sequencia: \n");
scanf("%d", &seq);

printf("Digite o valor: \n");
scanf("%d", &valor);

if (valor>0){
total++;
}

while(contador < seq-1){

printf("Digite o  valor : \n");
scanf("%d", &valor);

if (valor>0){
total++;}

contador++;
}
printf("Total de numeros maiores que zero = %d \n", total);
return 0;
}
