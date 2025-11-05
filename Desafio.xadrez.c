#include <stdio.h>

int main() {
    int casasTorre = 5;         // Torre se move 5 casas para a direita
    int casasBispo = 5;         // Bispo se move 5 casas na diagonal
    int casasRainha = 8;        // Rainha se move 8 casas para a esquerda
    int casasCavaloBaixo = 2;   // Cavalo se move 2 casas para baixo
    int casasCavaloEsquerda = 1;// Cavalo se move 1 casa para a esquerda

    // Torre
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++)
    printf("Direita\n");
    printf("\n");

    // Bispo
    printf("Movimento do Bispo:\n");
    int contadorBispo = 0;
    while (contadorBispo < casasBispo) {
    printf("Cima, Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // Rainha
    printf("Movimento da Rainha:\n");
    int contadorRainha = 0;
    do {
    printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);
    printf("\n");

    // Cavalo
    printf("Movimento do Cavalo:\n");
    for (int i = 0; i < casasCavaloBaixo; i++)  // Move 2 casas para baixo
    printf("Baixo\n");
    int j = 0;
    while (j < casasCavaloEsquerda) {           // Move 1 casa para a esquerda
    printf("Esquerda\n");
        j++;
    }

    return 0;
}
