#include <stdio.h>

int main(){
int a;
a = 5;

printf("pos incremento a++");
printf(" a %d", a);
printf(" a++ %d", a++);
printf(" a %d", a);

printf("pre incremento ++a");
printf(" a %d", a);
printf(" ++a %d", ++a);
printf(" a %d", a);

return 0;
}
