#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

 float vet[12];

 int i;
 float maior,menor;
 int mes_maior,mes_menor;

 for(i=0;i<12;i++){
    printf("Digite a temperatura media do mes %d: \n", i+1);
    scanf("%f",&vet[i]);
 }

 for(i=0;i<12;i++){
    if (i==0){
        maior = vet[i];
        menor = vet[i];
        mes_maior = i+1;
        mes_menor = i+1;

    }
    else{
        if(vet[i]>maior){
            maior = vet[i];
        mes_maior = i+1;

        }
        if(vet[i]<menor){
             menor = vet[i];
             mes_menor = i+1;
        }
    }
    
 }

  for(i=0;i<12;i++){
    printf("Temperatura media mes %d = %.2f  graus Celsius \n",i+1, vet[i]);
    
 }

 printf("\n");

printf("maior temperatura mes %d = %.2f \n", mes_maior, maior);
printf("menor temperatura mes %d = %.2f", mes_menor, menor);
    return 0;
}