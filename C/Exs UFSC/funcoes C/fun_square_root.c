#include <stdio.h>

int square_root(int num,int raiz);
void print_linha();

int main(){

float raiz;
float i,indice;



printf("Digite um numero: \n");
scanf("%f", &i);


printf("Digite o indice da raiz: \n");
scanf("%f", &indice);


print_linha();

raiz = square_root(i,indice);

printf("a raiz %f de %f = %f \n\n", indice, i, raiz);

print_linha();

return 0;
}

float square_root(float num, float indice){
    return num **(1/indice);

}

void print_linha()
{
    printf("  ---------------------------------- \n \n");
    return;
}
