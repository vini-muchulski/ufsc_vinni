#include <stdio.h>

    typedef struct numeros_struct
    {
        int n1s,n2s;
    }numeros_struct;

    int soma( numeros_struct y){

    int soma = 0;

    soma = y.n1s + y.n2s;

    printf("soma %d \n", soma);
    }



    int subtracao( numeros_struct y){

    int sub;

    sub = y.n1s - y.n2s;

    printf("subtracao %d \n", sub);
    }

    int multiplicacao( numeros_struct y){

    int sub;

    sub = y.n1s * y.n2s;

    printf("mult %d \n", sub);
}


    float divisao(numeros_struct y){

    float sub;

    sub =  (float) y.n1s / y.n2s;

    printf("div %.2f \n", sub);
    }



        int main(){

        struct numeros_struct numero1;
        printf("Digite um valor: \n");
        scanf("%d", &numero1.n1s);

        printf("Outro valor: \n");
        scanf("%d", &numero1.n2s);

        //printf("A SOMA DOS VALORES = %d", numero1.n1s+numero1.n2s);

        soma(numero1);
        subtracao(numero1);
        multiplicacao(numero1);
        divisao(numero1);

        return 0;

        }

