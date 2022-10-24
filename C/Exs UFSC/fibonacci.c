#include <stdio.h>

int main(){
int f1,f2,fn,i;
f1 =1;
f2 = 1;
fn = 1;
for (i=0;i<10;i++){

fn = f1 + f2;
f1= f2;
f2 = fn;

printf("%d \n",fn);
}

return 0;
}

