
#include <stdio.h>

int main(){
    int i,total;
    i=1;
    total = 0;

while (i<100){
//printf("%d", i);
total = total+i;
i = i +2;
}

printf("%d",total);
return 0;
}
