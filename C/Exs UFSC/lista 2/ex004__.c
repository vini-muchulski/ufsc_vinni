#include <stdio.h>

int main(){

    /* • Criar vetores a, b e c com 10 elementos do tipo int;
• Os valores dos elementos de a podem ser fornecidos pelo usuário ou 
pre definidos.
• O vetor b deve conter os elementos positivos de a
• O vetor c deve conter os elementos negativos de a */

 int a[10]= {0,0,0,0,0,0,0,0,0,0};
int i,contb,contc;
 int b[10]= {0,0,0,0,0,0,0,0,0,0};
 int c[10] = {0,0,0,0,0,0,0,0,0,0};

 contb = contc = 0;

 for (i=0;i<10;i++){
    printf("Digite um valor para o elemento %i : \n", i);
    scanf("%i", &a[i]);

    if (a[i]>0){
        b[contb] = a[i];
        contb +=1;
    }

     if (a[i]<0){
        c[contc] = a[i];
        contc +=1;
    }

 }


printf("Vetor A \n");

 for (i=0;i<10;i++){
    
        printf(" %i ",a[i]);
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