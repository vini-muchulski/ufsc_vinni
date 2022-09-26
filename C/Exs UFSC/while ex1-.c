#include <stdio.h>

int main(){
int valor,quadrado;

printf("Digite o valor [0 para finalizar]: \n");
scanf("%d", &valor);

while(valor !=0){
 quadrado = valor*valor;
 printf("%d \n", quadrado);

printf("Digite o valor [0 para finalizar]: \n");
scanf("%d", &valor);

}
return 0;
}
