//Escreva o programa que de forma repetida recebe pares de números inteiros  e mostra qual dos dois números é menor com auxílio da função
// revisar - menor valor


#include <stdio.h>
#include <stdlib.h>

int max(int n1,int n2);

int main(){
    int n1;
    int max_valor;
    
    printf("Digite um valor: \n");
    scanf("%d", &n1);

    max_valor = n1;

    while(n1 != 0){

    printf("Digite outro valor:[0 BREAK] \n");
    scanf("%d", &n1);
    max_valor =  max(n1,max_valor);
    }

    printf("o maior valor foi %d", max_valor);

    return 0;
}

int max(int n1,int n2){

    int max;



    if(n2>n1 ){
        max = n2;
    }

    if(n1>n2){
        max = n1;
    }

    
    return max;

}