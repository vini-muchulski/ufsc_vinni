#include <stdio.h>

int main(){
    int i,pi,soma;
    pi=5;
    soma  = 0;
    int v[pi];

    for (i=0;i<pi;i++){
        printf("Digite o %d elemento: \n",i);
        scanf("%d", &v[i]);
    }
    printf("ELEMENTO ---- VALOR \n");

    for (i=0;i<pi;i++)
    {
        printf("%d ---- %d \n",i,v[i]);
    }

    for(i=0;i<pi;i++){
        soma = soma + v[i];
    }
    printf("\nA soma dos elementos foi = %d",soma);
    return 0;
}
