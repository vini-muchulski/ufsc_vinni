#include <stdio.h>
//Programa recebe as escolhas dos 10 eleitores e calcula os votos para 5 candidatos.

int main(){
    int total_candidatos,i,voto;
    total_candidatos = 6;
    int cand[total_candidatos];

    for (i=0;i<total_candidatos;i++){
        cand[i]=0;
    }

    //voto
    for (i=0;i<10;i++){
    printf("Qual candidato? De 1 A 5 \n");
    scanf("%d",&voto);
    if (voto<=5 && voto>0){
        cand[voto]++;
    }
    else{
        cand[0]++;
    }
    }
    for (i=0;i<total_candidatos;i++){
        printf("CANDIDATO = %d    VOTOS = %d \n",i,cand[i]);
        
    }
    printf("\nVotos Nulos %d", cand[0]);

    return 0;
}
