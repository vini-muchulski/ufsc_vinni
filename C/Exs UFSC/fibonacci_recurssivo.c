#include <stdio.h>

int fibonacci(int n);
int main(){

int f;

f = fibonacci(6);

printf("%d \n", f);


return 0;
}

int fibonacci(int n){
    if (n==1||n==2)
{
    return 1;
}
    else{
    return fibonacci(n-1)+fibonacci(n-2);
    }
}


