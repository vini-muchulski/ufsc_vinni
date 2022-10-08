#include <stdio.h>

int main(){
int x,y,r, codigo;

printf("Digite os valores de X e Y, resp: \n");
scanf("%d", &x);
scanf("%d", &y);

printf("Digite a operacao que deseja realizar \n1 = Soma +\n2 = Subtracao -\n3 = Multiplicação *\n4 = Divisao /\n ");
scanf("%d",&codigo);




switch(codigo)
{
    case 1:
        r = x+y;
        printf("%i + %i =  %i",x,y,r );
        break;

    case 2:
        r = x-y;
        printf("%i - %i =  %i",x,y,r );
        break;

    case 3:
        r = x*y;
        printf("%i * %i =  %i",x,y,r );
        break;

     case 4:
        r = x/y;
        printf("%i / %i =  %i",x,y,r );
        break;

    default:
        printf("ERRO! Digite um codigo valido!");
        break;
}

return 0;
}