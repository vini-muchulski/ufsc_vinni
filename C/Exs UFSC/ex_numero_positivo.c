#include <stdio.h>

int main(){
int valor, cont,n;

printf("Digite a quantidade de tentativas: \n");
scanf("%d", &n);

cont = 1;

while (cont <=n){
 printf("Digite um valor: \n");
 scanf("%d", &valor);

 if (valor > 0){
    printf("MAIOR QUE ZERO \n");

 }
 else if (valor <0){
    printf("Menor ou igual a ZERO! \n ");
 }
 cont++;

}
return 0;}
