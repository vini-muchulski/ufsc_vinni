#include <stdio.h>



int main(){

int tamanho = 5;

int vetor[5] = {0,9,2,8,1};

OrdenarCrescente(vetor, tamanho);
    return 0;
}

void OrdenarCrescente(int vetor[], int tamanho){
    int i,j,temp;
    

    for (i = 0; i< tamanho;  i++){
        for(j=i+1;j<tamanho;j++){
            if(vetor[i]>vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                
            }
        }
    }
    
    for (i=0;i<tamanho;i++){
        printf("%d ", vetor[i]);
        }
}
