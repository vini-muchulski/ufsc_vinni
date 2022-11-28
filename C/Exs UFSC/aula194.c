#include <stdio.h>

int main(){
int vet[10];
int i;


for( i=0;i<10;i++)
{
    printf("Digite o %d valor do vetor: \n", i);
    scanf("%d", &vet[i]);
}


for( i=0;i<10;i++)
{
    printf("Valor do vet[%d] = %d \nEndereco = %p \n",i,vet[i], &vet[i]);
    printf("\n");
}



    return 0;
}