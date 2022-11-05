//Escreva uma função int reverse (int n) que recebe um número inteiro e retorna um número inteiro com a ordem dos dígitos invertida.

#include <stdio.h>

int reverse(int n);

int main(){

reverse(20);

    return 0;
}

int reverse(int n){
    int contador = 0;

    //len caseiro

    while(n/10>0){
        contador++;
    }

    printf("contador %d", contador);


}