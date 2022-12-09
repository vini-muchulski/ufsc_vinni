/* Escreva o programa que inverta a ordem dos dígitos em um número usando
uma função recursiva.
Ex: se o número for 7631 o programa deve retornar o número 1367
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int algarismos(int n);


int main(){
int x = rev(7631);

printf("%d", x);
    return 0;
}

int algarismos(int n){
     
    printf("%d \n",n);
    if(10>n){
        return n;
    }
    

    else{

        return (n%10)*10 +10*algarismos(n/10);

    //return (n%10)*10 + algarismos(n/10);

    /*          1*10 + algr(763)
                3*10 + algr(76)
                6*10 + algr(7)
                7
                        */
}
}

int rev(int num)
{
int static sum,r;

if(num)
{
r=num%10;
sum=sum*10+r;
rev(num/10);
}
else
return 0;

return sum;
}
