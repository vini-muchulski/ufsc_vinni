#include <stdio.h>

struct pessoa
{
    char nome[20], rua[20];
    int idade,numero;
};

int main(){

struct pessoa p[3];
int i;

for(i=0;i<3;i++){
    
    printf("Nome ");
    scanf("%s",&p[i].nome);

    printf("Idade \n");
    scanf("%d",&p[i].idade);

    printf("Rua ");
    scanf("%s",&p[i].rua);

    printf("Numero \n");
    scanf("%d", &p[i].numero);

}


for(i=0;i<3;i++){
    printf("\nnome %s - idade %d - rua %s - numero %d",p[i].nome,p[i].idade,p[i].rua,p[i].numero  );
}


    return 0;
}
