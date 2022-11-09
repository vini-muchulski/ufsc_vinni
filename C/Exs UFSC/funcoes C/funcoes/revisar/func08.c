// jogo “Adivinhe o número”: jogador deve adivinhar um número gerado de forma aleatória


// como usar a variavel tentativas da funcao dificuldade para se tornar o valor da variavel global tentativas

#include <stdio.h>



int main(){

int i;
int chute = 0;
int nivel;
int alet = aleatorio();

printf("Digite o nivel de dificuldade ---- \n1 = Facil \n2 = Medio \n3 = Dificil\n");
scanf("%d",&nivel);
dificuldade(nivel);




while (chute>=0){
    printf("Digite um valor para o chute [-1 Break]: \n");
    scanf("%d", &chute);

    if (chute == -1){
        break;
    }
    
    if (compara_chute(chute,alet) == -1){
        break;
    }
}

    return 0;
}




int dificuldade(int nivel){
    if(nivel ==1){
        int static tentativas = 8;
        
    }

    if(nivel ==2){
        int static tentativas = 5;
    }

    if(nivel ==3){
        int static tentativas = 3;
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
int compara_chute(int chute, int nrand){
    
    
    if( chute != nrand){
        tentativas--;
        printf("Voce errou! Restam %i tentativas \n", tentativas);
        if (tentativas>0){
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
