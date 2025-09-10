#include <stdio.h>   // Biblioteca padrão para entrada (scanf) e saída (printf)

int main(){

    printf("Desafio xadrez! - Super Trunfo\n");  // Mensagem de boas-vindas

    // ===== Variáveis da Carta 1 =====
    char estado1;                 // Estado da cidade (A-H)
    char codigo1[4];              // Código da carta (ex: A01)
    char nomeCidade1[100];        // Nome da cidade (pode ter espaços)
    unsigned long int populacao1; // População da cidade
    float area1;                  // Área da cidade em km²
    float pib1;                   // PIB da cidade em bilhões
    int pontosTuristicos1;        // Número de pontos turísticos
    float densidade1;             // Densidade populacional = população / área
    float pibPerCapita1;          // PIB per capita = PIB / população
    float superPoder1;            // Super Poder = soma de atributos + inverso da densidade

    // ===== Variáveis da Carta 2 =====
    char estado2;      // Estado da cidade (A-H)
    char codigo2[4];   // Código da carta (ex: B02)
    char nomeCidade2[100];   // Nome da cidade (pode ter espaços)
    unsigned long int populacao2; // População da cidade
    float area2;      // Área da cidade em km²
    float pib2;      // PIB da cidade em bilhões
    int pontosTuristicos2;    // Número de pontos turísticos
    float densidade2;        // Densidade populacional = população / área
    float pibPerCapita2;     // PIB per capita = PIB / população
    float superPoder2;      // Super Poder = soma de atributos + inverso da densidade

    // ===== Cadastro da Carta 1 =====
    printf("\n=== Cadastro da Carta 1 ===\n");    // Título do cadastro da Carta 1
    printf("Estado (A-H): "); 
    scanf(" %c", &estado1);         // Lê o estado da cidade
    
    printf("Código (ex: A01): "); 
    scanf("%3s", codigo1);       // Lê o código da carta
    
    printf("Nome da Cidade: "); 
    scanf(" %99[^\n]", nomeCidade1);     // Lê o nome da cidade (com espaços)
    
    printf("População: "); 
    scanf("%lu", &populacao1);     // Lê população
    
    printf("Área (km²): "); 
    scanf("%f", &area1);         // Lê área
    
    printf("PIB (bilhões): "); 
    scanf("%f", &pib1);        // Lê PIB em bilhões
    
    printf("Pontos Turísticos: "); 
    scanf("%d", &pontosTuristicos1);      // Lê número de pontos turísticos

    // ===== Cadastro da Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");    // Título do cadastro da Carta 2
    printf("Estado (A-H): "); 
    scanf(" %c", &estado2);         // Lê o estado da Carta 2
    
    printf("Código (ex: B02): "); 
    scanf("%3s", codigo2);         // Lê código da Carta 2
    
    printf("Nome da Cidade: "); 
    scanf(" %99[^\n]", nomeCidade2);     // Lê nome da cidade
    
    printf("População: "); 
    scanf("%lu", &populacao2);      // Lê população
    
    printf("Área (km²): "); 
    scanf("%f", &area2);          // Lê área
    
    printf("PIB (bilhões): "); 
    scanf("%f", &pib2);           // Lê PIB
    
    printf("Pontos Turísticos: "); 
    scanf("%d", &pontosTuristicos2);       // Lê pontos turísticos

    // ===== Cálculos =====
    densidade1 = populacao1 / area1;       // Calcula densidade da Carta 1
    densidade2 = populacao2 / area2;       // Calcula densidade da Carta 2
    pibPerCapita1 = pib1 / populacao1;     // Calcula PIB per capita da Carta 1
    pibPerCapita2 = pib2 / populacao2;     // Calcula PIB per capita da Carta 2
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);  // Super Poder da Carta 1
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);  // Super Poder da Carta 2

    // ===== Mostrar Cartas =====
    printf("\n=== Cartas Cadastradas ===\n");     // Título da seção de exibição

    printf("\nCarta 1:\n"); 
    printf("Estado: %c\n", estado1);     // Mostra o estado da Carta 1
    printf("Código: %s\n", codigo1);    // Mostra o código da Carta 1
    printf("Cidade: %s\n", nomeCidade1);    // Mostra o nome da cidade da Carta 1
    printf("População: %lu\n", populacao1);    // Mostra população
    printf("Área: %.2f km²\n", area1);    // Mostra área
    printf("PIB: %.2f bilhões\n", pib1);   // Mostra PIB
    printf("Pontos Turísticos: %d\n", pontosTuristicos1); // Mostra pontos turísticos
    printf("Densidade: %.2f\n", densidade1);     // Mostra densidade
    printf("PIB per Capita: %.2f\n", pibPerCapita1);  // Mostra PIB per capita
    printf("Super Poder: %.2f\n", superPoder1);   // Mostra Super Poder

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);   // Mostra estado da Carta 2
    printf("Código: %s\n", codigo2);     // Mostra código da Carta 2
    printf("Cidade: %s\n", nomeCidade2);    // Mostra nome da cidade
    printf("População: %lu\n", populacao2);   // Mostra população
    printf("Área: %.2f km²\n", area2);       // Mostra área
    printf("PIB: %.2f bilhões\n", pib2);     // Mostra PIB
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);  // Mostra pontos turísticos
    printf("Densidade: %.2f\n", densidade2);    // Mostra densidade
    printf("PIB per Capita: %.2f\n", pibPerCapita2);  // Mostra PIB per capita
    printf("Super Poder: %.2f\n", superPoder2);   // Mostra Super Poder

    // ===== Comparação de Cartas =====
    printf("\n=== Comparação de Cartas ===\n");    // Título da seção de comparação
    printf("População: %s venceu (%d)\n", populacao1 > populacao2 ? "Carta 1" : "Carta 2", populacao1 > populacao2 ? 1 : 0); // Compara população
    printf("Área: %s venceu (%d)\n", area1 > area2 ? "Carta 1" : "Carta 2", area1 > area2 ? 1 : 0);   // Compara área
    printf("PIB: %s venceu (%d)\n", pib1 > pib2 ? "Carta 1" : "Carta 2", pib1 > pib2 ? 1 : 0);   // Compara PIB
    printf("Pontos Turísticos: %s venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2 ? "Carta 1" : "Carta 2", pontosTuristicos1 > pontosTuristicos2 ? 1 : 0);   // Compara pontos turísticos
    printf("Densidade Populacional: %s venceu (%d)\n", densidade1 < densidade2 ? "Carta 1" : "Carta 2", densidade1 < densidade2 ? 1 : 0);   // Menor densidade vence
    printf("PIB per Capita: %s venceu (%d)\n", pibPerCapita1 > pibPerCapita2 ? "Carta 1" : "Carta 2", pibPerCapita1 > pibPerCapita2 ? 1 : 0);   // Compara PIB per capita
    printf("Super Poder: %s venceu (%d)\n", superPoder1 > superPoder2 ? "Carta 1" : "Carta 2", superPoder1 > superPoder2 ? 1 : 0);   // Compara Super Poder

    return 0 ; // Finaliza o programa
    }
