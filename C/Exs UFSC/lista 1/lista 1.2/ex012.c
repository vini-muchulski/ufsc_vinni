/*Escreva um programa que solicite ao usuário três números inteiros a, b, c. O
programa deve somar todos os inteiros entre b e c que sejam divisíveis por
número a.*/

#include <stdio.h>

int main(){
int a,b,c,i,n;
int soma_intervalo = 0;

printf("Digite  valor para A:\n");
scanf("%d",&a);
printf("Digite  valor para B:\n");
scanf("%d",&b);
printf("Digite  valor para C:\n");
scanf("%d",&c);

i = b;
n = c;

for (;i<=n;i++){
    if(i%a==0){
    soma_intervalo +=i;
}
}

printf("A soma do intervalo é %d", soma_intervalo);

return 0;
}