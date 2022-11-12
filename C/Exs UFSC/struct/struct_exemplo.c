#include <stdio.h>

struct pessoa
{
    int idade,numero;
    char nome[20];
};


int main(){

struct pessoa p1;

p1.idade = 19;
p1.numero = 2710;

printf("Digite seu nome \n");
gets(p1.nome);

printf("%s %d %d",p1.nome,p1.idade,p1.numero);

return 0;

}