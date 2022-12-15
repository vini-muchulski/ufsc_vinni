#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int i;
    float vet[10];

    for(i=0;i<10;i++){
    printf("digite um valor para o elemento %d \n",i);
    scanf("%f", &vet[i]);
    
 }
    printf("vetor original \n");
    for(i=0;i<10;i++){
    printf(" %.2f ",vet[i]);
    }

    printf("\nvetor reverso \n");
    for(i=0;i<10;i++){
    printf(" %.2f ",vet[9-i]);
    }
    

    
 

    return 0;
}