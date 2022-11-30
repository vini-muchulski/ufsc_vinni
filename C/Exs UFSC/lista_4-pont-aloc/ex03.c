        /* • Criar vetor a com 10 elementos int.
    • Criar e fazer uso da função:
    ◦ msum retorna a soma do maior elemento do vetor com o menor 
    elemento do mesmo vetor int msum (int v [ ], int n) ou int msum 
    (int * v, int n)
    ◦ Essa função por sua vez deve fazer a chamada de duas funções 
    auxiliares que vão receber o vetor retornar o valor do elemento 
    máximo e o valor do elemento mínimo. */

#include <stdio.h>
#include <stdlib.h>

int msum (int * v, int n);
int maior (int * vet, int n);
int menor (int * vet, int n);


int main(){

int const tamanho = 10;
int var;

// int vet[tamanho] = {-1,2,3,4,5,6,7,8,9,10};
int vet[10] = {-1,2,3,4,5,6,7,8,9,10};

var = msum(vet,tamanho);

printf("A soma dos valores = %d", var);

    return 0;
}


int msum (int * vet, int n){

    int somas;

    somas = menor(vet,n) + maior(vet,n);

    return somas;

}


int maior (int * vet, int n){

    int maior = 0;
    int i;

    for(i=0;i<n;i++){
        if(i==0){
            maior = vet[i];
        
        }
        else{
            if(vet[i]> maior){
                maior = vet[i];
            }
        }
    }
    return maior;
}


int menor (int * vet, int n){

    
    int menor = 0;
    int i;

    for(i=0;i<n;i++){
        if(i==0){
           
            menor = vet[i];

        }
        else{
            if(vet[i]<menor){
                menor = vet[i];
            }
        }
    }
    return menor;

}