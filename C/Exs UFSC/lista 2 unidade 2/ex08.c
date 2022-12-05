/* Escreva o programa que inverta a ordem dos dígitos em um número usando
uma função recursiva.
Ex: se o número for 7631 o programa deve retornar o número 1367
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int algarismos(int n);


int main(){
int x = algarismos(7631);

printf("%d", x);
    return 0;
}

int algarismos(int n){
    if (n == 0){
        return n;
    } 
    return (n%10)*10 + algarismos(n/10);
}
