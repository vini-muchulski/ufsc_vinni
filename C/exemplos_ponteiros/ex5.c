#include <stdio.h>

const int arraySize= 10;


int main(){

 int v[10] = {10,100,200,-3,1,0,45,67,8,23};

 int i;
 int *ptr;

 i=0;
 ptr = v;

 while (ptr <= &v[arraySize-1]){
    printf("\n Endereco of v[%d] = %p \n",i,ptr);
    printf("valor de v[%d] = %i \n", i , *ptr);
    ptr++;
    i++;


 }



    return 0;
}