#include <stdio.h>

#define TAM 10        // tamanho do tabuleiro 10x10
#define NAV_SIZE 3    // tamanho fixo dos navios
#define HSIZE 5       // tamanho das matrizes de habilidade (5x5)
#define NAV 3         // valor que representa navio
#define HABIL 5       // valor que representa área de habilidade

int main() {
    int tab[TAM][TAM] = {0};   // tabuleiro inicial com 0 = água  // tabuleiro vazio

    // ---------------------------
    // Coordenadas dos 4 navios (definidas no código)
    // ---------------------------
    // nav1 horizontal começa em (2,1)
    int n1_l = 2, n1_c = 1;    // navio 1 horizontal
    // nav2 vertical começa em (5,7)
    int n2_l = 5, n2_c = 7;    // navio 2 vertical
    // n3 diagonal principal / começa em (0,6)
    int n3_l = 0, n3_c = 6;    // navio 3 diagonal
    // n4 diagonal secundária / começa em (6,3)
    int n4_l = 6, n4_c = 3;    // navio 4 diagonal 

    // ---------------------------
    // Validação: garantir limites e não sobreposição
    // ---------------------------
    // valida nav1 horizontal
    for (int i = 0; i < NAV_SIZE; i++) {
        int c = n1_c + i;
        if (n1_l < 0 || n1_l >= TAM || c < 0 || c >= TAM) {
            printf("Erro: navio 1 fora dos limites.\n"); return 1;
        }
        if (tab[n1_l][c] == NAV) { printf("Erro: sobreposicao navio 1.\n"); return 1; }
    }
    // valida nav2 vertical
    for (int i = 0; i < NAV_SIZE; i++) {
        int l = n2_l + i;
        if (l < 0 || l >= TAM || n2_c < 0 || n2_c >= TAM) {
            printf("Erro: navio 2 fora dos limites.\n"); return 1;
        }
        if (tab[l][n2_c] == NAV) { printf("Erro: sobreposicao navio 2.\n"); return 1; }
    }
    // valida nav3 diagonal ↘
    for (int i = 0; i < NAV_SIZE; i++) {
        int l = n3_l + i;
        int c = n3_c + i;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            printf("Erro: navio 3 fora dos limites.\n"); return 1;
        }
        if (tab[l][c] == NAV) { printf("Erro: sobreposicao navio 3.\n"); return 1; }
    }
    // valida nav4 diagonal ↙
    for (int i = 0; i < NAV_SIZE; i++) {
        int l = n4_l + i;
        int c = n4_c - i;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            printf("Erro: navio 4 fora dos limites.\n"); return 1;
        }
        if (tab[l][c] == NAV) { printf("Erro: sobreposicao navio 4.\n"); return 1; }
    }

    // ---------------------------
    // Posiciona os 4 navios no tabuleiro
    // ---------------------------
    for (int i = 0; i < NAV_SIZE; i++) tab[n1_l][n1_c + i] = NAV;        // coloca nav1
    for (int i = 0; i < NAV_SIZE; i++) tab[n2_l + i][n2_c] = NAV;        // coloca nav2
    for (int i = 0; i < NAV_SIZE; i++) tab[n3_l + i][n3_c + i] = NAV;    // coloca nav3
    for (int i = 0; i < NAV_SIZE; i++) tab[n4_l + i][n4_c - i] = NAV;    // coloca nav4

    // ---------------------------
    // Construção dinâmica das matrizes de habilidade (5x5)
    // ---------------------------
    int meio = HSIZE / 2;
    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octa[HSIZE][HSIZE];

    // cone: ponto em cima que vai abrindo pra baixo  // forma de cone
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (i <= meio) {
                int largura = i;                       // quanto maior i, mais largo
                if (j >= meio - largura && j <= meio + largura) cone[i][j] = 1;
                else cone[i][j] = 0;
            } else cone[i][j] = 0;
        }
    }

    // cruz: linha e coluna central  // forma de cruz
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (i == meio || j == meio) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }

    // octaedro (losango) usando distancia de Manhattan <= 2  // forma de losango
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            int dx = i - meio; if (dx < 0) dx = -dx;
            int dy = j - meio; if (dy < 0) dy = -dy;
            if (dx + dy <= 2) octa[i][j] = 1;
            else octa[i][j] = 0;
        }
    }

    // ---------------------------
    // Pontos de origem (centro) das habilidades no tabuleiro
    // ---------------------------
    int origemConeL = 1, origemConeC = 2;   // topo do cone perto dos navios
    int origemCruzL = 4, origemCruzC = 5;   // cruz no meio
    int origemOctL  = 7, origemOctC  = 6;   // octaedro mais abaixo

    // ---------------------------
    // Sobrepor cada habilidade ao tabuleiro (sem sobrescrever navio)
    // ---------------------------
    // sobrepor cone
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (cone[i][j] == 1) {
                int tl = origemConeL + (i - meio);
                int tc = origemConeC + (j - meio);
                if (tl >= 0 && tl < TAM && tc >= 0 && tc < TAM) {
                    if (tab[tl][tc] == 0) tab[tl][tc] = HABIL;   // marca só água
                }
            }
        }
    }

    // sobrepor cruz
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (cruz[i][j] == 1) {
                int tl = origemCruzL + (i - meio);
                int tc = origemCruzC + (j - meio);
                if (tl >= 0 && tl < TAM && tc >= 0 && tc < TAM) {
                    if (tab[tl][tc] == 0) tab[tl][tc] = HABIL;   // marca só água)
                }
            }
        }
    }

    // sobrepor octaedro
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (octa[i][j] == 1) {
                int tl = origemOctL + (i - meio);
                int tc = origemOctC + (j - meio);
                if (tl >= 0 && tl < TAM && tc >= 0 && tc < TAM) {
                    if (tab[tl][tc] == 0) tab[tl][tc] = HABIL;   // marca só água
                }
            }
        }
    }

    // ---------------------------
    // Exibir o tabuleiro final
    // ---------------------------
    printf("\nTabuleiro final (0=agua, 3=navio, 5=habilidade)\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);    // (eu: imprime linha por linha)
        }
        printf("\n");
    }

    return 0;   // (eu: fim do programa)
}
