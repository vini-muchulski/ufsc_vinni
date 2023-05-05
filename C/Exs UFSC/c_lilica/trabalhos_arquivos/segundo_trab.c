#include <stdio.h>
#include <stdlib.h>


int main() {
    int linhas;
    int i, j;
    int opcao;

    // recebe o numero de linhas da forma
    printf("Digite o numero de linhas da forma: ");
    scanf("%d", &linhas);


    printf("\n 1 - quadrado\n 2 - triangulo retangulo\n 3 - paralelogramo\n 4 - losango\n");
     // pede a escolha  da forma geométrica a ser desenhada
    printf("Digite a forma geometrica a ser desenhada: ");
    
    scanf(" %d", &opcao);

    switch (opcao){
        // desenha a figura emitindo asteriscos durante cada iteração da primeira linha, apos isso ele trabalha com as excecoes para 
        // ver se deve emitir pontos no contorno da figura
        case 1:
            for (i = 1; i <= linhas; i++) {
            for (j = 1; j <= linhas; j++) {
            if (i == 1 || i == linhas || j == 1 || j == linhas) {
                        printf("* ");
                } 
            else
            {
                        printf("  ");
            }
                }

            printf("\n");
            }

            break;




        case 2:
        // desenha um triângulo retângulo usando asteriscos seguindo o mesmo raciocinio
            for (i = 1; i <= linhas; i++) {
            for (j = 1; j <= i; j++) {
                if (j == 1 || j == i || i == linhas) {
                    printf("* ");
            } else{
                        printf("  ");
            }
            }
            printf("\n");
            }
            break;




    case 3:
         // desenha um paralelogramo usando asteriscos
            for (i = 1; i <= linhas; i++) {
            for (j = 1; j <= linhas - i; j++) {
                    printf("  ");
                }
            for (j = 1; j <= linhas; j++) {
                if (i == 1 || i == linhas || j == 1 || j == linhas) {
                        printf("* ");
                } 
                else{
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;

        case 4:
    // desenha o losango usando os asteriscos
    for (i = 1; i <= linhas/2 + 1; i++) {
        for (j = 1; j <= linhas - i; j++) {
        printf(" ");
        }
        for (j = 1; j <= i*2-1; j++) {
            if (j == 1 || j == i*2-1) {
            printf("*");
            } else {
            printf(" ");
            }
        }
        printf("\n");
    }
    for (i = linhas/2; i >= 1; i--) {
        for (j = 1; j <= linhas - i; j++) {
            printf(" ");
        }


        for (j = 1; j <= i*2-1; j++) {
            if (j == 1 || j == i*2-1) {
            printf("*");
            } 
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    break;




    }




return 0;
}
