#include <stdio.h>

int main(){
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);

    if (valor % 2 ==0){
        printf("O numero %d eh PAR", valor);
    }
    else
    {
        printf("O numero %d eh IMPAR", valor);
    }
    return 0;
}
