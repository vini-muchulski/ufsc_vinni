#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

int vet_A[15] = {1,2,3,4,5,6,7,8,0,0,0,0,0,0,0};
int *b;
int *c;
int i;
int cont_impares = 0;
int k;
int cont_maiores_k = 0;
int cont_b = 0;
int cont_c = 0;

for(i=0;i<15;i++){
    if(vet_A[i]%2 == 1){
        cont_impares++;
    }
}


// ----------------------------------------------
b = (int*) malloc(cont_impares*sizeof(int));

printf("Digite um valor para K: \n");
scanf("%d", &k);

for(i=0;i<15;i++){
    if(vet_A[i]%2 == 1){
        b[cont_b] = vet_A[i];
        cont_b++;
    }
}

for(i=0;i<cont_impares;i++){
    if(b[i]>k){
        cont_maiores_k++;
    }
}

c = (int*) malloc(cont_maiores_k*sizeof(int));

for(i=0;i<cont_impares;i++){
    if(b[i]>k){
        c[cont_c] = b[i];
        cont_c++;

    }
}

//--------------------------------------------------------
//print vetores

printf("\n Vetor A\n");
for(i=0;i<15;i++){
    printf("%d ",vet_A[i]);
}

printf("\n Vetor B\n");
for(i=0;i<cont_impares;i++){
    printf("%d ",b[i]);
}

printf("\n Vetor C\n");
for(i=0;i<cont_maiores_k;i++){
    printf("%d ",c[i]);
}

    return 0;
}