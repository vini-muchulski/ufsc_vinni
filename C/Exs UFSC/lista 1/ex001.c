#include <stdio.h>

/* Receber os valores de x, y e z do usuário.
Calcular o resultado r de acordo com a expressão max {x+y+z, x*y*z} + 3*/


int main(){
    int x,y,z,r,r1,r2;

    printf("DIGITE OS VALORES DE X,Y,Z RESPECTIVAMENTE: \n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);

r1= x+y+z;
r2 =x*y*z;

    if (r1>r2){
        r = r1+3;
        printf("X+Y+Z = %d",r);
    }

    if (r1<r2){
        r = r2+3;
        printf("X*Y*Z = %d",r);
    }

return 0;

}
