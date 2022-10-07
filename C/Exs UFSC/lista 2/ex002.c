#include <stdio.h>

int main(){
/*
criar vetor com 10 elementos do tipo float
calcular o valor médio dos elementos
imprimir os elementos do vetor que estão acima da média com suas 
respectivas posições 
*/

float vet[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

float media;

int i,soma;

soma = 0;

for (i=0;i<10;i++){
    soma = soma + vet[i];

}
 media = soma/10;

 printf("O valor médio foi %.2f \n Valores acima da media \n", media);

for (i=0;i<10;i++){
    if (vet[i]>=media){
        printf("%.2f \n",vet[i]);
    }
}

return 0;
}




