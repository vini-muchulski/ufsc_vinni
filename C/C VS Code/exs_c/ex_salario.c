#include <stdio.h>

//Faça um algoritmo que leia o salário de um funcionário e mostre seu novo salário, com 15% de aumento

int main(){
    float salario, novo_salario;
    printf("Digite seu salario: \n");
    scanf("%f", &salario);
    novo_salario = salario*1.15;
    printf("Seu novo salario reajustado eh de %f reais", novo_salario);
    return 0;
    }
