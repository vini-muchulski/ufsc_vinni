/*Dado um número inteiro qualquer, escreva o programa que calcula a soma dos
dígitos de um número inteiro qualquer informado pelo usuário.*/

#include <stdio.h>

int main(){
int numero,resto,soma_alg;

soma_alg = 0;

printf("Digite um valor N: \n");
scanf("%d",&numero);

while (numero !=0){

    resto = numero%10;
    soma_alg +=resto;
    numero = numero/10;

    
}

printf("soma dos algarismo = %d ", soma_alg);
return 0;
}