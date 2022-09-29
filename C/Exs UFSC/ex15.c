#include <stdio.h>

int main(){

int aprovados,reprovados,i,c;
float media,somanotas,nota;
aprovados = 0;
reprovados = 0;

for(i=1;i<=4;i++){
        printf("\n Aluno %d \n", i);
        for (c = 0; c <=3; c++){
    printf("Digite a nota: \n");
    scanf("%f",&nota);

    somanotas = somanotas + nota;

    if (c==2){
        media = somanotas/3;
        printf("%.2f \n", media);

        if (media>=6){
            aprovados = aprovados +1;
            printf("Aprovados mais 1 \n");

        }
        else{
            reprovados = reprovados +1;
            printf("Reprovados mais 1 \n");
        }
        somanotas = 0;
        break;
    }
        }
}

printf("Alunos aprovados: %d   -  Alunos reprovados: %d", aprovados,reprovados);

return 0;
}
