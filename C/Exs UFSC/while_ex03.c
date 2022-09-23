#include <stdio.h>



int main(){
int i;
float notaadd, notastotais;

i=0;
notaadd = 0;
notastotais = 0;

while(i<10){
    i++;
 printf("Digite a nota %d: \n", i);
 scanf("%f",&notaadd);

 notastotais = notaadd + notastotais;
 printf("%.2f\n",notastotais);
}

notastotais = notastotais/10;

printf("A media foi %.2f",notastotais);

return 0;
}
