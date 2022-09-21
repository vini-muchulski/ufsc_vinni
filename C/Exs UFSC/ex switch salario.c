#include <stdio.h>



int main(){
  int codigo;
  float salario_atual, aumento, novosalario;

  printf("Digite o salario atual: \n");
  scanf("%f", &salario_atual);

  printf("Escolha o cargo \n");
  printf("1 - Junior   \n2 - Pleno   \n3 - Senior \n");
  scanf("%d", &codigo);

switch(codigo)
{
    case 1:
        aumento = salario_atual*0.5;
        novosalario = salario_atual + aumento;
        printf("Cargo: Junior  -  Novo Salario: R$ %.2f  -  Aumento: %.2f \n", novosalario, aumento);
        break;

    case 2:
        aumento = salario_atual*0.35;
        novosalario = salario_atual + aumento;
        printf("Cargo: Pleno  -  Novo Salario: R$ %.2f  -  Aumento: %.2f \n", novosalario, aumento);
        break;

    case 3:
        aumento = salario_atual*0.1;
        novosalario = salario_atual + aumento;
        printf("Cargo: Senior  -  Novo Salario: R$ %.2f  -  Aumento: %.2f \n", novosalario, aumento);
        break;

    default:
        printf("ERRO! Digite um código válido!");
        break;
}

return 0;
}
