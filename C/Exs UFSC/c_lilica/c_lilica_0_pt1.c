#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

// Declaração de variaveis e inicialização
int n1,n2,n3,n4;

int aux;

int n1_criptografado,n2_criptografado,n3_criptografado,n4_criptografado;

int numero_final_criptografado;

 // Solicita ao usuário que digite os quatro dígitos

printf("Digite o primeiro digito: \n");
scanf("%d", &n1);

printf("Digite o segundo digito: \n");
scanf("%d", &n2);

printf("Digite o terceiro digito: \n");
scanf("%d", &n3);

printf("Digite o quarto digito: \n");
scanf("%d", &n4);

// Soma  7 a cada um
n1_criptografado = n1 + 7;
n2_criptografado = n2 + 7;
n3_criptografado = n3 + 7;
n4_criptografado = n4 + 7;

// Mantém apenas o último dígito da soma, utilizando o operador módulo (%)
n1_criptografado = n1_criptografado % 10;
n2_criptografado = n2_criptografado % 10;
n3_criptografado = n3_criptografado % 10;
n4_criptografado = n4_criptografado % 10;

// Troca a posição do primeiro e terceiro dígitos e do segundo e quarto dígitos

aux = n1_criptografado;

n1_criptografado = n3_criptografado;
n3_criptografado = aux;

aux = n2_criptografado;

n2_criptografado = n4_criptografado;
n4_criptografado = aux;

// Cria o número final criptografado
numero_final_criptografado = n1_criptografado*1000 + n2_criptografado * 100 + n3_criptografado* 10 + n4_criptografado;

printf("Numero criptografado = %d", numero_final_criptografado);







    return 0;
}
