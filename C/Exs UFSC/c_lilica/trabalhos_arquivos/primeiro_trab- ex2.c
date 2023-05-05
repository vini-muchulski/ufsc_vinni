#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    
    int n1, n2, n3, n4; // os dígitos do número a ser criptografado
    int aux; 
    int numero; // número a ser criptografado
    int numero_final_criptografado; // número criptografado resultante

    // Solicita ao usuário para digitar o número a ser criptografado
    printf("Digite o numero \n");
    scanf("%d", &numero);

    // Separação dos dígitos do número
    n4 = numero % 10; 
    n3 = (numero/ 10) % 10; 
    n2 = (numero/ 100) % 10; 
    n1 = (numero/ 1000) % 10; 

    // Troca dos valores dos dígitos
    aux = n1; 
    n1 = n3; 
    n3 = aux; 

    aux= n2; // guarda o valor de n2 em aux
    n2 = n4; // n2 recebe o valor de n4
    n4 = aux; // n4 recebe o valor guardado em aux

    // Adiciona 3 a cada dígito e realiza o módulo por 10 para manter o número de um dígito
    n1 = (n1+3) % 10;
    n2 = (n2+3) % 10;
    n3 = (n3+3) % 10;
    n4 = (n4+3) % 10;

    // Reorganiza os dígitos para formar o número criptografado final
    numero_final_criptografado = n1*1000 + n2 * 100 + n3* 10 + n4;

    
    printf( " numero final = %d ", numero_final_criptografado);

    
    return 0;
}