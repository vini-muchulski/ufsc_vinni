/*
6.] Dados dois vetores de caracteres, um contendo uma palavra e outro uma frase. Escreva um
algoritmo que determine o número de vezes que a palavra ocorre na frase. Exemplo: A palavra “ara”
aparece 6 vezes na frase: “Raras araras vivem em Araranguá e Araraquara”.

*/

#include <stdio.h>
int main(){

char vet [50] = "Raras araras vivem em Araranguá e Araraquara";
char buscar[3] = {"ara"};


int i;
int cont = 0;

for (i=0;i<50;i++){
    if( vet[i]==buscar[0] && vet[i+1]==buscar[1] && vet[i+2]==buscar[2]){
        cont +=1;

    }
}

printf("%d", cont);


    return 0;
}
