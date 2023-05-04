#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

// declara as variáveis necessárias
int n1,n2,n3,n4;

int aux;
int numero;

int n1_criptografado,n2_criptografado,n3_criptografado,n4_criptografado;

int numero_final_criptografado;

printf("Digite o numero \n");
scanf("%d", &numero);

// obtém os dígitos do número original
n4 = numero % 10;

n3 = (numero/ 10) % 10;

n2 = (numero/ 100) % 10;

n1 = (numero/ 1000) % 10;


n1_criptografado = n1 + 7;
n2_criptografado = n2 + 7;
n3_criptografado = n3 + 7;
n4_criptografado = n4 + 7;

// ajusta o valor criptografado para o intervalo de 0 a 9

n1_criptografado = n1_criptografado % 10;
n2_criptografado = n2_criptografado % 10;
n3_criptografado = n3_criptografado % 10;
n4_criptografado = n4_criptografado % 10;


// permuta os dígitos criptografados
aux = n1_criptografado;

n1_criptografado = n3_criptografado;
n3_criptografado = aux;

aux = n2_criptografado;

n2_criptografado = n4_criptografado;
n4_criptografado = aux;

numero_final_criptografado = n1_criptografado*1000 + n2_criptografado * 100 + n3_criptografado* 10 + n4_criptografado;

printf("Numero criptografado = %d", numero_final_criptografado);







    return 0;
}
