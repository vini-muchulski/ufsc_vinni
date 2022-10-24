#include <stdio.h>

int fatorial(int n);

int main(){

int f;
f = fatorial(5);

printf("%d", f);

return 0;
}

int fatorial(int n){
int fat,i;
fat = 1;
for( i=1;i<=n;i++){
fat = fat*i;
}
return fat;
}
