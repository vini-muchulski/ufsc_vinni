#include <stdio.h>

int main(){

    int const tamanho = 5;
    int i;
    int vet[5];

    int maior = 0;
    int menor = 0;

    printf("Digite %d valores: \n", tamanho);
    for ( i = 0; i < tamanho; i++)
    {
     scanf("%d", &vet[i]);
    }

    for ( i = 0; i < tamanho; i++)
    {
     if(i==0){
        maior = vet[i];
        menor = vet[i];
     }
     else{
        if (vet[i]>maior){
            maior = vet[i];
        }
        if (vet[i]<menor){
            menor = vet[i];
        }
     }
    }
    printf("MAIOR = %d  -- MENOR = %d", maior,menor);

    return 0;
}