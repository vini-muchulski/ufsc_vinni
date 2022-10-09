/*• criar uma matriz 3 x 3 A com elementos do tipo float;
• criar uma matriz B com elementos da matriz A que estão acima da 
media (os outros elementos devem ser iguais a 0);
*/

#include <stdio.h>

int main(){
float matriz[3][3] ={{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
float media;
int i,j,valor;

float soma =0;
float b[3][3] ={{0,0,0},{0,0,0},{0,0,0}};



printf ("MATRIZ A \n");

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf(" %.2f ", matriz[i][j]);
    }
    printf("\n");
}



for(i=0;i<3;i++){
    for(j=0;j<3;j++){
    soma += matriz [i][j];
    }
}

media = soma/9;


for(i=0;i<3;i++){
    for(j=0;j<3;j++){
    if(matriz [i][j]>=media){
    b[i][j]= matriz [i][j];
    }
    else{
      b[i][j] = 0.0;
    }
    }
}

printf("media = %.2f \n",media);

printf ("MATRIZ B \n");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf(" %.2f ", b[i][j]);
    }
    printf("\n");
}

    return 0;
}