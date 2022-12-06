#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

FILE *aptr;

aptr = fopen("out.txt", "r");

if( aptr == NULL){
    printf("Erro de alocacao");
    return 1;
}

int num;
float media = 0;
int cont = 0;
int i;

while (fscanf(aptr, "%d", &num) == 1){
    printf(" numero %d ", num);
    printf("\n");

    if(num%2 ==0){
        media = media + num;
        cont++;
    }
}

media = media/cont;

printf("\n media = %.2f", media);


    return 0;
}

