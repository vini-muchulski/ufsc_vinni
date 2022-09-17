#include <stdio.h>

int main(){
    float nota1, nota2 , media;

    printf("Digite o valor da primeira nota: \n");
    scanf("%f", &nota1);

    printf("Digite o valor da segunda nota: \n");
    scanf("%f", &nota2);

    media =(nota1+nota2)/2;

    printf("\n A nota final foi de %.2f", media);

    return 0;
}
