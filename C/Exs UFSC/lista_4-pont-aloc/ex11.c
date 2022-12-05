/* Criar o vetor a com a quantidade de elementos determinada pelo
usuário.
• Criar o vetor b contendo os elementos pares do vetor a. 
• Criar o vetor c contendo os elementos positivos do vetor a
• Os vetores b e c devem ser criados dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main(){
    int tam;
    int *a,*b,*c;
    int i;
    int qnt_pares= 0;
    int positivos = 0;

    printf("Digite o tamanho de a: \n");
    scanf("%d", &tam);

    a = (int*) (malloc(tam*sizeof(int)));

    if ( a == NULL){
        printf("erro de alocacao de memoria");

    }
    for (i=0; i< tam; i++){
        printf("Digite o valor do elemento %d: \n",i);
        scanf("%d", &a[i]);
    }

    for (i=0; i< tam; i++){
        if (a[i]>0){
            positivos++;
            
        }
        if (a[i]%2 == 0){
            qnt_pares++;
            
        }

    }
    b = (int*) (malloc(qnt_pares*sizeof(int)));
    c = (int*) (malloc(positivos*sizeof(int)));

    for (i=0; i< tam; i++){
        if (a[i]>0){
            
            c[i] = a[i];
            
        }
        if (a[i]%2 == 0){
            b[i] = a[i];
             
        }

    }
    printf("\n Vetor B - Pares \n");
    for (i=0; i< qnt_pares; i++){
        printf("%d ",b[i]);
        
    }

    printf("\n Vetor C - Positivos \n");
    for (i=0; i< positivos; i++){
        printf("%d ",c[i]);
        
    }

    return 0;
}
