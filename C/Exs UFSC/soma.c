#include <stdio.h>

int soma(int n);

int main(){
    int n,s;

    s = soma(4);

    printf("%d", s);


return 0;
}



int soma(int n){
    int soma,i;
    soma = 0;

    if(n==1){
        return 1;
    }

    else{

        for (i=0;i<=n;i++){
         soma = soma + i;
    }
    return soma;
}
}



