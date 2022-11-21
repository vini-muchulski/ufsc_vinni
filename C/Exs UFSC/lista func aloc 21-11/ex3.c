//escreve uma funcao que receba dois vetores (alocados dinamicamente) e devolva a soma destes vetores

#include <stdio.h>
#include <stdlib.h>

void soma_f(int *veta, int *vetb,int *soma, int tamanho);

int main(){

int tamanho;
int i;

printf("Digite o tamanho do vetor: ");
scanf("%d", &tamanho);


int *vet_a = malloc(tamanho*sizeof(int));

int *vet_b = malloc(tamanho*sizeof(int));




for (i=0;i<tamanho;i++){
    printf("VETOR A - Digite o elemento [%d]: \n",i);
    scanf("%d", &vet_a[i]);
}

for (i=0;i<tamanho;i++){
    printf("VETOR B - Digite o elemento [%d]: \n",i);
    scanf("%d", &vet_b[i]);
}

for (i=0;i<tamanho;i++){
                printf(" %d \n", vet_a[i]);
           }


for (i=0;i<tamanho;i++){
                printf(" %d \n", vet_b[i]);
           }




int *soma =  malloc(tamanho*sizeof(int));

soma_f( vet_a, vet_b, soma,  tamanho);

    for (i=0;i<tamanho;i++){
                printf(" %d \n", soma[i]);
           }

return 0;
 }









void soma_f(int *veta, int *vetb,int *soma, int tamanho){
    int i;
    for (i=0;i<tamanho;i++){
        soma[i] = veta[i] + vetb[i];

    }

}