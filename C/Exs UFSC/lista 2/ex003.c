#include <stdio.h>

int main(){


/* 
• criar vetor com 10 elementos do tipo int
• achar a soma dos elementos pares
• achar a soma dos elementos que se encontram nas posições com
índice par ( c[0], c[2], c[4])
*/



int vet [10]= {1,2,3,4,5,6,7,8,11,10};

int i, soma_pares,soma_pos;

i=0;
soma_pares = 0;
soma_pos = 0;

for (i=0;i<10;i++){
    if (vet[i]%2 == 0){
    soma_pares = soma_pares + vet[i];
    }
}

for (i=0;i<10;i = i +2){
soma_pos = soma_pos + vet[i];
}

printf("Soma dos pares = %i \nSoma dos indices pares = %i", soma_pares,soma_pos);


    return 0;
}