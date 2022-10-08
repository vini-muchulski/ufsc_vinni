*/ Escreva um programa que recebe uma quantidade arbitrária de números 
inteiros e mostra qual foi o menor número ímpar*/

#include <stdio.h>


int main(){
int num,i;
int menor;

i=0;

while (num != 0){

    printf("Digite um valor [0 Break]: \n");
    scanf("%d",&num);

    if(i==0){
        menor = num;

    }

    if (i !=0){
        if (num<menor && num%2!=0){
           menor = num; 
        }
    }
i++;

}
printf("MENOR NUMERO IMPAR = %d", menor);

return 0;
}