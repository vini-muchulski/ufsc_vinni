#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int n1,n2,n3,n4;

int aux;
int numero;

int numero_final_criptografado;

printf("Digite o numero \n");
scanf("%d", &numero);

n4 = numero % 10;

n3 = (numero/ 10) % 10;

n2 = (numero/ 100) % 10;

n1 = (numero/ 1000) % 10;



aux = n1;

n1 = n3;
n3 = aux;


aux= n2;
n2 = n4;
n4 = aux;

n1 = (n1+3) % 10;
n2 = (n2+3) % 10;
n3 = (n3+3) % 10;
n4 = (n4+3) % 10;


numero_final_criptografado = n1*1000 + n2 * 100 + n3* 10 + n4;

printf( " numero final = %d ", numero_final_criptografado);


    return 0;
}
