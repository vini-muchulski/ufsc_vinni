#include <stdio.h>
#define tam 25
//remove espacos

int main(){
    int i,j;

    int tamanho_vet = tam;

    char Vet[tam]= "sem espacos e vini";


     for(i=0; i<tamanho_vet; i++){
        if(Vet[i]==' '){
            Vet[i]=Vet[i+1];

            for (j=i;j<tamanho_vet;j++){
            Vet[j]=Vet[j+1];
            }
        }
    }
    printf("String sem espacos em branco: \n%s \n", Vet );

    return 0;
}
