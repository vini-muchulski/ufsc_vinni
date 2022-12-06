#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
FILE *aptr;

aptr = fopen("out.txt", "w");

if( aptr == NULL){
    printf("Erro de alocacao");
    return 1;
}

int i;
int tam;

printf("digite o tamanho do vetor: \n");
scanf("%d", &tam);

int *vet = (int*) malloc (tam*sizeof(int));

for (i=0;i<tam;i++){
    printf("digite o uma valor para [%d]: \n", i);
    scanf("%d", &vet[i]);
}
for (i=0;i<tam;i++){
    printf("%d ",vet[i]);
    
}


for (i=0;i<tam;i++){
    if(vet[i]%2 == 0){
        fprintf(aptr, "%d\n", vet[i]);
        
    }
    
}


    return 0;
}

