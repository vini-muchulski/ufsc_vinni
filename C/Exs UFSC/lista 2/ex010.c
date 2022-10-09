/*O programa deve calcular o determinante de uma matriz A 3x3
regra de Sarrus*/


#include <stdio.h>

int main(){
 int matriz[3][3];
int i,j,valor;

int det;

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("Digite o valor para o elemento %d %d: \n",i,j);
        scanf("%d",&valor);
        matriz[i][j] = valor;
    }
}

printf("MATRIZ 3x3 \n");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf(" %d ", matriz[i][j]);
    }
    printf("\n");
}


det = (matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1]) - ( matriz[0][2]*matriz[1][1]*matriz[2][0] + matriz[0][0]*matriz[1][2]*matriz[2][1] + matriz[1][0]*matriz[0][1]*matriz[2][2]);



printf("Determinante = %d",det);



return 0;
}