#include <stdio.h>

/* Receber o valor de x e achar o valor do y de acordo com a expressão:
y={
x
2
, se −2⩽x⩽2
4, se x <−2ou x>2}


*/

/* */

int main(){
    int x,y;

    printf("DIGITE UM VALOR PARA X: \n");
    scanf("%i", &x);

    if(-2<=x<=2){
        y = x*x;

    }

    if(x>2  ||  x<-2 ){
        y=4;

    }

    printf("Y = %i",y);

    return 0;
}
