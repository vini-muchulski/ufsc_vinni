/* [7] Dado um vetor com dados de 50 alturas, escreva um algoritmo que permita calcular:
(a) A m�dia das alturas;
(b) A moda das alturas. Lembrando que moda � o valor que possui maior incid�ncia de repeti��es
*/

#include <stdio.h>
#define tamanho 10


int main(){

int vet [tamanho] = {1,2,3,4,5,6,7,8,9,1};
int vetAux[tamanho] = {0};

int i;
int j;

int cont = 0;
float media = 0;

int rep_var = 0;
int var;

int maior,posicao;
int moda;


            // media
            for (i=0;i<tamanho;i++){
                cont += vet[i];
            }
            media = (float) cont/tamanho;
            printf("media = %f, cont = %d \n", media,cont);
            printf("\n");

            // conta quantas vezes cada numero apareceu
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
            

            // imprime os vetores com a quantidade de repeticao de cada valor
            for(i=0;i<tamanho;i++){
                printf(" %d ", vetAux[i]);
            }
            printf("\n");

            // gera a moda
            for(i=0;i<tamanho;i++){
                if (i==0){
                    maior = vetAux[i];
                    posicao = i;
                }
                else{
                    if(vetAux[i]>maior){
                         maior = vetAux[i];
                         posicao = i;

                    }
                }
            }

            printf("MODA  = %i - \nREPETIU %i VEZES", vet[posicao],maior);

                return 0;
            }