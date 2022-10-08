/*Selecionar valores repetidos de um vetor de 10 elementos sem repetições.*/

#include <stdio.h>

int main(){
 int c[10] = {7,8,1,0,8,0,7,5,6,7};
 int rep[10] = {0,0,0,0,0,0,0,0,0,0};

 int i,f,t;

 for (i=0; i<10;i++ ){
    for (f=i+1;f<10;f++){
        if (c[i] == c[f]){
            printf("%d \n",c[i]);
        }
    }

 }
    

// printando vetor de valores repetidos
for (i=0; i<10;i++ ){
printf(" %d ",rep[i]);

}



return 0; 
}