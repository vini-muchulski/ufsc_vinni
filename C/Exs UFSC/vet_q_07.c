/* [7] Dado um vetor com dados de 50 alturas, escreva um algoritmo que permita calcular:
(a) A média das alturas;
(b) A moda das alturas. Lembrando que moda é o valor que possui maior incidência de repetições
*/

#include <stdio.h>
#define tamanho 10
int main(){

int vet [tamanho] = {1,2,3,4,5,6,7,8,9,1};
int vetAux[tamanho] = {0,0,0,0,0,0,0,0,0,0};

int i;
int cont = 0;
float media = 0;

int rep_var = 0;

int var;
int j;


// media
for (i=0;i<tamanho;i++){

    cont += vet[i];

}

media = (float) cont/tamanho;

printf("media = %f, cont = %d", media,cont);


for (i=0;i<tamanho;i++){
        var = vet[i];

        for(j=i;j<tamanho;j++){
            if (vet[j] == var){
                rep_var +=1;
            }


        }
        vetAux[i] = rep_var;
        rep_var = 0;


}

for(i=0;i<tamanho;i++){
    printf("\n %d ", vetAux[i]);
}



    return 0;
}
