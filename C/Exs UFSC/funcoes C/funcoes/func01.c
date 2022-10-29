//  Escreva o programa “calculadora” que receba 2 números reais x e y e, dependendo da escolha do usuário chama as funções para realizar as operações escolhidas

#include <stdio.h>
#include <stdlib.h>

float adicao ( float x, float y);
float subtracao ( float x, float y);
float divisao ( float x, float y);
float multiplicacao ( float x,float y);
float potencia (float x,float y);

int main(){

int opt;
float x,y;

printf("Digite um valor para X: \n");
scanf("%f", &x);
printf("Digite um valor para Y: \n");
scanf("%f", &y);

printf("Digite: \n1 = para adicao (x+y) \n2 = para subtracao (x-y) \n3 = para divisao (x/y) \n4 = para multiplicacao (x*y) \n5 = para potencia (xy)\n");
scanf("%d", &opt);

switch (opt)
{
case 1:

    printf("A operacao %.2f + %.2f = %.2f\n",x,y, adicao(x,y));
    break;
    
case 2:
    printf("A operacao %.2f - %.2f = %.2f",x,y, subtracao(x,y));
    break;
    
case 3:
    printf("A operacao %.2f / %.2f = %.2f",x,y, divisao(x,y));
    break;

case 4:
    printf("A operacao %.2f * %.2f = %.2f",x,y, multiplicacao(x,y));
    break;

case 5:
    printf("A operacao %.2f ** %.2f = %.2f",x,y, potencia(x,y));
    break;

default:
    printf("Digite um valor valido");
    break;
}


    return 0;
}


float adicao (float  x, float  y){
    float c;
    c = x + y;
    return c;

}
float subtracao (float x,float y){

     float c;
    c = x - y;
    return c;
}

float divisao ( float x, float y){

     float c;
    c = x / y;
    return c;
}

float multiplicacao (float x, float y){

     float c;
    c = x * y;
    return c;
}

float potencia (float x, float y){

     float c,i;
    c = 1;
     for(i=y;i>0;i--){
        c = c*x;
     }
    
    return c;
}