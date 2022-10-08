#include <stdio.h>

int main(){
 int matriz[3][3];
int i,j,valor;

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("Digite o valor para o elemento %d %d: \n",i,j);
        scanf("%d",&valor);
        matriz[i][j] = valor;

    }

}

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf(" %d ", matriz[i][j]);
    }
    printf("\n");
}

    return 0;
}