#include <stdio.h>

//escre um programa que receba tres notas e o numero de ausencia de um estudante e deolva a situacao aprovado,recuperação e reprovado.

int main(){
    float a,b,c, media, ausencia;

    printf("Digite a PRIMEIRO nota: \n");
  scanf("%f", &a);

    printf("Digite a SEGUNDO nota: \n");
  scanf("%f", &b);

    printf("Digite a TERCEIRO nota: \n");
  scanf("%f", &c);

  printf("Digite a quantidade de FALTAS: \n");
  scanf("%f", &ausencia);

media = (a+b+c)/3;

printf("A media foi %.2f \n", media);

 if (ausencia>72){
 printf("REPROVADO POR FALTAS \n");
 }
 else{

 if (media>=6){
 printf("APROVADO \n");
}

else{

 printf("REPROVADO \n");
 }
}

return 0;
}
