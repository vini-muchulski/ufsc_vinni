#include <stdio.h>

int max(int num1,int num2);

int main(){


    int a, b;
    int num_max;

    printf("Digite dois numeros: \n");
    scanf("%d", &a);
    scanf("%d", &b);


    num_max = max(a,b);

    printf("O valor maximo eh: %d \n", num_max);


    return 0;
    }

int max(int num1,int num2){

    int result;

    if(num1>num2){
      result = num1;
    }
    else{
      result = num2;
    }
    return result;


}

