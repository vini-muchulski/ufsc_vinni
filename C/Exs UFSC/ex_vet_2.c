#include <stdio.h>
//produto vetorial de dois arrays

int main(){
int i;

float soma, produto;

soma = 0;

float v[4] = {1,2,3,4};
float u[4] = {1,2,3,4};

for (i = 0;i<4;i++){
 produto = u[i]*v[i];
 soma += produto;
}

printf("Produto escalar = %.2f",soma);
return 0;
}
