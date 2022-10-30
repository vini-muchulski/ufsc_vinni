
#include <stdio.h>
#include <stdlib.h>

int potencia(int x,int y);

int main(){
int x, y, d;

printf("Digite dois valores para x e y: \n");
scanf("%d", &x);
scanf("%d", &y);

d = potencia(x,y);
printf("O resultado eh %d", d);

    return 0;
}

int potencia(int x,int y){
    if (y<=0){
        return 1;
    }
    else{
        return x*potencia(x,y-1);
    }



}