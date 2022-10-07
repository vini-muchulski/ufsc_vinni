#include <stdio.h>

int main(){
    int x,y,z;

printf("Digite o valor de X: \n");
scanf("%d",&x);

y =2*x + 5;

if (y<0){
    z = 2*(y*y) - 3*y + 7;
}

if (y>=0){
    z = 4*(y*y) + 5*y -3;
}

printf("Valor de Z = %d", z);


    return 0;
}