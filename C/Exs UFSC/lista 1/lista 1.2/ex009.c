#include <stdio.h>

/* Escreva um programa que recebe uma quantidade arbitrária de números 
inteiros positivos e calcula a soma dos números pares.
*/

int main(){
int num,som,i;
som =0;

printf("Digite um valor inicial: \n");
scanf("%d",&num);

while (num != 0){

    if(num%2 ==0){
    som +=num;
    }

    printf("Digite um valor [0 Break]: \n");
    scanf("%d",&num);


}

printf("A soma total dos pares foi %d", som);


    return 0;
}