#include <stdio.h>

int main(){

 int v[10] = {10,100,200,-3,1,0,45,67,8,23};

 int i;
 int *ptr;

 ptr = v;

 for (i=0;i<10;i++){
    printf("\n Endereco of v[%d] = %p \n",i,ptr);
    printf("valor de v[%d] = %i \n", i , *ptr);
    ptr++;
 }



    return 0;
}