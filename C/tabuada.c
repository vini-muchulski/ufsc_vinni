#include <stdio.h>

int main(){
int mult, contador,conta;
contador =1;
conta = 1;
mult = 1;
printf("Digite um valor para a tabuada: ");
scanf("%d",&mult);

while (contador<=10){
    conta = contador*mult;
    printf("%d X %d = %d \n", mult,contador,conta);
    contador++;

}
return 0;
}
