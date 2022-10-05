#include <stdio.h>

int main(){
 int i,j;
 int mat[2][2] = {{1,2},{3,4}};

 printf("MATRIZ 2X2 \n");

 for (i=0;i<2;i++){

        for (j=0;j<2;j++){
            printf("%i ", mat[i][j]);

 }
    printf("\n");
 }

return 0;
}
