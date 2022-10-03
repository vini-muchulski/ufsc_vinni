#include <stdio.h>

int main(){

int i,n;

printf("Digite o tamanho do vetor: \n");
scanf("%i", &n);

int vet[n];

for(i=0;i<n;i++){
printf("Digite o elemento: \n");
scanf("%i", &vet[i]);
}

for(i=n-1;i>=0;i--){
 printf("%d",vet[i]);
}



return 0;
}
