#include <stdio.h>
#include <stdlib.h>

float inCircle(float x_c, float y_c, float x_point, float y_point, float R);

int main(){
float x_c, y_c, x_point, y_point, R;

printf("Digite o valor do raio: \n");
scanf("%d", &R);

printf("Digite o valor do X_c: \n");
scanf("%d", &x_c);

printf("Digite o valor do Y_c: \n");
scanf("%d", &y_c);

printf("Digite o valor X do ponto: \n");
scanf("%d", &x_point);

printf("Digite o valor Y do ponto: \n");
scanf("%d", &y_point);

inCircle (x_c, y_c, x_point, y_point, R);

    return 0;
}

float inCircle(float x_c, float y_c, float x_point, float y_point, float R){
    float pitagoras;

    pitagoras = (x_point-x_c)*(x_point-x_c)+(y_point-y_c)*(y_point-y_c);

    if(pitagoras<=R*R){
        printf("o ponto esta DENTRO do circulo!");
    }
    else{
        printf("o ponto esta FORA do circulo!");
    }


}