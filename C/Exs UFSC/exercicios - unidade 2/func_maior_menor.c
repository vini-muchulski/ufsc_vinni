#include <stdio.h>
int const tamanho = 5;
int main(){

    int i;
    int vet[5];

    int maior_numero = 0;
    int menor_numero = 0;

    printf("Digite %d valores: \n", tamanho);
    for ( i = 0; i < tamanho; i++)
    {
     scanf("%d", &vet[i]);
    }

    maior_numero = maior(vet);
    menor_numero = menor(vet);

    printf("MAIOR = %d  -- MENOR = %d", maior_numero,menor_numero);

    return 0;
}

int maior(int vet[]){

    int i;

    int maior = 0;

    for ( i = 0; i < tamanho; i++)
    {
     if(i==0){
        maior = vet[i];
        
     }
     else{
        if (vet[i]>maior){
            maior = vet[i];
        }

     }
    }
    return maior;

    return 0;
}


int menor(int vet[]){

    int i;

    int menor = 0;

    for ( i = 0; i < tamanho; i++)
    {
     if(i==0){
        menor = vet[i];
        
     }
     else{
        if (vet[i]<menor){
            menor = vet[i];
        }

     }
    }
    return menor;

    return 0;
}