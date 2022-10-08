/*Escreva um programa para calcular a média aritmética de um conjunto de
números pares positivos fornecidos pelo usuário*/

#include <stdio.h>

int main(){
int soma_pares,i,valor;
int tentativas_invalidas = 0;


float media;

i=0;
tentativas_invalidas =0;

printf("Digite um valor inicial: \n");
scanf("%d",&valor);

if (valor%2==0 && valor>0){
    soma_pares +=valor;
    i++;
}


while ( valor != 0){

printf("Digite um valor adicional: \n");
scanf("%d",&valor);

if (valor%2==0 && valor>0){
    soma_pares +=valor;
    i++;
}
if(valor%2 !=0){
    tentativas_invalidas +=1;
}
}

media = soma_pares/i;

printf("A media de %d valores positivos pares foi = %.2f \n",i,media);
printf(" %d tentativas invalidas", tentativas_invalidas);

    return 0;
}