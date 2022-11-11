#include <stdio.h>

const int arraySize= 10;

int main(){

int v[10] = {10,100,200,-3,1,0,45,67,8,23};

 int i;
 int *ptr [arraySize];

 for (i=0;i<arraySize;i++){
    ptr[i] = &v[i];

 }

 for (i=0;i<arraySize;i++){
 printf("Valor de v[%d] = %d \n",i,*ptr[i]);

    
 }

    return 0;
}