#include <stdio.h> // (Biblioteca padrão para entrada e saída)

int main (){ // (Função principal do programa)

// Variáveis da carta 1 
char estado1; // (Guarda a letra do estado 'A-H')
char codigo1[4]; // (Código da carta(ex:A01) 3 caracteres + '0'no fim)
char nomeCidade1[100]; // (Nome da cidade - uma palavra)
int populacao1; // (População da cidade)
float area1; // (Área da cidade - em km²)
float pib1; // (Pib da cidade em bilhões de reais)
int pontosTuristicos1; // (Número de pontos turísticos)

// Variáveis da carta 2
char estado2; // (O processo da carta 1 é o mesmo da carta 2)
char codigo2[4];
char nomeCidade2[100];
int populacao2;
float area2;
float pib2;
int pontosTuristicos2;

// Carta 1
printf("=== Cadastro da Carta 1 ===\n");
printf("Digite a letra do Estado (A-H): ");
scanf(" %c", &estado1); // (Lê o estado, o espaço antes do '%c' evita erro na leitura)

printf("Digite o Código da Carta (ex: A01): ");
scanf("%s", codigo1); // ('%s' Lê o código como uma palavra ex:A01)

printf("Digite o Nome da Cidade: ");
scanf("%s", nomeCidade1); // (Lê o nome da cidade - uma palavra)

printf("Digite a População da cidade: ");
scanf("%d", &populacao1); // (Lê a população - inteiro)

printf("Digite a Área da cidade (em km²): ");
scanf("%f", &area1); // (Lê o tamanho da área - 2 casas decimais )

printf("Digite o PIB da cidade (em bilhões de reais): ");
scanf("%f", &pib1); // (Lê o pib - 2 casa decimais)

printf("Digite o Número de Pontos Turísticos: ");
scanf("%d", &pontosTuristicos1); // (Lê o número de pontos turísticos - inteiros)

// Carta 2
printf("\n=== Cadastro da Carta 2 ===\n");
printf("Digite a letra do Estado (A-H): ");
scanf(" %c", &estado2); // (O processo da carta 1 é o mesmo da carta 2)

printf("Digite o Código da Carta (ex: B02): ");
scanf("%s", codigo2);

printf("Digite o Nome da Cidade: ");
scanf("%s", nomeCidade2);

printf("Digite a População da cidade: ");
scanf("%d", &populacao2);

printf("Digite a Área da cidade (em km²): ");
scanf("%f", &area2);

printf("Digite o PIB da cidade (em bilhões de reais): ");
scanf("%f", &pib2);

printf("Digite o Número de Pontos Turísticos: ");
scanf("%d", &pontosTuristicos2);

// Exibir cartas
printf("\n=== Cartas Cadastradas ===\n");

printf("\nCarta 1:\n");
printf("Estado: %c\n", estado1); // (Mostra a letra do estado)
printf("Código: %s\n", codigo1); // (Mostra o código)
printf("Nome da Cidade: %s\n", nomeCidade1); // (Mostra o nome da cidade)
printf("População: %d\n", populacao1); // (Mostra a população)
printf("Área: %.2f km²\n", area1); // (Mostra a área com 2 casas decimais)
printf("PIB: %.2f bilhões de reais\n", pib1); // (Mostra o PIB com 2 casas decimais)
printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1); // (Mostra os pontos turísticos)

printf("\nCarta 2:\n");
printf("Estado: %c\n", estado2); // (O processo da carta 1 é o mesmo da carta 2)
printf("Código: %s\n", codigo2);
printf("Nome da Cidade: %s\n", nomeCidade2);
printf("População: %d\n", populacao2);
printf("Área: %.2f km²\n", area2);
printf("PIB: %.2f bilhões de reais\n", pib2);
printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

return 0; // (Finaliza o código)
}