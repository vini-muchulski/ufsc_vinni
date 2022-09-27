#include <stdio.h>
// soma dos algarismos de um numero
int main(){
int valor, algarismo,divisao, soma, valor_inicial;
soma = 0;
printf("Digite um valor: \n");
scanf("%d", &valor);
valor_inicial = valor;

while (valor != 0){
    algarismo = valor%10;
    soma +=algarismo;
    divisao = valor/10;

    valor = divisao;

}

printf("A soma dos algarismo de %d eh equivalente a %d", valor_inicial, soma);

return 0;
}
