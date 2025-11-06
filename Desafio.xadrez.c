#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
     if (casas <= 0) return;         // Caso base da recursão
    printf("Direita\n");             // Move uma casa para a direita
    moverTorre(casas - 1);           // Chamada recursiva
}

// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
     if (casas <= 0) return;
    printf("Esquerda\n");            // Move uma casa para a esquerda
    moverRainha(casas - 1);
}

// Função recursiva para o movimento do Bispo com loops aninhados
void moverBispo(int casasVertical, int casasHorizontal) {
     if (casasVertical <= 0) return;
     for (int h = 0; h < casasHorizontal; h++) {  // Loop horizontal
    printf("Cima, Direita\n");               // Cada casa na diagonal
    }
    moverBispo(casasVertical - 1, casasHorizontal); // Chamada recursiva vertical
}

int main() {
    // Quantidade de casas
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    int cavaloCima = 2;      // Cavalo sobe 2 casas
    int cavaloDireita = 1;   // Cavalo vai 1 casa para a direita

    // ---------------------------
    // Torre
    // ---------------------------
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);
    printf("\n");

    // ---------------------------
    // Bispo
    // ---------------------------
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo, 1);  // 1 casa horizontal por cada vertical
    printf("\n");

    // ---------------------------
    // Rainha
    // ---------------------------
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // ---------------------------
    // Cavalo - loops complexos
    // ---------------------------
    printf("Movimento do Cavalo:\n");
     for (int v = 0; v < cavaloCima; v++) {      // Loop vertical
     for (int h = 0; h < cavaloDireita; h++) { // Loop horizontal
    printf("Cima\n");
            if (v == cavaloCima - 1) break;      // Controle do movimento "L"
        }
    }

    // Movimento horizontal do Cavalo
    int c = 0;
     while (c < cavaloDireita) {
    printf("Direita\n");
        c++;
    }

    return 0;
}
