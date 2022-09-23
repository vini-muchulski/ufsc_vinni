#include <stdio.h>

int main(){
int i;
float notaadd, notastotais;

i=0;
notaadd = 0;
notastotais = 0;

while(notaadd != -1){
 printf("Digite a nota %d [ -1 Break ]: \n", i);
 scanf("%f",&notaadd);

 if(notaadd != -1){
  i++;
  notastotais = notaadd + notastotais;
  }

}
notastotais = notastotais/i;

printf("A media foi %.2f - Ao todo %d alunos foram cadastrados",notastotais, i);

return 0;
}
