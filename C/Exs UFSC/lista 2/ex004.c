#include <stdio.h>

int main(){

    /* • Criar vetores a, b e c com 10 elementos do tipo int;
• Os valores dos elementos de a podem ser fornecidos pelo usuário ou 
pre definidos.
• O vetor b deve conter os elementos positivos de a
• O vetor c deve conter os elementos negativos de a */

 int a[10];
int i;
 int b[10];
 int c[10];

 for (i=0;i<10;i++){
    printf("Digite um valor para o elemento %i : \n", i);
    scanf("%i", &a[i]);

    if (a[i]>0){
        b[i] = a[i];
        c[i] = 0;
    }

     if (a[i]<0){
        c[i] = a[i];
        b[i] = 0;
    }

 }



 /* VERIFICAR SE OS ZEROS ALI NO MEIO ESTAO CERTOS */



printf("Vetor A \n");

 for (i=0;i<10;i++){
    
        printf("%i ",a[i]);
}

printf("\n Valores positivos  \n ");
 for (i=0;i<10;i++){
    
        printf(" %i  ",b[i]);
}

printf("\n Valores negativos \n");
 for (i=0;i<10;i++){
    
        printf(" %i ",c[i]);
}

return 0;
}