#include <stdio.h>

// escreve um programa q receba tres valores e mostre o maior

int main(){
    int a,b,c;

    printf("Digite o PRIMEIRO valor: \n");
  scanf("%d", &a);

  printf("Digite o SEGUNDO valor: \n");
  scanf("%d", &b);

    printf("Digite o TERCEIRO valor: \n");
  scanf("%d", &c);





if (a>b){
    if (a>c){
    printf(" %d eh o maior", a);
    }

}

if (a<b) {
    if (b>c){
    printf(" %d eh o maior", b);
    }
}

if (c>a)  {
    if (b<c){
    printf(" %d eh o maior", c);
    }}

    return 0;
}
