#include <stdio.h>

int main(){
int maior,i,posicao;

int n = 4;

int vet[n];

for(i=0;i<n;i++){
printf("Digite o elemento: \n");
scanf("%i", &vet[i]);
}

for (i=0;i<n;i++){
if (i==0){
 maior = vet[i];
 posicao = i;
}

else{
if (vet[i]>maior)
{
maior = vet[i];
posicao = i;

}

}
}
printf("MAIOR ELEMENTO: %d  POSICAO: %d", maior,posicao);
return 0;
}
