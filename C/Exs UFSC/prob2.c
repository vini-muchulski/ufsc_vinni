
/*
FILE: prob1.c
TITLE: RELATORIO DE TRABALHO DE LABORATORIO 2

SUBMITTED BY: Vinicius Wolosky Muchulski
FOR COURSE: Engenharia de computacao
DUE DATE: 9 de Dezembro de 2022

PURPOSE:
Programa que busca simular o funcionamento de um jogo da velha com dois jogadores

OVERALL METHOD:
É declarada uma função que busca facilitar o processo de impressão das matrizes ao longo do jogo;
Após a declaração das variaveis, a matriz do jogo é inicializada, com as posicoes livres equivalendo a um traço "-"
Logos após, inicia-se o jogo com o jogador 0 dando o primeiro lance na partida, assim as posicoes que equivalem ao 'O' são fornecidas por ele ao longo da partida, 
em seguida o processo se repete para o jogador 1, que usa o caracter 'X', e jogo vai se alternando.
O processo de verificação se houve algum jogador é dado verificado se todas as linhas, ou colunas, ou diagonais possuem o mesmo caracter
Esse processo é feito para cada caracter correspondente a cada jogador, isto é, testa-se se há algum alinhamento de 'X' ou 'O'
Há um limite de 9 tentativas para a partida que, caso seja atingido, gera a informação que mostra que ocorreu um empate no jogo;
Caso algum jogador venca conseguindo um alinhamento, o jogo para e é exibida a matriz com a informação de qual jogador ganhou.

FUNCTIONS:

func_print_matriz
    A funcao receberá uma matriz em forma de parametro e exibira para o usuario
    Ela foi posta no codigo para ser chamada apos cada iteração dos jogadores, mostrando assim o andamento do jogo


INCLUDED FILES:
stdio.h
stdlib.h
string.h

DATA FILES:
none
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_print_matriz(char matriz[3][3]);


int main(){

char matriz[3][3];

printf("Matriz de linhas e colunas de 0 ate 2 \nJogador 0 = O e Jogador 1 = X\n");

int linha_user = 0;
int coluna_user = 0;
int i;
int j;


int ganhador = -1;
int jg=0;
int tentativas= 0;


for(i=0;i<3;i++){
    for(j=0;j<3;j++){
         matriz[i][j] = '-';
    }
        
}
func_print_matriz(matriz);


jg = 0;

do{
// codigo para receber as coordenadas do jogador, verificar se sao validas e se nenhum valor foi jogado nesse msm coordenada anteriormente,
// no caso verifica se a coordenada esta livre para ser jogada por meio da checagem se o caracter gerado no inicio da matriz esta ali
do{ 
    printf("Jogador %d\n", jg);
    printf("Digite o valor da posicao [linha] [coluna] =\n");
scanf("%d", &linha_user);
scanf("%d", &coluna_user);

}

while( matriz[linha_user][coluna_user] != '-' ||  coluna_user>2 || coluna_user<0 || linha_user <0 || linha_user >2 );{
    if(jg == 0){
         matriz[linha_user][coluna_user] = 'O';
         jg = 1;
    }
    else{
         matriz[linha_user][coluna_user] = 'X';
         jg = 0;
    }
     

     func_print_matriz(matriz);
     tentativas++;
   
}
    // verifica se jogador 0 ganhou em alguma linha
    if( matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O' || matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O' || matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'){
        printf("fim de jogo! Jogador 0 Venceu!");
        ganhador = 0;
        
    }


    // verifica se jogador 0 ganhou em alguma coluna

    if( matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O' || matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O' || matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'){
        printf("fim de jogo! Jogador 0 Venceu!");
        ganhador = 0;
        
    }

    // verifica se jogador 0 ganhou na diagonais principal e secundaria

    //diagonal principal
    if(matriz[0][0] =='O' && matriz[1][1] =='O' && matriz[2][2] == 'O'){
        printf("fim de jogo! Jogador 0 venceu!");
        ganhador = 0;
        
    }
    //diagonal secundaria
    if(matriz[2][0] == 'O' && matriz[1][1] == 'O' && matriz[0][2] == 'O'){
        printf("fim de jogo! Jogador 0 venceu!");
        ganhador = 0;
        
    }



    // --------------------------------------

    // verifica se jogador 1 ganhou em alguma linha
    if( matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X' || matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X' || matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X'){
        printf("fim de jogo! Jogador 1 Venceu!");
        ganhador = 1;
        
    }



    // verifica se jogador 1 ganhou em alguma coluna
     if( matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X' || matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X' || matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){
        printf("fim de jogo! Jogador 1 'Venceu!");
        ganhador = 1;
        
    }

    // verifica se alguem ganhou nas diagonais principais e secundarias

    //diagonal principal
    if(matriz[0][0] =='X' && matriz[1][1] =='X' && matriz[2][2] == 'X'){
        printf("fim de jogo! Jogador 1 venceu!");
        ganhador = 1;
        
    }
    //diagonal secundaria
    if(matriz[2][0] == 'X' && matriz[1][1] == 'X' && matriz[0][2] == 'X'){
        printf("fim de jogo! Jogador 1 venceu!");
        ganhador = 1;
        
    }
    else{
        printf("\nProxima rodada\n"); 
    }

    printf("\n");

}while(tentativas <=9 && ganhador == -1 );

//verifica se houve empate e o numero de possiveis tentativas se esgotou
if ( ganhador == -1){
    printf("\nEmpate! \n");
}

    return 0;
}



// funcao que exibe e atualiza a matriz na tela durante o jogo
void func_print_matriz(char matriz[3][3]){
    int i;
    int j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        printf("%c", matriz[i][j]);
        if(j<2){
            printf(" | ");
        }
        }
        printf("\n");
}
}
