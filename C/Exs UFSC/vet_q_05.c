#include <stdio.h>

/* [5] Escreva um programa que receba uma string e verifique se ela é um palíndrome, ou seja, uma
palavra ou frase que pode ser lida da esquerda para a direita e da direita para a esquerda. Ex. Saudável
leva duas.
*/



int main(){

char vet [15] = "saudavel";
char vet2 [15] = "leva duas";
char vet2aux[15];

int tam = 15;

int i,j;

int cont = 0;

for(i=0;i<tam-cont;i++){

    if (vet2[i]==32){
            for(j=i;j<tam-cont;j++){
                vet2[j] = vet2[j+1];

            }

         cont +=1;
    }
}


for(i=0;i<tam-cont;i++){

    printf("%c", vet2[i]);
}


    return 0;
}
