#include <stdio.h>

int main(){
    int i;
    int v[5];

    for (i=0;i<5;i++){
        printf("Digite o %d elemento: \n",i);
        scanf("%d", &v[i]);
    }
    printf("ELEMENTO ---- VALOR \n");

    for (i=0;i<5;i++)
    {
        printf("%d ---- %d \n",i,v[i]);
    }
    return 0;
}
