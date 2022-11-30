/*• Criar vetor a com 10 elementos e vetor b com 5 elementos do tipo int.
• Criar função que recebe dois vetores (a e b) e substitui todos os 
elementos ímpares em vetor a pelo menor elemento do vetor b.
• Fazer uso da função auxiliar para achar o maior elemento de um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int menor_valor(int *b, int n);
int substitui(int *a,int *b,int nA,int nB);



    int main(){
    int const tamanho_a = 10;
    int vet_a[10]= {-2,-1,0,3,4,5,6,7,8,-9};

    int const tamanho_b = 5;
    int vet_b[5]= {-2,-1,5,3,4};

    int i;
    int x = substitui(vet_a,vet_b,tamanho_a,tamanho_b);

    for(i=0;i<tamanho_a;i++){
        printf("%4d ", vet_a[i]);
    }


    return 0;
}


int menor_valor(int *b, int n){

    int i;
    int menor;

    for(i=0;i<n;i++){
        if (i ==0){
            menor = b[i];
        }
        else{
            if (b[i]<menor){
                menor = b[i];
            }
        }
    }
    return menor;
}

int substitui(int *a,int *b,int nA,int nB){
    int i;
    int menor = menor_valor(b, nB);

    for(i=0;i<nA;i++)
    {
        if(a[i]%2 != 0){
            a[i] = menor;
        }
    }

}

