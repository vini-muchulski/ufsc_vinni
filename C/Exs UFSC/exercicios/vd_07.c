/* mostra o maior e o menor numero de uma serie de valores digitados*/
#include <stdio.h>

int main(){
int menor,maior,digito;
int cont = 0;

printf("Digite um valor \n");
scanf("%d", &digito);

while (digito>=0){
    if (cont ==0){
        maior = digito;
        menor = digito;
        cont++;
    }

    if (cont !=0){

    printf("Digite um valor: \n");
    scanf("%d", &digito);

        if (digito<0){
            break;
        }
        if (digito>maior){
        maior = digito;
        
        }

        if(digito<menor){
            menor = digito;
        }
        cont++;

    }

}

printf("Maior = %d - menor = %d", maior,menor);

    return 0;
}