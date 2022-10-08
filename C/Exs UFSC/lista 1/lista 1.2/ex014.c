/*Escreva um programa que recebe uma quantidade arbitrária de números reais
(float) e mostra qual foi o maior número negativo*/

#include <stdio.h>


int main(){
float num;
int i;
float maior;


i=0;

while (num != 0){

    printf("Digite um valor [0 Break]: \n");
    scanf("%f",&num);

    if(i==0){
        maior = num;
    }
    if(num<0 && num>maior){
        maior = num;
    }
i++;

}
printf("maior NUMERO negativo = %.2f", maior);

return 0;
}