#include <stdio.h>
#define CONSTANTE 5

// Programação em Linguagem C - Ordenando Arrays com algoritmo Bubblesort -
// Algoritmo de classificação (ordenação) de arrays unidimensionais por bolhas, o Bubblesort, em linguagem C.

int main(){
 int vet[CONSTANTE];
 int i,aux,contador;

printf("Digite 5 valores para o array: \n");
for (i=0;i<CONSTANTE;i++){
    scanf("%d", &vet[i]);
}

printf("Ordem atual dos items: \n");

for (i=0;i<CONSTANTE;i++){
    printf("%3d", vet[i]);}

//algoritmo de classificacao

for (contador =1 ; contador<CONSTANTE;contador++){
    for(i=0;i<CONSTANTE-1;i++){
        if (vet[i]>vet[i+1]){
            aux = vet[i];
            vet[i]= vet[i+1];
            vet[i+1] = aux;
    }
    }
}
printf("\n Ordenacao: \n");
for (i=0;i<CONSTANTE;i++){
    printf("%3d", vet[i]);}


return 0;
}
