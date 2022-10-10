#include <stdio.h>

int main(){
int matriz[5][5] = {{0,1,1,0,0},{0,0,1,0,0},{1,0,0,1,1},{0,0,1,0,1},{1,0,1,0,0}};

int k,i,j;
int aconhecem = 0;
int queElaConhece = 0;

for (i=0;i<5;i++){
    for(j=0;j<5;j++){
    printf("%i ",matriz[i][j]);
}
printf("\n");

}



printf("Digite o numero da pessoa [ de 1 a 5]: \n");
scanf("%i", &k);

for (i=k-1;i<=k-1;i++){
    for(j=0;j<5;j++){
    queElaConhece += matriz[i][j];
}
printf("\n");

}

printf("Pessoas que ela conhece = %d \n", queElaConhece);


 for(j=0;j<5;j++){
for (i=k-1;i<=k-1;i++){
    aconhecem += matriz[j][i];

}

}

printf("Pessoas que A CONHECEM = %d", aconhecem);

return 0;
}


/* Sim, basta realizar a soma das colunas e comparar o valor de cada uma, a que tive o maior valores significa
que é a que possui mais pessoas que a conhecem e a pessoa que possuir menor é a menos conhecida */
