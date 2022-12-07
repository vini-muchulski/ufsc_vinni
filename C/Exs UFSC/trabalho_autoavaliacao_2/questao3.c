#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int *matriz_vet;

matriz_vet = (int*)malloc(5*4*(sizeof(int)));

int i,j,m;

for(i=0;i<20;i++){
 matriz_vet[i] = 0;
}

// elemento mat 3 -2;
int elemento;

elemento = 3*4 + 2;
matriz_vet[elemento] = 15;
for(i=0;i<20;i++){
printf(" %d ", matriz_vet[i]);
}


    return 0;
}