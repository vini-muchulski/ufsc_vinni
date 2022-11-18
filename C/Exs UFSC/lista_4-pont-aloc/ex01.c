/*  Criar vetor a com 10 elementos float e vetor b com 15 elementos float.
• Ciar e fazer uso das funções a seguir:
◦ minv para achar o menor elemento em vetor com protótipo:
float minv (float v[ ], int n) ou float minv (float * v, int n)
◦ sumv para achar a soma dos elementos do vetor com protótipo: 
float sumv (float v[ ], int n) ou float sumv (float * v, int n) 
◦ meanv para achar o valor médio dos elementos do vetor com 
protótipo:
float meanv (float v[ ], int n) ou float meanv (float * v, int n)

*/

#include <stdio.h>
#include <stdlib.h>

float minv (float * v, int n);
float sumv (float * v, int n) ;
float meanv (float * v, int n);


int main(){

int tamanho = 10;
int tamanho_b = 15;

float vet[10] = {-1,1,2,3,4,5,6,-7,8,9};
float vetb[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

float menor_valor;
float soma_total;
float media;

float b_menor_valor;
float b_soma_total;
float b_media;

menor_valor = minv(vet,tamanho);

soma_total = sumv(vet,tamanho);

media = meanv(vet,tamanho);


printf("\n    VETOR A   \n");
 printf("\n menor valor = %.2f  \n",menor_valor);

 printf("\n media = %.2f \n",media);

 printf("\n soma =  %.2f \n",soma_total);

 b_menor_valor = minv(vetb,tamanho_b);

 b_soma_total = sumv(vetb,tamanho_b);

 b_media = meanv(vetb,tamanho_b);


printf("\n    VETOR B   \n");
 printf("\n menor valor = %.2f  \n",b_menor_valor);

 printf("\n media = %.2f \n",b_media);

 printf("\n soma =  %.2f \n",b_soma_total);

return 0;
}


float minv (float * v, int n)
{
    int i;
    float menor;
for(i=0;i<n;i++){
    if(i==0){
        menor = v[i];
    }
    else{
        if (v[i]<menor){
            menor = v[i];
        }
    }
    
}
    return menor;
}

 float sumv (float * v, int n) 
{
 int i;
 float soma = 0;

 for(i=0;i<n;i++){
    soma += v[i];
    
}
return soma;


}

float meanv (float * v, int n)
{


int i;
float soma = 0;
float media = 0;

for(i=0;i<n;i++){
    soma += v[i];
    
}
 media = soma/n;

 return media;





}



