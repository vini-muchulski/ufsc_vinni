/*Criar o vetor a com 15 elementos do tipo int
• Criar o vetor b composto por elementos positivos do vetor a
• Vetor b deve ser criado dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int i;

    int a[15] = {1,2,-1,-2,3,4};
    int *b;

    int qnt_positivos = 0;

    for (i=0;i<15;i++){
        printf("%d ", a[i]);
        if ( a[i]>0)
        {
            qnt_positivos++;
            
        }

    }
    
    printf("\n ");
    b = (int*) malloc(qnt_positivos*sizeof(int));

     for (i=0;i<15;i++){
        if ( a[i]>0)
        {
            b[i] = a[i];
        }
    }

    for (i=0;i<qnt_positivos;i++){
        printf("%d ", b[i]);
    }

    return 0;
}
