/*Escreva um programa que permita armazenar dados sobre o estoque de vinhos
de uma adega*/

#include <stdio.h>

int main(){

int tinto,rose,branco,opcao,incluir,remover;

opcao = 0;

tinto=rose=branco=0;

while (opcao !=4){

printf("MENU \n1 para vinho tinto \n2 para vinho branco \n3 para vinho rosê \n4 Sair \n");
scanf("%d", &opcao);



if (opcao == 1){
    printf("Quantos TINTOS deseja incluir? \nEstoque atual: %d \n", tinto);
    scanf("%d", &incluir);
    tinto +=incluir;

    printf("E quantos TINTOS deseja remover? \nEstoque atual: %d \n", tinto);
    scanf("%d", &remover);
    tinto -=remover;

    printf("ESTOQUE RESULTANTE: %d \n", tinto);
}

if (opcao == 2){
    printf("Quantos vinhos BRANCOS deseja incluir? \nEstoque atual: %d \n", branco);
    scanf("%d", &incluir);
    branco +=incluir;

    printf("E quantos vinhos BRANCOS deseja remover? \nEstoque atual: %d \n", branco);
    scanf("%d", &remover);
    branco -=remover;

    printf("ESTOQUE RESULTANTE: %d \n", branco);
}

if (opcao == 3){
    printf("Quantos vinhos ROSE deseja incluir? \nEstoque atual: %d \n", rose);
    scanf("%d", &incluir);
    rose +=incluir;

    printf("E quantos vinhos ROSES deseja remover? \nEstoque atual: %d \n", rose);
    scanf("%d", &remover);
    rose -=remover;

    printf("ESTOQUE RESULTANTE: %d \n", rose);
}

}

printf("FIM");
    return 0;
}