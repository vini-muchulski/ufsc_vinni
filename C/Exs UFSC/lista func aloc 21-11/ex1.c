#include <stdio.h>

// funcao que recdbe dois valores e determina o seu valor maximo e minimo

void valores(int *v, int *menor , int *maior, int tamanho);

int main(){

        int vet[5] = {1,-2,9,3,4};

        int maior, menor;

        int tamanho = 5;

        valores(vet, &menor, &maior, tamanho);

        printf(" maior %d ----- menor %d", maior,menor);


return 0;
}

void valores(int *v, int *menor , int *maior, int tamanho){
        int i;

        for(i=0;i<tamanho;i++){
        if(i==0){
            *menor = v[i];
        }
        else{
            if (v[i]<*menor){
                *menor = v[i];
            }
        }
        }


    // maior

        for(i=0;i<tamanho;i++){
        if(i==0){
            *maior = v[i];
        }
        else{
            if (v[i]>*maior){
                *maior = v[i];
            }
        }

        }
    }
