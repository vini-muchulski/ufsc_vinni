/* poe as letras em ordem alfabetica*/

#include <stdio.h>

int main(){

int x,y;
char palavra [10] = {"ABACAXI"};
char aux;

for (x=0;x<10;x++){
    for (y = x+1;y<10;y++){
        if(palavra[x] > palavra[y] && palavra[y]!= "\0"){
            aux = palavra[x];
            palavra[x] = palavra[y];
            palavra[y] = aux;

        }
    }

}

for (x=0;x<10;x++){
    printf("%c", palavra[x]);
}
    return 0;
}
