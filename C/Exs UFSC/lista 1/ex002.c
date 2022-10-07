#include <stdio.h>

/* Receber os valores de x, y e z do usuário.
Calcular o resultado r de acordo com a expressão min {x2
 + y2
, y2
 + z2
} – 4 */


int main(){
    int x,y,z,r,r1,r2;

    printf("DIGITE OS VALORES DE X,Y,Z RESPECTIVAMENTE: \n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);

r1= x*x+y*y;
r2 =z*z+y*y;

    if (r1<r2){
        r = r1-4;
        printf("x*x+y*y = %d -4 == %d",r1,r);
    }

    if (r1>r2){
        r = r2-4;
        printf("z*z+y*y = %d -4 == %d",r2,r);
    }

return 0;

}
