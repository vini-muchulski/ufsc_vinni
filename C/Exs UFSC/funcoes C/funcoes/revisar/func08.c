// jogo “Adivinhe o número”: jogador deve adivinhar um número gerado de forma aleatória


// como usar a variavel tentativas da funcao dificuldade para se tornar o valor da variavel global tentativas

#include <stdio.h>



int main(){

int i;
int chute = 0;
int nivel;
int dificuldades_tentativas;
int aleat = aleatorio();
int cont = 0;

printf("Digite o nivel de dificuldade ---- \n1 = Facil - 8 tentativas \n2 = Medio - 5 tentativas \n3 = Dificil - 3 tentativas\n");
scanf("%d",&nivel);
dificuldades_tentativas = dificuldade(nivel);




while (chute>=0){
    printf("Digite um valor para o chute [-1 Break]: \n");
    scanf("%d", &chute);

    if (chute == -1){
        break;
    }
    
    if (compara_chute(chute,aleat,dificuldades_tentativas-cont) == -1){
        
        break;
    }
    cont++;
}

    return 0;
}




int dificuldade(int nivel){
    int tentativas;

    if(nivel ==1){
          tentativas = 8;
        
    }

    if(nivel ==2){
          tentativas = 5;
    }

    if(nivel ==3){
          tentativas = 3;
    }
    
    return tentativas;
    
}


int aleatorio(){
    int i;
    srand( (unsigned)time(NULL) );
    int nrand;
        
    nrand = 1 + rand()% 10;

    printf("nrand %d \n", nrand);
    return nrand;
}
int compara_chute(int chute, int nrand, int tentativas){
        int chutes = tentativas;
    
    if( chute != nrand){
        chutes--;
        printf("Voce errou! Restam %i tentativas \n", chutes);
        if (chutes>0){
        if(chute>nrand){
            printf("O valor chutado eh maior que o numero gerado \n");
        }
        else{
            printf("O chute eh menor que o valor gerado \n");
        }}
        else{
            printf("Ficou sem tentativas =( FIM DE JOGO \n");
            return -1;
        }
    }
    else{
        printf("Voce acertou!  \n");
        return -1;
        
    }

}