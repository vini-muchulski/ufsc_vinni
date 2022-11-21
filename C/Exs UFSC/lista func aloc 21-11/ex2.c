// escreva um programa que leia o tamanho de um vetor, aloque dois vetores inteiros (com este tamanho), dinamicamente e calcule o produto escalar;

#include <stdio.h>
#include <stdlib.h>



int main(){

int tamanho;
int i;
int prod_escalar = 0;

printf("Digite o tamanho do vetor: ");
scanf("%d", &tamanho);

int *vet_a = malloc(tamanho*sizeof(int));

int *vet_b = malloc(tamanho*sizeof(int));

for (i=0;i<tamanho;i++){
    printf("VETOR A - Digite o elemento [%d]: \n",i);
    scanf("%d", &vet_a[i]);
}

for (i=0;i<tamanho;i++){
    printf("VETOR B - Digite o elemento [%d]: \n",i);
    scanf("%d", &vet_b[i]);
}

for (i=0;i<tamanho;i++){
    prod_escalar = prod_escalar + vet_b[i]*vet_a[i];
}

printf(" Produto escalar = %d", prod_escalar);



return 0;
}