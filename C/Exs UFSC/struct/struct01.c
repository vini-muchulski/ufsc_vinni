#include <stdio.h>

struct numeros_struct
{
    int n1s,n2s;
};



int main(){

struct numeros_struct numero1;
printf("Digite um valor: \n");
scanf("%d", &numero1.n1s);

printf("Outro valor: \n");
scanf("%d", &numero1.n2s);

printf("A SOMA DOS VALORES = %d", numero1.n1s+numero1.n2s);

return 0;

}