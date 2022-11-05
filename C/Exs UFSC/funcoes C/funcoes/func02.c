// Escreva uma função int fatorial (int N) que calcula N! (fatorial de N), sendo que o valor inteiro (positivo) N é fornecido pelo usuário.

#include <stdio.h>
#include <stdlib.h>

int fatorial( int n);

int main(){
    int n;

    printf("Digite o valor: \n");
    scanf("%d", &n);

    printf("O fatorial de %d = %d", n, fatorial(n));

    return 0;
}

int fatorial(int n){
    if(n<0){
        printf("Nao existe fatorial de numero negativo");
       
    }
    else{
    int k,i;
    k = 1;
    for(i=n;i>1;i--){
        k = k*i;
    }
    return k;
    }
}