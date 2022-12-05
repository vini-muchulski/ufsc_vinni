/*• Criar um vetor a com 10 elementos do tipo int.
• Criar um vetor b com 10 elementos do tipo int.
• Criar um vetor de ponteiros vPtr que vai conter endereços de maior
elemento entre a[i] e b[i]:
Se a[i] > b[i]
 vPtr[i] vai apontar para elemento a[i]
caso contrario
 vPtr[i] vai apontar para b[i]*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int b[10] = {9,8,7,6,5,4,3,2,1,0};

int *vet_ptr[10];

int i;

for (i = 0;i<10;i++){
    if(a[i]>b[i]){
        vet_ptr[i] = a[i];
    }

    else{
        vet_ptr[i] = b[i];
    }
}

for( i=0;i<10;i++){
    printf("%d ", vet_ptr[i]);
}



    return 0;
}
