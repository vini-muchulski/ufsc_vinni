#include <stdio.h>
#define tam 5


/* • Programa recebe as escolhas dos 10 eleitores e calcula os votos para 5
candidatos.
• Modifique programa permitindo:
◦ receber a quantidade de votos a ser analisada
◦ receber os votos para 7 candidatos
◦ calcular a percentagem de votos de cada candidato e votos nulos */

int main(){

int voto;
int i;
int candidatos[5] = {0,0,0,0,0};

for (i=0;i<tam;i++){
    printf("Digite o valor do candidato[1 ate 5]: ");
    scanf("%i",&voto);
    candidatos[voto-1] = candidatos[voto-1] + 1;

}
for (i=0;i<tam;i++){
printf("CANDIDATO %i   VOTOS %i",i,candidatos[i]);
printf("\n");
}

return 0;
}
