#include <stdio.h>
// soma dos algarismos de um numero
int main(){
int valor,a, n,b, soma;

soma = 0;
 a = -1;
printf("Digite o valor: \n");
scanf("%d", &valor);


while(valor !=0){

    a = valor%10;
    n = valor/10;

    valor = n;

    if (b==a){
        printf("sim");
    }
    //printf("n = %d     a = %d \n",n,a);

    b = a;
}


return 0;
}

