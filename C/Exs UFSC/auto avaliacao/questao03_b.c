#include <stdio.h>

int main (){

int vet[10] = {1,2,3,4,5,6,7,8,9,10};

int i;
int soma = 0;


for (i=0;i<10;i++){

    if(vet[i] % 2 == 0){
        vet[i] = -1;
    }
}

for (i=0;i<10;i++){
 printf("%d ", vet[i]);
}

    return 0;
}