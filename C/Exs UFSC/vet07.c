#include <stdio.h>

//remove espacos

int main(){
    int i;
    char Vet[]= "OLA MUNDO e pessoas";


     for(i=0; i<15; i++){
        if(Vet[i]==' '){
            Vet[i]=Vet[i+1];
            
        }
    }
    printf("String sem espacos em branco:%s \n", Vet );

    return 0;
}