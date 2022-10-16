#include <stdio.h>

int main(){

float matriz[4][4];
float medias[4];
float notas;
float soma = 0;


int i,j;

// recebe as notas dos alunos
for( i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf("ALUNO %i -- NOTA %i: \n",i,j);
        scanf("%f", &notas);
        matriz[i][j] = notas;
    }
}


// mostra a matriz com as notas
for( i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
    }


// calcula a media de cada aluno
for( i=0;i<4;i++){
    soma =0;
    for(j=0;j<4;j++){
       soma +=matriz[i][j];

    }
    medias[i] = soma/4;
}

// mostra as notas
for (i=0;i<4;i++){
    printf("Aluno %i - Media = %.2f \n",i ,medias[i]);
}

    return 0;
}