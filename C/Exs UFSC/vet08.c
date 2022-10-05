#include <stdio.h>
#define tam 25

// transforma minusculas em maiusculas

int main(){
 int i;

 char Vet[tam]= "OLA MUNDO e pessoas";

 for (i=0;i<tam;i++){
    if(Vet[i]>=97 && Vet[i]<=122){
        //printf("%c", Vet[i]);
         Vet[i] =  Vet[i] -32;
         //printf("%c", Vet[i]);
 }
 }

for (i=0;i<tam;i++){
    printf("%c",Vet[i]);
}


    return 0;
}