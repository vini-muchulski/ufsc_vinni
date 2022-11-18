/* Criar vetor a com 10 elementos do tipo int.
• Criar e fazer uso das funções:
◦ impar que recebe vetor e retorna a quantidade dos elementos 
ímpares no vetor com protótipo:
int impar (int v [ ], int n) ou int impar (int * v, int n)
◦ sump que recebe vetor e retorna a soma dos elementos positivos no
vetor com protótipo: int sump (int v [ ], int n) ou int sump (int * v, 
int n)
*/

#include <stdio.h>
#include <stdlib.h>

int impar (int * v, int n);
int sump (int * v, int n);


int main(){

int tamanho = 10;

int vet[10] = {-1,2,3,4,5,6,7,8,9,10};

int impares;
int positivos;

impares = impar(vet,tamanho);

printf("\n Quantidade de impares = %d", impares);

positivos = sump(vet,tamanho);

printf("\n Quantidade de positivos = %d", positivos);


    return 0;
}

 int impar (int * v, int n)
{

    int i;
    int qnt_impares = 0;

    for(i=0;i<n;i++){
        
        if (v[i]%2 != 0){
            qnt_impares +=1;
        }
    }
    return qnt_impares;

}

int sump (int * v, int n){

    int i;
    int qnt_pos =0;

for(i=0;i<n;i++){
if(v[i]>0){
    qnt_pos+=1;
}

}
return qnt_pos;



}