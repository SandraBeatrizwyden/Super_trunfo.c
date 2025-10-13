#include <stdio.h>

int main() {
    // Cartas pré-definidas: Brasil e Canadá
    // Dados do Brasil
    char nomePais1[] = "Brasil";
    unsigned long populacao1 = 213000000;     // população
    float area1 = 8515767.0;                   // km²
    float pib1 = 1444.7;                       // PIB em bilhões USD
    int pontosTuristicos1 = 20;

    // Dados do Canadá5
    char nomePais2[] = "Canadá";
    unsigned long populacao2 = 38000000;
    float area2 = 9984670.0;
    float pib2 = 1643.4;
    int pontosTuristicos2 = 18;

    // Calculando densidade demográfica = população / área para cada país
    float densidadeDemografica1 = populacao1 / area1; // menor vence
    float densidadeDemografica2 = populacao2 / area2;

    int atributo1, atributo2;  // Atributos escolhidos pelo jogador

    // Menu para escolher o PRIMEIRO atributo
    printf("País 1: %s\n", nomePais1);
    printf("=== Escolha o PRIMEIRO atributo para comparação ===\n");
    printf("1 - População\n");              // opção 1
    printf("2 - Área\n");                    // opção 2
    printf("3 - PIB\n");                     // opção 3
    printf("4 - Pontos Turísticos\n");      // opção 4
    printf("5 - Densidade Demográfica\n");  // opção 5, incluída a densidade
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Por favor escolha um número de 1 a 5.\n");
        return 1;
    }

    // Menu para escolher o SEGUNDO atributo (dinâmico, não permite repetir o primeiro)
    printf("\nPaís 2: %s\n", nomePais2);
    printf("=== Escolha o SEGUNDO atributo (diferente do primeiro) ===\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida! Escolha um atributo diferente do primeiro.\n");
        return 1;
    }

    // Variáveis para armazenar valores dos atributos escolhidos para cada país
    float val1A, val2A, val1B, val2B;
    char nomeAttr1[30], nomeAttr2[30];

    // Atribuindo valores e nomes do primeiro atributo escolhido
    switch (atributo1) {
        case 1: 
            val1A = populacao1; 
            val2A = populacao2; 
            snprintf(nomeAttr1, sizeof(nomeAttr1), "População"); 
            break;
        case 2: 
            val1A = area1; 
            val2A = area2; 
            snprintf(nomeAttr1, sizeof(nomeAttr1), "Área"); 
            break;
        case 3: 
            val1A = pib1; 
            val2A = pib2; 
            snprintf(nomeAttr1, sizeof(nomeAttr1), "PIB"); 
            break;
        case 4: 
            val1A = pontosTuristicos1; 
            val2A = pontosTuristicos2; 
            snprintf(nomeAttr1, sizeof(nomeAttr1), "Pontos Turísticos"); 
            break;
        case 5: 
            val1A = densidadeDemografica1; 
            val2A = densidadeDemografica2; 
            snprintf(nomeAttr1, sizeof(nomeAttr1), "Densidade Demográfica"); 
            break;
    }

    // Atribuindo valores e nomes do segundo atributo escolhido
    switch (atributo2) {
        case 1: 
            val1B = populacao1; 
            val2B = populacao2; 
            snprintf(nomeAttr2, sizeof(nomeAttr2), "População"); 
            break;
        case 2: 
            val1B = area1; 
            val2B = area2; 
            snprintf(nomeAttr2, sizeof(nomeAttr2), "Área"); 
            break;
        case 3: 
            val1B = pib1; 
            val2B = pib2; 
            snprintf(nomeAttr2, sizeof(nomeAttr2), "PIB"); 
            break;
        case 4: 
            val1B = pontosTuristicos1; 
            val2B = pontosTuristicos2; 
            snprintf(nomeAttr2, sizeof(nomeAttr2), "Pontos Turísticos"); 
            break;
        case 5: 
            val1B = densidadeDemografica1; 
            val2B = densidadeDemografica2; 
            snprintf(nomeAttr2, sizeof(nomeAttr2), "Densidade Demográfica"); 
            break;
    }

    // Contadores de pontos para cada país (quem ganhar cada atributo recebe 1 ponto)
    int pontos1 = 0, pontos2 = 0;

    // Comparar primeiro atributo
    if (atributo1 == 5) {  // Se for densidade demográfica, menor vence
        pontos1 += (val1A < val2A) ? 1 : 0;
        pontos2 += (val2A < val1A) ? 1 : 0;
    } else {               // Nos outros, maior vence
        pontos1 += (val1A > val2A) ? 1 : 0;
        pontos2 += (val2A > val1A) ? 1 : 0;
    }

    // Comparar segundo atributo
    if (atributo2 == 5) {  // Densidade demográfica: menor vence
        pontos1 += (val1B < val2B) ? 1 : 0;
        pontos2 += (val2B < val1B) ? 1 : 0;
    } else {               // Outros: maior vence
        pontos1 += (val1B > val2B) ? 1 : 0;
        pontos2 += (val2B > val1B) ? 1 : 0;
    }

    // Soma dos valores dos dois atributos para desempate
    float soma1 = val1A + val1B;
    float soma2 = val2A + val2B;

    // Exibir resultados de forma clara e organizada
    printf("\n=== Resultado da Comparação ===\n");
    printf("%s vs %s\n\n", nomePais1, nomePais2);
    printf("%s: %.2f vs %.2f\n", nomeAttr1, val1A, val2A);
    printf("%s: %.2f vs %.2f\n", nomeAttr2, val1B, val2B);
    printf("Soma dos atributos - %s: %.2f | %s: %.2f\n", nomePais1, soma1, nomePais2, soma2);

    // Decidir vencedor
    if (pontos1 > pontos2) {
        printf("Resultado final: %s venceu!\n", nomePais1);
    } else if (pontos2 > pontos1) {
        printf("Resultado final: %s venceu!\n", nomePais2);
    } else {  // Empate nos pontos, desempate pela soma
        if (soma1 > soma2)
            printf("Resultado final: %s venceu pela soma dos atributos!\n", nomePais1);
        else if (soma2 > soma1)
            printf("Resultado final: %s venceu pela soma dos atributos!\n", nomePais2);
        else
            printf("Resultado final: Empate!\n");
    }

    return 0;
}