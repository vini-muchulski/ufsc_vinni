/*Dado um número natural n (fornecido pelo usuário), calcular a soma: 1/n...*/
#include <stdio.h>



int main(){
int n,i;

float soma;
soma = 0.0;

printf("Digite um numero natural: \n");
scanf("%d", &n);

for(i=1;i<=n;i++){
   
    soma = soma +1.0/i;


}
printf("SOMA =  %.2f",soma);

    return 0;
}