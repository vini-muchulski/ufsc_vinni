#include <stdio.h>


int main(){
 float a[4][2] = {{1,2},{2,3},{3,4},{4,5}};
 float b[2][3] = {{1,2,3},{4,5,6}};
 float c[4][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

 int i,j,x;
 float aux;



for(i = 0; i < 4; i++) {
		for(j = 0; j < 3; j++) {
			
			c[i][j] = 0;
			for(x = 0; x < 2; x++) {
				aux +=  a[i][x] * b[x][j];
			}

			c[i][j] = aux;
			aux = 0;
		}
	}


for(i = 0; i < 4; i++) {
		for(j = 0; j < 3; j++) {
			printf("%6.f", c[i][j]);
		}
		printf("\n\n");
	}

    return 0;
}