/*• criar e inicializar uma matriz A 3 x 3
• achar a soma dos elementos pares*/

#include <stdio.h>

int main(){
 int matriz[3][3];
int i,j,valor;
int soma =0;

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("Digite o valor para o elemento %d %d: \n",i,j);
        scanf("%d",&valor);
        matriz[i][j] = valor;

    }

}


for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if( matriz[i][j]%2==0){
            soma = soma + matriz[i][j];
        }
    }
}


for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf(" %d ", matriz[i][j]);
    }
    printf("\n");
}


printf("A soma dos elementos pares foi = %d",soma);

return 0;
}