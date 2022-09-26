#include <stdio.h>

int main(){
 int n,k,i,a;


printf("Digite a base: ");
scanf("%d", &n);

printf("Digite o expoente: ");
scanf("%d", &k);

i = 1;
a= 1;

while (i<=k){
a = a * n;
i++;
}

printf("%d", a);
return 0;}
