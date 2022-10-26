#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
unsigned int seed;
int i,j,n,r;


printf("Gerando numeros psedudo aletorios de 1 a 6 \n");
for (i=1;i<=10;i++){
n = 1+ rand()%6;
printf("%i ", n);
}

// --------------------------------

printf("\nFuncao RAND \n");

seed = 1;

while (seed !=0){

printf("\nDigite um numero ou 0 para sair \n");
scanf("%u", &seed);

if (seed !=0){


 srand(seed);

 for (i=1 ; i<=10;i++)
 {
     n = 1+ rand()&6;
     printf("%i ", n);

 }
}

}


// --------------------------------

printf("\n funcao srand + time \n");
printf("Digite quantas sequencias deseja");
scanf("%d", &r);

for (j=1;j<=r;j++){

printf("\n sequencia %i \n", j);
srand(time(NULL));
// getchar();

for (i=1;i<=10;i++){
n= 1 + rand() % 6;
printf("%i ", n);

}
sleep(2);
}

return 0;
}
