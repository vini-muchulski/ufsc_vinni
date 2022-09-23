#include <stdio.h>

//Achar a primeira potência de 2 maior do que 1000.

int main(){
 int produto,i,total;
 total = 1;
 i = 2;


 while(total<=1000){
     total = total*i;
     printf("%d \n", total);

 }


return 0;
}
