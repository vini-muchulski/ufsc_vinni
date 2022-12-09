/*• Criar vetor a com 10 elementos do tipo int.
• Criar função e fazer uso da função que recebe um vetor e um valor e 
verifica quantas vezes aquele valor aparece no vetor a com protótipo:
int count (int v [ ], int n, int k) ou int count (int * v, int n, int k)*/

#include <stdio.h>
#include <stdlib.h>

int verRep(int *vet,int tamanho, int numero);


int main(){

    int const tamanho_a = 10;
    int vet_a[10]= {2,2,0,3,4,5,6,7,8,2};

    int var;
    
    var = verRep(vet_a,tamanho_a,2);

    printf("O numero %d se repetiu = %d vezes", 2,var);



    return 0;
}

int verRep(int *vet,int tamanho, int numero){

    int i;
    int repeticoes = 0;

    for(i=0;i<tamanho; i++){
        if(vet[i]== numero){
            repeticoes++;
        }
    }

    return repeticoes;
}