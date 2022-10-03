#include <stdio.h>

int main(){
int i;
char s1[10]; char s2[] = " mundo";

printf("%s",s2);

for( i =32;i<128;i++){

printf("%d %c \n",i,s2);
}

return 0;
}
