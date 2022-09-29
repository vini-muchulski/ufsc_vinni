#include <stdio.h>

int main(){

int aprovados,reprovados,i,c;
float media,somanotas,nota, media_aprovados;
aprovados = 0;
reprovados = 0;

for(i=1;i<=4;i++){

        printf("\n Aluno %d \n", i);
        for (c = 0; c <=3; c++){

    printf("Digite a nota: \n");
    scanf("%f",&nota);

    if (nota<0 || nota>10){
            printf("Nota invalida, digite um valor entre 0 e 10");
        break;
    }

        else{
        somanotas = somanotas + nota;

        if (c==2){
            media = somanotas/3;
            printf("%.2f \n", media);

            if (media>=6){
                aprovados = aprovados +1;
                printf("Aprovados mais 1 \n");
                media_aprovados = media + media_aprovados;

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
}
media_aprovados = media_aprovados/aprovados;

printf("Alunos aprovados: %d   -  Alunos reprovados: %d  - Media dos aprovados %.2f"  , aprovados,reprovados, media_aprovados);

return 0;
}
