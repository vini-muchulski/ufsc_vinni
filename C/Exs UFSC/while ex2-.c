#include <stdio.h>
 // soma de numeros inteiros
int main(){
int valor,total;
total = 0;

printf("Digite o valor [0 para finalizar]: \n");
scanf("%d", &valor);

while(valor !=0){
total = total + valor;

printf("Digite o valor [0 para finalizar]: \n");
scanf("%d", &valor);

}

printf("Total da soma dos numeros = %d \n", total);
return 0;
}
