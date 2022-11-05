//Criar uma função contador


#include <stdio.h>

static cont = 5;

void contador();

int main(){

contador();
contador();
contador();
contador();
contador();
contador();

        return 0;
}

void contador(){

    cont = cont -1;
    if (cont <=0){
        cont = 5;
    }
    
    printf("contador = %d \n", cont);
}