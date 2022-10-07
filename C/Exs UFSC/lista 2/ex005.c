#include <stdio.h>

/* • Criar vetores a, b com 5 elementos do tipo int e vetor c com 10
elementos;
• Os valores dos elementos de a e b podem ser fornecidos pelo usuário 
ou pre definidos.
• O vetor c deve conter os elementos de a e b de forma intercalada.*/

int main(){


 int a[5];
 int i;
 int b[5];
 int c[10] = {0,0,0,0,0,0,0,0,0,0};

 int cont_a = 0;
 int cont_b = 0;



    for (i=0;i<5;i++){
    printf("Digite um valor para o elemento A %i : \n", i);
    scanf("%i", &a[i]);

    }

    for (i=0;i<5;i++){
    printf("Digite um valor para o elemento B %i : \n", i);
    scanf("%i", &b[i]);

    }

    for(i=0;i<10;i++){

    if(i%2 == 0){
        c[i] = a[cont_a];
        cont_a +=1;

    }

    if(i%2 == 1){
        c[i] = b[cont_b];
        cont_b +=1;

    }
}

printf("Vetor C \n");


for (i=0;i<10;i++){
    printf("%i ", c[i]);
}

    return 0;
}