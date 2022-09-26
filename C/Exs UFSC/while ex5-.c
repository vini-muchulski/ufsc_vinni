#include <stdio.h>
int main(){
int valor,a, n, soma;

soma = 0;

printf("Digite o valor: \n");
scanf("%d", &valor);


while(valor !=0){

    a = valor%10;
    soma = soma + a;

    valor = valor/10;

}

printf("Soma do algarismos = %d", soma);

return 0;
}

