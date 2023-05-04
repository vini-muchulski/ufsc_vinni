#include <stdio.h>

int main() {
    int linhas, i, j;
    int opcao;

    // Recebe o numero de linhas da forma
    printf("Digite o numero de linhas da forma: ");
    scanf("%d", &linhas);


    printf("\n 1 - quadrado\n 2 - triangulo retangulo\n 3 - paralelogramo\n 4 - losango\n");
    
     // Pede a escolha  da forma geométrica a ser desenhada
    printf("Digite a forma geometrica a ser desenhada: ");
    scanf(" %d", &opcao);

    switch (opcao) {
        // Desenha o quadrado emitindo asteriscos durante cada iteração da primeira linha, apos isso ele trabalha com as excecoes para 
        // Ver se deve emitir pontos no contorno da figura
        case 1:
            for (i = 1; i <= linhas; i++) {
                for (j = 1; j <= linhas; j++) {
                    if (i == 1 || i == linhas || j == 1 || j == linhas) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;

        case 2:
        // Desenha um triângulo retângulo usando asteriscos seguindo o mesmo raciocinio
            for (i = 1; i <= linhas; i++) {
                for (j = 1; j <= i; j++) {
                    if (j == 1 || j == i || i == linhas) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;

        case 3:
         // Desenha um paralelogramo usando asteriscos
            for (i = 1; i <= linhas; i++) {
                for (j = 1; j <= linhas - i; j++) {
                    printf("  ");
                }
                for (j = 1; j <= linhas; j++) {
                    if (i == 1 || i == linhas || j == 1 || j == linhas) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;

        case 4:
        // Desenha o losango usando os asteriscos
            for (i = 1; i <= linhas; i++) {
                for (j = 1; j <= linhas - i; j++) {
                    printf(" ");
                }
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            for (i = linhas-1; i >= 1; i--) {
                for (j = 1; j <= linhas - i; j++) {
                    printf(" ");
                }
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        default:
            printf("Forma geométrica inválida.\n");
            break;
    }

    return 0;
}
