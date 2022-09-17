#include <stdio.h>

int main(){
    int reais, dolares;
    printf("Quantos dolares vc quer comprar? ");
    scanf("%d", &dolares);

    reais = dolares*5;

    printf("Para comprar US$ %d  voce precisara de R$ %d ", dolares,reais);

    return 0;
}
