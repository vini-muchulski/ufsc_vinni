/* Criar o vetor a com a quantidade de elementos definida pelo usuário.
• Criar o vetor b com a quantidade de elementos definida pelo usuário.
• Ciar o vetor c contendo os elementos pares do vetor a e os elementos 
pares do vetor b.
Exemplo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
int i, tam_a, tam_b;
int *a,*b,*c;
int qnt_pares = 0;
int cont =0;


//cria vetor a
printf("Digite o tamanho do vetor A: \n");
scanf("%d", &tam_a);

a = (int*) malloc(tam_a*sizeof(int));

 for (i=0; i< tam_a; i++){
        printf("Digite o valor do elemento %d: \n",i);
        scanf("%d", &a[i]);
        if (a[i]%2 == 0){
            qnt_pares++;
        }
    }


//cria vetor b
printf("Digite o tamanho do vetor B: \n");
scanf("%d", &tam_b);

b = (int*) malloc(tam_b*sizeof(int));

 for (i=0; i< tam_b; i++){
        printf("Digite o valor do elemento %d: \n",i);
        scanf("%d", &b[i]);
        if (b[i]%2 == 0){
            qnt_pares++;
        }
    }




//pega elementos de b e a

c = (int*) malloc (qnt_pares*sizeof(int));


for(i=0;i<tam_a;i++){
    if (a[i]%2 == 0){
        c[cont] = a[i];
        cont++;
    }

}

for(i=0;i<tam_b;i++){
    if (b[i]%2 == 0){
        c[cont] = b[i];
        cont++;
    }

}



for(i=0;i<qnt_pares;i++){
    printf("%d ", c[i]);

}


    return 0;
}
