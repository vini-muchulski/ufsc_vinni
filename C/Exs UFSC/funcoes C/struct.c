#include <stdio.h>

typedef struct dma{
int dia;
int mes;
int ano;
}data;

int main(){
data x,y;

x.dia = 31;
x.mes = 12;
x.ano = 2022;

printf("%d / %d / %d \n", x.dia, x.mes,x.ano);

return 0;
}


