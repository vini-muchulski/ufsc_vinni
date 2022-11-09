//Escreva uma função int reverse (int n) que recebe um número inteiro e retorna um número inteiro com a ordem dos dígitos invertida.

#include <stdio.h>
#include <string.h>

int reverse(int n);

int main(){

int a;

a = reverse(431);
printf("numero %d", a);
printf("\n---------------------------------\n");
a = reverse(97631);
printf("numero %d", a);

    return 0;
}

int reverse(int n){
    int v[50];
    int cont =0;
    int algarismo;
    int numero;
    int i;

    int numero_return = 0;
    int vet_exp[6];

    int a,k;
    a=1;
    
    // pega algarismo e gera vetor com eles em posicoes invertidas
    while (n%10 !=0){
        algarismo = n%10;
        numero = n/10;
        n = numero;

        v[cont] = algarismo;

        cont++;


    }
    // mostra numero inverso
    for (i=0;i<cont;i++){
        printf("%d ", v[i]);
    }
    printf("\ncont %d\n", cont);


    // vetor para gerar a casa decimal do algarismo dps na hora da soma
    for (i=0;i<cont;i++){
        for(k=0;k<=i;k++){
            a = a*10;

        }
        vet_exp[i] = a;
        a=1;
    }

    for (i=0;i<cont;i++){
        printf("%d ", vet_exp[i]);
    }

    printf("\n");



    for (i=0;i<cont;i++){
        numero_return += v[i]*vet_exp[cont-i-1];
    
    }
    return numero_return/10;
}