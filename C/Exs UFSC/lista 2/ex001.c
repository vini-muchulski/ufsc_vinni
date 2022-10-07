#include <stdio.h>


/* • criar um vetor com 15 elementos 
• achar o maior e o menor elemento com suas respectivas posições */


int main(){
    int vet[15] = {1,2,3,4,5,6,7,8,9,10,0,87,22,54,15};

    int i, maior;
    i=0;
    maior=0;

    for (i=0;i<15;i++){
        if (i==0){
            maior = vet[i];
        }
        if (i !=0 ){
            if (vet[i]>maior){
                maior = vet[i];
            }
        }

    }

    printf("o maior digito foi %i ", maior);


    return 0;
}