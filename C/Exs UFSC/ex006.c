#include <stdio.h>
//#Fa�a um programa que leia tr�s n�meros e mostre qual � o maior e qual � o menor.

int main(){

int prim,sec,terc, max , min;

printf("Digite tres valores: \n");
scanf("%d", &prim);
scanf("%d",&sec);
scanf("%d",&terc);
max = prim;
min = prim;


 if ((sec<prim) && (sec<terc))
    min=sec;


 if (( terc<prim) && (terc<sec))
    min=terc;


 if ((sec>prim) && (sec>terc))
    max = sec;


 if (( terc>prim) && (terc>sec))
    max = terc;


 printf("O maior valor foi %d e o menor foi %d", max,min);
return 0;
}
