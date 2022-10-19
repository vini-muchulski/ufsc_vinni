#include <stdio.h>

int square(int num);
void print_linha();

int main(){

int quadrado;
int i;



printf("Digite um numero: \n");
scanf("%d", &i);

print_linha();

quadrado = square(i);

printf("o valor %d ao quadrado eh = %d \n\n", i,quadrado);

print_linha();

return 0;
}

int square(int num){
    return num * num;

}

void print_linha()
{
    printf("  ---------------------------------- \n \n");
    return;
}
