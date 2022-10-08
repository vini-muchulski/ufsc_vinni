/*Selecionar valores repetidos de um vetor de 10 elementos sem repetições.*/

#include <stdio.h>

int main(){
 int c[10] = {7,8,1,0,8,0,3,2,2,3};
 int rep[10] = {0,0,0,0,0,0,0,0,0,0};
 int vetor_limpo[10] = {0,0,0,0,0,0,0,0,0,0};

int i,f,t;
int contador = 0;

 for (i=0; i<10;i++ ){
    for (f=i+1;f<10;f++){
        if (c[i] == c[f]){
            rep[i] = c[i];
        }
    }

 }

 for (i=0; i<10;i++ ){
    for (f=i+1;f<10;f++){
        if (rep[i] == rep[f]){
            rep[f] = -1;
        }
    }

 }
    

// printando vetor de valores repetidos



for (i=0; i<10;i++ ){
    if (rep[i] != -1){
        printf(" %d ", rep[i]);
    }
}




return 0; 
}