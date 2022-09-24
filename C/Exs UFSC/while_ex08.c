#include <stdio.h>

int main(){
int somatorio,  valor,cont;
float media;

somatorio = 0;
valor = 0;
cont = 0;
media = 0;

while (valor !=1){
    printf("Digite um valor negativo [1 para finalizar]: \n");
    scanf("%d", &valor);

    if(valor<0)
    {
    somatorio = somatorio + valor;
    cont = cont + 1;
    }
}

media = somatorio/cont;
printf("%.2f media",media);

return 0;
}
