/* Escreva um programa que recebe uma quantidade arbitrária de números
positivos e mostra qual foi -  o maior dos números fornecidos pelo usuário- o menor dos números fornecidos pelo usuário */
#include <stdio.h>

int main(){
    int voto,tent;
    int maior,menor;

tent = 0;
menor=0;
maior=0;
voto = 0;

while ( voto != -1){
printf("Digite um valor inteiro[-1 Break]: \n");
scanf("%i", &voto);

if (voto==-1){
break;
}

if (tent==0){

        maior = voto;
        menor = voto;
}
if (tent>0){
    if (voto>maior){
        maior=voto;
    }
    if (voto<menor){
        menor = voto;
    }
}
tent +=1;
}
printf("MAIOR = %d    MENOR = %d", maior, menor);

return 0;
}
