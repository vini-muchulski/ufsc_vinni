#include <stdio.h>


/*  Receber o valor de x e achar o valor do y de acordo com a expressão:
y={
0, se x⩽0
x+1, se 0< x≤1
x ²+5, x>1 } */

int main(){

int x,y;

printf("Digite o valor de X: \n");
scanf("%d",&x);

if (x<=0){
    y=0;
}
if (0<x<=1){
    y = x + 1;
}
if (x>1){
    y = x*x + 5;
}

printf("Valor de y = %d",y);





    return 0;
}
