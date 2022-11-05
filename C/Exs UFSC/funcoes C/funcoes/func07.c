//  Gerar 100 números aleatórios no intervalo de 1..10. - Calcular a média e analisar a distribuição


#include <stdio.h>
#include <time.h>
//srand( (unsigned)time(NULL) );


int aleatorio();

int main(){

aleatorio();


    return 0;
}

int aleatorio(){
    int vet[10] = {0};
    float soma = 0;
    int i;
    
    srand( (unsigned)time(NULL) );

    int nrand;

    for(i=0;i<100;i++){
        
        nrand = 1 + rand()% 10;
        soma +=nrand;
        vet[nrand-1] +=1;

    }
    soma = soma/100;
    printf("A media foi %.2f \n", soma);

     for (int i = 0; i<10 ; i++){
        printf("-- Numero %i apareceu = %i vezes = %% %i\n",i+1,vet[i],vet[i]);
     }
}