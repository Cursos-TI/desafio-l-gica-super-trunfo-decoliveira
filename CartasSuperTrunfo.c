#include <stdio.h>

// ==== FUNÇÃO DE ATRIBUIÇÃO DOS VALORES ====
float getValor(
    int opcao, int carta,
    unsigned long int populacao1, unsigned long int populacao2,
    float area1, float area2,
    float pib1, float pib2,
    int pontosturisticos1, int pontosturisticos2,
    float densidadepopulacional1, float densidadepopulacional2,
    float pibpercapita1, float pibpercapita2
) {
    switch (opcao) {
        case 1: return carta == 1 ? populacao1 : populacao2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? pib1 : pib2;
        case 4: return carta == 1 ? pontosturisticos1 : pontosturisticos2;
        case 5: return carta == 1 ? densidadepopulacional1 : densidadepopulacional2;
        case 6: return carta == 1 ? pibpercapita1 : pibpercapita2;
        default: return 0;
    }
}

int main() {
    char estado1, estado2;
    char numero1[4], numero2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosturisticos1, pontosturisticos2;
    float densidadepopulacional1, densidadepopulacional2;
    float pibpercapita1, pibpercapita2;
    int opcao1, opcao2;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    // ENTRADAS - CARTA 1
    printf("\nCARTA 1\n");
    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o número da carta (1-4): ");
    scanf("%s", numero1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosturisticos1);

    // ENTRADAS - CARTA 2
    printf("\nCARTA 2\n");
    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o número da carta (1-4): ");
    scanf("%s", numero2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosturisticos2);

    // CÁLCULOS DERIVADOS
    densidadepopulacional1 = (float) populacao1 / area1;
    densidadepopulacional2 = (float) populacao2 / area2;
    pibpercapita1 = (pib1 * 1000000000) / populacao1;
    pibpercapita2 = (pib2 * 1000000000) / populacao2;

    // MENU DE ESCOLHA 1
    printf("\n--- MENU DE COMPARAÇÃO ---\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // MENU DE ESCOLHA 2 (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i == opcao1) continue;
        switch (i) {
            case 1: 
            printf("1 - População\n"); 
                break;
            case 2: 
            printf("2 - Área\n"); 
                break;
            case 3: 
            printf("3 - PIB\n"); 
                break;
            case 4: 
            printf("4 - Pontos Turísticos\n"); 
                break;
            case 5: 
            printf("5 - Densidade Populacional\n"); 
                break;
            case 6: 
            printf("6 - PIB per Capita\n"); 
                break;
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("Erro: os atributos devem ser diferentes!\n");
        return 0;
    }

    // CAPTURA DOS VALORES ESCOLHIDOS
    valor1_c1 = getValor(opcao1, 1, populacao1, populacao2, area1, area2, pib1, pib2,
                         pontosturisticos1, pontosturisticos2,
                         densidadepopulacional1, densidadepopulacional2,
                         pibpercapita1, pibpercapita2);
    valor1_c2 = getValor(opcao1, 2, populacao1, populacao2, area1, area2, pib1, pib2,
                         pontosturisticos1, pontosturisticos2,
                         densidadepopulacional1, densidadepopulacional2,
                         pibpercapita1, pibpercapita2);
    valor2_c1 = getValor(opcao2, 1, populacao1, populacao2, area1, area2, pib1, pib2,
                         pontosturisticos1, pontosturisticos2,
                         densidadepopulacional1, densidadepopulacional2,
                         pibpercapita1, pibpercapita2);
    valor2_c2 = getValor(opcao2, 2, populacao1, populacao2, area1, area2, pib1, pib2,
                         pontosturisticos1, pontosturisticos2,
                         densidadepopulacional1, densidadepopulacional2,
                         pibpercapita1, pibpercapita2);

    // COMPARAÇÕES E SOMAS
    float pontos1 = 0, pontos2 = 0;

    // Comparação 1
    if (opcao1 == 5) { // Densidade: menor é melhor
        pontos1 = valor1_c1 < valor1_c2 ? 1 : 0;
        pontos2 = valor1_c2 < valor1_c1 ? 1 : 0;
    } else {
        pontos1 = valor1_c1 > valor1_c2 ? 1 : 0;
        pontos2 = valor1_c2 > valor1_c1 ? 1 : 0;
    }

    // Comparação 2
    if (opcao2 == 5) {
        pontos1 += valor2_c1 < valor2_c2 ? 1 : 0;
        pontos2 += valor2_c2 < valor2_c1 ? 1 : 0;
    } else {
        pontos1 += valor2_c1 > valor2_c2 ? 1 : 0;
        pontos2 += valor2_c2 > valor2_c1 ? 1 : 0;
    }

    // SOMA DOS VALORES TOTAIS
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    // EXIBIÇÃO DOS RESULTADOS
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Carta 1: %s\nCarta 2: %s\n\n", cidade1, cidade2);

    printf("Atributo 1: ");
    switch (opcao1) {
        case 1: 
        printf("População"); 
            break;
        case 2: 
        printf("Área"); 
            break;
        case 3: 
        printf("PIB"); 
            break;
        case 4: 
        printf("Pontos Turísticos"); 
            break;
        case 5: 
        printf("Densidade Populacional"); 
            break;
        case 6: 
        printf("PIB per Capita"); 
            break;
    }
    printf("\n  %s: %.2f | %s: %.2f\n\n", cidade1, valor1_c1, cidade2, valor1_c2);

    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: 
        printf("População"); 
            break;
        case 2: 
        printf("Área"); 
            break;
        case 3: 
        printf("PIB"); 
            break;
        case 4: 
        printf("Pontos Turísticos"); 
            break;
        case 5: 
        printf("Densidade Populacional"); 
            break;
        case 6: 
        printf("PIB per Capita"); 
            break;
    }
    printf("\n  %s: %.2f | %s: %.2f\n\n", cidade1, valor2_c1, cidade2, valor2_c2);

    printf("Soma total dos atributos:\n");
    printf("  %s: %.2f\n  %s: %.2f\n\n", cidade1, soma_c1, cidade2, soma_c2);

    // DECISÃO FINAL
    if (soma_c1 > soma_c2)
        printf("🏆 Vencedora: %s!\n", cidade1);
    else if (soma_c2 > soma_c1)
        printf("🏆 Vencedora: %s!\n", cidade2);
    else
        printf("⚖️ Empate!\n");

    return 0;
}
