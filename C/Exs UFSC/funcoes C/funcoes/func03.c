//Escreva o programa que de forma repetida recebe pares de números inteiros  e mostra qual dos dois números é menor com auxílio da função


#include <stdio.h>
#include <stdlib.h>

int max_min(int n1,int n2);

int main(){
    int n1,n2;
    printf("Digite um valor: \n");
    scanf("%d", &n1);

    printf("Digite outro valor: \n");
    scanf("%d", &n2);
    max_min(n1,n2);

    //printf("O maior valor foi %d ===== Menor valor %d", max.max_min(),max_min());

    return 0;
}

int max_min(int n1,int n2){

    static int max;
    static int min;

    if(n1<n2 && n1<min){
        min = n1;
    }

    if(n2<n1 && n2<min){
        min = n2;
    }


    if(n2>n1 && n2>max){
        max = n2;
    }

    if(n1>n2 && n1>max){
        max = n1;
    }

    printf("O maior valor foi %d ===== Menor valor %d", max,min);
    return max,min;

}