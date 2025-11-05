#include <stdio.h>

int main() {
    int casasTorre = 5;    // Torre se move 5 casas
    int casasBispo = 5;    // Bispo se move 5 casas
    int casasRainha = 8;   // Rainha se move 8 casas

    // Torre - horizontal/vertical
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++)
    printf("Direita\n");
    printf("\n");

    // Bispo - diagonal
    printf("Movimento do Bispo:\n");
    int contadorBispo = 0;
    while (contadorBispo < casasBispo) {
    printf("Cima, Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // Rainha - todas as direções
    printf("Movimento da Rainha:\n");
    int contadorRainha = 0;
    do {
    printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    return 0;
}
