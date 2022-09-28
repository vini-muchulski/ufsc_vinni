#include <stdio.h>

int main(){

int i, soma;
soma = 0;

for (i = -10;i<=20;i =i + 5){
 soma = soma + i;
}

printf("%d \n", soma);
return 0;
}
