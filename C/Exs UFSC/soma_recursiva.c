#include <stdio.h>

int soma(int n);

int main(){
    int n,s;

    s = somaint(5);

    printf("%d", s);


return 0;
}



int somaint(int n){


    if(n==1){
        return 1;
    }

    else{

        return n + somaint(n-1);
    }

}




