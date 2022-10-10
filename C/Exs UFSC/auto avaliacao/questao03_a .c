#include <stdio.h>

int main (){

int vet[10] = {1,2,3,4,5,6,7,8,9,10};

int k,i;
int soma = 0;

printf("digite um numero K: \n");
scanf("%d", &k);

for (i=0;i<10;i++){

    if(vet[i]>k){
        soma +=vet[i];
    }
}

printf("A soma dos elementos maiores que %d no vetor foi = %d", k,soma);



    return 0;
}