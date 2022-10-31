#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float raiz(float a);

int main(){
float a,raiza;

a = 2;
raiza = raiz(a);

printf("%f", raiza);

    return 0;
}


// formula de recorrencia

float raiz(float a){
    float x0,x,erro,tol;

    x0= a/2;

    tol = 0.0001;
    erro = 1.0;

    while(erro>tol){

        x= 0.5*(x0*x0 + a)/x0;
        erro = fabs(x-x0);
        x0 = x;

    }
    return x;

}
