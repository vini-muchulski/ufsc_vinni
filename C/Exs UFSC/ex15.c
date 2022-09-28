#include <stdio.h>

int main(){

int nota,somanotas,aprovados,reprovados,i,c;
float media;
aprovados = 0;
reprovados = 0;

for(i=1;i<=4;i++){
        for (c = 0; c <=3; c++){
    printf("Digite a nota: \n");
    scanf("%d",&nota);

    somanotas = somanotas + nota;

    if (c==2){
        media = somanotas/5;

        if (media>=6){
            aprovados = aprovados +1;

        }
        if (media<6){
            reprovados = reprovados +1;
        }

        break;
    }


        }

}

return 0;
}
