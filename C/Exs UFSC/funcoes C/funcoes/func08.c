// jogo “Adivinhe o número”: jogador deve adivinhar um número gerado de forma aleatória

#include <stdio.h>


int compara_chute(int chute, int nrand);



int main(){

int i;
int chute = 0;

int alet = aleatorio();

while (chute>=0){
    printf("Digite um valor para o chute [-1 Break]: \n");
    scanf("%d", &chute);

    if (chute == -1){
        break;
    }
    compara_chute(chute,alet);
}

    return 0;
}








int aleatorio(){
    int i;
    srand( (unsigned)time(NULL) );
    int nrand;
        
    nrand = 1 + rand()% 10;

    return nrand;
}
int compara_chute(int chute, int nrand){
    

    if( chute != nrand){
        if(chute>nrand){
            printf("O valor chutado eh maior que o numero gerado \n");
        }
        else{
            printf("O chute eh menor que o valor gerado \n");
        }
    }
    else{
        printf("Voce acertou!  \n");
        
    }

}