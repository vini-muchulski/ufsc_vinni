/*• Criar vetor a com 10 elementos e vetor b com 5 elementos int.
• Criar função e fazer uso da função que substitui todos os elementos 
negativos do vetor a pelo valor do maior elemento do vetor b.
• Fazer uso da função auxiliar para achar o maior elemento de um vetor.*/

#include <stdio.h>
#include <stdlib.h>

int maior_valor(int *b, int n);
int substitui(int *a,int *b,int nA,int nB);



    int main(){
    int const tamanho_a = 10;
    int vet_a[10]= {-2,-1,0,3,4,5,6,7,8,-9};

    int const tamanho_b = 5;
    int vet_b[5]= {-2,-1,5,3,4};

    int i;
    int x = substitui(vet_a,vet_b,tamanho_a,tamanho_b);

    for(i=0;i<tamanho_a;i++){
        printf("%d ", vet_a[i]);
    }


    return 0;
}


int maior_valor(int *b, int n){

    int i;
    int maior;

    for(i=0;i<n;i++){
        if (i ==0){
            maior = b[i];
        }
        else{
            if (b[i]>maior){
                maior = b[i];
            }
        }
    }
    return maior;
}

int substitui(int *a,int *b,int nA,int nB){
    int i;
    int maior = maior_valor(b, nB);

    for(i=0;i<nA;i++)
    {
        if(a[i]<0){
            a[i] = maior;
        }
    }

}

