#include <stdio.h>

int main()
{
  float Eps_float = 1.0;
  double Eps_double = 1.0;

  //----------------------- float -----------------------------
  while (Eps_float + 1 > 1)
  {
    Eps_float = Eps_float / 2.0;
    printf("Eps_float = %1.25f \n", Eps_float);
  }
  printf("\n Dados do tipo float: a maquina acha que %1.25f vale zero! \n", Eps_float);


  //----------------------- double -----------------------------
  while (Eps_double + 1 > 1)
  {
      Eps_double = Eps_double / 2.0;
      printf("Eps_double = %1.25lf \n", Eps_double);
  }
  printf("\nDados do tipo double: a maquina acha que %1.25lf vale zero! \n", Eps_double);
}

