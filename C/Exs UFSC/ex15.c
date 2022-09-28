#include <stdio.h>

int main(){

int nota,somanotas,aprovados,reprovados,i,c;
float media;
aprovados = 0;
reprovados = 0;

for(i=1;i<=4;i++){
        printf("Aluno %d \n", i);
        for (c = 0; c <=3; c++){
    printf("Digite a nota: \n");
    scanf("%d",&nota);

    somanotas = somanotas + nota;

    if (c==2){
        media = somanotas/4;

        if (media>=6){
            aprovados = aprovados +1;
            printf("Aprovados mais 1");

        }
        else{
            reprovados = reprovados +1;
            printf("Reprovados mais 1");
        }

        break;
    }


        }

}

printf("Alunos aprovados: %d Alunos reprovados: %d", aprovados,reprovados);

return 0;
}
